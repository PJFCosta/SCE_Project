#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2022-08-23 22:47:56

#include "Arduino.h"
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

static void IRAM_ATTR vButtonEVENT1(void) ;
static void IRAM_ATTR vButtonEVENT2(void) ;
void setup() ;
void loop() ;
void TaskTemp(void *pvParameters) ;
void TaskVentoinha(void *pvParameters) ;
void TaskHumidade(void *pvParameters) ;
void TaskLED(void *pvParameters) ;
void TaskScreen(void *pvParameters) ;
bool my_vApplicationIdleHook(void) ;

#include "SCE_Project.ino"


#endif
