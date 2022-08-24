/*
 * Projeto de SCE 2021/2022
 * Estufa automatizada com ventoinha e bomba de agua
 * Pedro Costa 2191919
 * Pedro Silva 2191166
 * Professor Luís Conde Bento
 */

//Bibliotecas necessárias ao correto funcionamento deste Projeto
#include "Arduino.h"
#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_task_wdt.h"
#include "esp_freertos_hooks.h"
#include <inttypes.h>
#include <Wire.h>
#include <SPI.h>
#include <Temperature_LM75_Derived.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Servo.h"

//Structs necessárias para passar informações entre as tasks
typedef struct Humidade {
	int humi;
} Humidadestr;

typedef struct Temperatura {
	float tempe;
} Temperaturastr;

typedef struct Templimit {
	int limit = 30;
} Templimitstr;

typedef struct Ecra {
	float temp = -1000;
	int hum = -1000;
	int limit = -1000;
} ToScreenstr;

//Criação de Queues necessárias para ser possivel transmitir as structs
QueueHandle_t xQueueHum;
QueueHandle_t xQueueTemp;
QueueHandle_t xQueueEcra;

//Criação de um Mutex
SemaphoreHandle_t xMutex;

//Criação de Semaphores
SemaphoreHandle_t xCountSemaphoreNeg;
SemaphoreHandle_t xCountSemaphorePos;

//Interrupts
static void IRAM_ATTR vButtonEVENT1(void) {
	static signed portBASE_TYPE xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;

	xSemaphoreGiveFromISR(xCountSemaphoreNeg,
			(signed portBASE_TYPE*)&xHigherPriorityTaskWoken);

	if (xHigherPriorityTaskWoken == pdTRUE) {
		portYIELD_FROM_ISR();
	}

}

static void IRAM_ATTR vButtonEVENT2(void) {
	static signed portBASE_TYPE xHigherPriorityTaskWoken;
	xHigherPriorityTaskWoken = pdFALSE;

	xSemaphoreGiveFromISR(xCountSemaphorePos,
			(signed portBASE_TYPE*)&xHigherPriorityTaskWoken);

	if (xHigherPriorityTaskWoken == pdTRUE) {
		portYIELD_FROM_ISR();
	}

}

//The setup function is called once at startup of the sketch
void setup() {
	Serial.begin(115200);

	// idle Task
	esp_register_freertos_idle_hook (my_vApplicationIdleHook);

	//Tamanho das Queues
	xQueueHum = xQueueCreate(4, sizeof(Humidadestr));
	xQueueTemp = xQueueCreate(4, sizeof(Temperaturastr));
	xQueueEcra = xQueueCreate(10, sizeof(ToScreenstr));

	//Verificação para a criação dos Semaphores, Mutex, Tasks e Interrupts
	if (xQueueHum != NULL && xQueueTemp != NULL && xQueueEcra != NULL) {

		xMutex = xSemaphoreCreateMutex();
		xCountSemaphoreNeg = xSemaphoreCreateBinary();
		xCountSemaphorePos = xSemaphoreCreateBinary();
		//Set loopTask max priority
		vTaskPrioritySet(NULL, configMAX_PRIORITIES - 1);
		if (xMutex != NULL) {
			xTaskCreatePinnedToCore(TaskTemp, "SensorTemperatura", 1024,
					(void*) 3, 2, NULL, 1);
			xTaskCreatePinnedToCore(TaskScreen, "Screen", 10500, (void*) 3, 1,
			NULL, 1);
		}
		if (xCountSemaphoreNeg != NULL && xCountSemaphorePos != NULL) {
			xTaskCreatePinnedToCore(TaskVentoinha, "Ventoinha", 1024, (void*) 3,
					3,
					NULL, 1);
		}
		xTaskCreatePinnedToCore(TaskHumidade, "SensorHumidade", 1024, (void*) 3,
				2, NULL, 1);
		xTaskCreatePinnedToCore(TaskLED, "AtuadorLED", 1024, (void*) 3, 3,
		NULL, 1);

		//Criação dos Interrupts
		attachInterrupt(digitalPinToInterrupt(15), vButtonEVENT1, RISING);
		attachInterrupt(digitalPinToInterrupt(2), vButtonEVENT2, RISING);
		interrupts();

	}

}

