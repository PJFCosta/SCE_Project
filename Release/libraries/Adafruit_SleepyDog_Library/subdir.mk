################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\Users\pedro\OneDrive\ -\ IPLeiria\Documents\Arduino\libraries\Adafruit_SleepyDog_Library\Adafruit_SleepyDog.cpp 

LINK_OBJ += \
.\libraries\Adafruit_SleepyDog_Library\Adafruit_SleepyDog.cpp.o 

CPP_DEPS += \
.\libraries\Adafruit_SleepyDog_Library\Adafruit_SleepyDog.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\Adafruit_SleepyDog_Library\Adafruit_SleepyDog.cpp.o: C:\Users\pedro\OneDrive\ -\ IPLeiria\Documents\Arduino\libraries\Adafruit_SleepyDog_Library\Adafruit_SleepyDog.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-g++" -DESP_PLATFORM "-DMBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\"" -DHAVE_CONFIG_H -DGCC_NOT_5_2_0=0 -DWITH_POSIX "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/config" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/app_trace" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/app_update" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/asio" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/bootloader_support" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/bt" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/coap" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/console" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/driver" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/efuse" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp-tls" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp32" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_adc_cal" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_event" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_http_client" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_http_server" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_https_ota" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_https_server" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_ringbuf" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp_websocket_client" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/espcoredump" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/ethernet" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/expat" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/fatfs" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/freemodbus" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/freertos" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/heap" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/idf_test" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/jsmn" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/json" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/libsodium" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/log" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/lwip" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/mbedtls" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/mdns" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/micro-ecc" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/mqtt" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/newlib" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/nghttp" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/nvs_flash" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/openssl" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/protobuf-c" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/protocomm" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/pthread" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/sdmmc" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/smartconfig_ack" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/soc" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/spi_flash" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/spiffs" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/tcp_transport" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/tcpip_adapter" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/ulp" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/unity" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/vfs" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/wear_levelling" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/wifi_provisioning" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/wpa_supplicant" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/xtensa-debug-module" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp-face" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp32-camera" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/esp-face" "-IC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/include/fb_gfx" -std=gnu++11 -Os -g3 -Wpointer-arith -fexceptions -fstack-protector -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -mlongcalls -nostdlib -w -Wno-error=maybe-uninitialized -Wno-error=unused-function -Wno-error=unused-but-set-variable -Wno-error=unused-variable -Wno-error=deprecated-declarations -Wno-unused-parameter -Wno-unused-but-set-parameter -Wno-missing-field-initializers -Wno-sign-compare -fno-rtti -MMD -c -DF_CPU=240000000L -DARDUINO=10812 -DARDUINO_ESP32_DEV -DARDUINO_ARCH_ESP32 "-DARDUINO_BOARD=\"ESP32_DEV\"" -DARDUINO_VARIANT="esp32"  -DESP32 -DCORE_DEBUG_LEVEL=0    -I"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6\cores\esp32" -I"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6\variants\esp32" -I"C:\Users\pedro\OneDrive - IPLeiria\Documents\Arduino\libraries" -I"C:\Users\pedro\OneDrive - IPLeiria\Documents\Arduino\libraries\Adafruit_GFX_Library" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