// The loop function is called in an endless loop
void loop() {
	vTaskSuspend(NULL);
}

//Tasks para ler o sensor de temperatura e enviar para uma Queue
void TaskTemp(void *pvParameters) {
	TickType_t xLastWakeTime;
	const TickType_t xTicksToWait = 200 / portTICK_PERIOD_MS;
	xLastWakeTime = xTaskGetTickCount();
	Temperaturastr temp;
	ToScreenstr values;
	Generic_LM75 temperature;
	float temp_air = 0;
	//Wire begin nao tras problemas ao ser chamado varias vezes
	Wire.begin();
	for (;;) {
		if (xSemaphoreTake(xMutex, xTicksToWait)) {
			temp_air = temperature.readTemperatureC();
			xSemaphoreGive(xMutex);
		}
		Serial.print("Temperatura: ");
		Serial.println(temp_air);
		temp.tempe = temp_air;
		values.temp = temp_air;
		xQueueSendToBack(xQueueTemp, &temp, 0);
		xQueueSendToBack(xQueueEcra, &values, 0);
		vTaskDelayUntil(&xLastWakeTime, (1000 / portTICK_PERIOD_MS));
	}

}

//Task para ler o valor da temperatura do sensor e comparar com o valor limite para ligar a ventoinha
void TaskVentoinha(void *pvParameters) {
	//Nao tras problemas a escrever defines dentro de funcoes porque sao compilados antes do programa todo
#define LOWLIMIT 0
#define MAXLIMIT 50
#define rele 4
	TickType_t xLastWakeTime;
	char check = 0;
	portBASE_TYPE xVerificarNeg;
	portBASE_TYPE xVerificarPos;
	const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;
	Temperaturastr temp;
	Templimitstr limitecra;
	ToScreenstr values;
	portBASE_TYPE xCheckQueue;
	pinMode(rele, OUTPUT);

	//Loop para botoes e ligar ventoinha
	for (;;) {
		xVerificarNeg = xSemaphoreTake(xCountSemaphoreNeg, xTicksToWait);
		xVerificarPos = xSemaphoreTake(xCountSemaphorePos, xTicksToWait);

		//Verifica se um botao foi precionado e causou uma interrupt
		if (xVerificarNeg == pdPASS || xVerificarPos == pdPASS) {

			//Verifica qual foi o botao e subtrai ou soma 1 ao limite da temperatura
			if (xVerificarNeg == pdPASS && limitecra.limit > LOWLIMIT)
				limitecra.limit--;

			if (xVerificarPos == pdPASS && limitecra.limit < MAXLIMIT)
				limitecra.limit++;

			values.limit = limitecra.limit;
			xQueueSendToBack(xQueueEcra, &values, 0);
		}

		//Verifica se recebeu uma nova temperatura do sensor na queue e comprar com o limite para ligar ou desligar a ventoinha
		xCheckQueue = xQueueReceive(xQueueTemp, &temp, xTicksToWait);
		if (xCheckQueue == pdPASS) {
			if (temp.tempe > (float) limitecra.limit) {
				digitalWrite(rele, HIGH);
			} else {
				digitalWrite(rele, LOW);
			}
		}
		vTaskDelayUntil(&xLastWakeTime, (500 / portTICK_PERIOD_MS));
	}
}

//Task para ler o sensor de humidade e colocar o valor
void TaskHumidade(void *pvParameters) {
#define HW103 33
	TickType_t xLastWakeTime;
	const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;
	xLastWakeTime = xTaskGetTickCount();
	int valve_flag = 0;
	int valve_auto = 1;
	pinMode(HW103, INPUT);
	Humidadestr hum;
	ToScreenstr values;

	//Loop que le o sensor de humidade de 1 segundo em 1 segundo
	for (;;) {
		int soil_hum = map(analogRead(HW103), 4095, 1750, 0, 100);
		if (soil_hum > 100)
			soil_hum = 100;
		Serial.print("Humidade: ");
		Serial.println(soil_hum);
		hum.humi = soil_hum;
		values.hum = soil_hum;
		xQueueSendToBack(xQueueHum, &hum, 0);
		xQueueSendToBack(xQueueEcra, &values, 0);
		vTaskDelayUntil(&xLastWakeTime, (1000 / portTICK_PERIOD_MS));
	}
}

//Task para comparar o valor lido pelo sensor de humidade com um valor predefinido para ativar o LED que simula uma bomba de agua
void TaskLED(void *pvParameters) {
#define led 32
	TickType_t xLastWakeTime;
	const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;
	xLastWakeTime = xTaskGetTickCount();
	pinMode(led, OUTPUT);
	Humidadestr hum;
	portBASE_TYPE xStatusHum;

	//Loop que compara o valor lido pelo sensor de humidade e compara com o valor predefinido para ativar ou desativar o LED
	for (;;) {
		xStatusHum = xQueueReceive(xQueueHum, &hum, 0);
		if (xStatusHum == pdPASS) {
			if (hum.humi > 50) {
				digitalWrite(led, LOW);
			} else {
				digitalWrite(led, HIGH);
			}
		}
		vTaskDelayUntil(&xLastWakeTime, (1000 / portTICK_PERIOD_MS));
	}
}

//Task para receber os valores dos sensores e limite de temperatura e mostra no ecrã
void TaskScreen(void *pvParameters) {

	//Settings necessárias para o ecrã
#define LCD_ADDRESS_1 0x3C
#define LCD_ADDRESS_2 0x3D

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

	TickType_t xLastWakeTime;
	const TickType_t xTicksToWait = 200 / portTICK_PERIOD_MS;
	xLastWakeTime = xTaskGetTickCount();
	Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

	//novo
	float temperature = 0;
	int humidity = 0;
	int limite = 30;

	ToScreenstr screenValues;

	UBaseType_t xTaskDetails;

	portBASE_TYPE xStatusEcra;

	Wire.begin();

	//Verifica se ocorreu um erro a iniciar o ecrã e mostra uma mensagem no serial monitor
	if (!display.begin(SSD1306_SWITCHCAPVCC, LCD_ADDRESS_1)) {
		Serial.println(F("Error: -------- SSD1306 allocation failed -------"));
		for (;;)
			;
	}

	//Inicia o ecrã
	if (xSemaphoreTake(xMutex, portMAX_DELAY)) {
		display.display();
		vTaskDelayUntil(&xLastWakeTime, (2000 / portTICK_PERIOD_MS));
		display.clearDisplay();
		display.setTextColor(WHITE);
		xSemaphoreGive(xMutex);
	}

	//Loop que mostra os valores no ecrã e atualiza-os
	for (;;) {

		xStatusEcra = xQueueReceive(xQueueEcra, &screenValues, xTicksToWait);

		//Verifica se recebeu algum valor, compara-o com um valor impossivel para colocar nas variaveis que vao ser apresentadas
		if (xStatusEcra == pdPASS) {


			if (screenValues.hum != -1000) {
				humidity = screenValues.hum;
			}
			if (screenValues.temp != -1000) {
				temperature = screenValues.temp;
			}
			if (screenValues.limit != -1000) {
				limite = screenValues.limit;
			}

			if (xSemaphoreTake(xMutex, xTicksToWait)) {
				//vTaskPrioritySet(NULL, 10);
				display.clearDisplay();
				display.setTextSize(1);
				display.setCursor(0, 0);
				display.print("Temperatura: ");
				display.print(String(temperature));
				display.cp437(true);
				display.write(167);
				display.println("C");
				display.print("Humidade: ");
				display.print(humidity);
				display.println("%");
				display.print("Limite: ");
				display.print(limite);
				display.cp437(true);
				display.write(167);
				display.println("C");
				display.display();
//				xTaskDetails = uxTaskGetStackHighWaterMark(NULL);
//				Serial.println(xTaskDetails);
				//vTaskPrioritySet(NULL, 1);
				xSemaphoreGive(xMutex);

			}
		}

		vTaskDelayUntil(&xLastWakeTime, (200 / portTICK_PERIOD_MS));
	}

}

bool my_vApplicationIdleHook(void) {
	return true;
}

