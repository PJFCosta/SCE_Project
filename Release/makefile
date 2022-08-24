################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ..\makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\Wire\src\subdir.mk
-include libraries\ServoESP32-master\subdir.mk
-include libraries\SPI\src\subdir.mk
-include libraries\I2C_Temperature_Sensors_derived_from_the_LM75-1.0.3\subdir.mk
-include libraries\Adafruit_VEML6075_Library\subdir.mk
-include libraries\Adafruit_SSD1306\subdir.mk
-include libraries\Adafruit_GFX_Library\subdir.mk
-include libraries\Adafruit_BusIO\subdir.mk
-include core\core\libb64\subdir.mk
-include core\core\subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ..\makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release\arduino.ar \

ELF += \
SCE_Project.elf \

HEX += \
SCE_Project.hex \


# All Target
all:
	$(MAKE) --no-print-directory pre-build
	$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: SCE_Project

# Tool invocations
SCE_Project: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-size" -A "C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release/SCE_Project.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release\arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-ar" cru     C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release/arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

SCE_Project.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\tools\xtensa-esp32-elf-gcc\1.22.0-97-gc752ad5-5.2.0/bin/xtensa-esp32-elf-gcc" -nostdlib "-LC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/lib" "-LC:\DEV\Sloeber_APP\arduinoPlugin\packages\esp32\hardware\esp32\1.0.6/tools/sdk/ld" -T esp32_out.ld -T esp32.project.ld -T esp32.rom.ld -T esp32.peripherals.ld -T esp32.rom.libgcc.ld -T esp32.rom.spiram_incompatible_fns.ld -u esp_app_desc -u ld_include_panic_highint_hdl -u call_user_start_cpu0 -Wl,--gc-sections -Wl,-static -Wl,--undefined=uxTopUsedPriority  -u __cxa_guard_dummy -u __cxx_fatal_exception   -Wl,--start-group   $(LINK_OBJ)   C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release/arduino.ar  -lgcc -lesp_websocket_client -lwpa2 -ldetection -lesp_https_server -lwps -lhal -lconsole -lpe -lsoc -lsdmmc -lpthread -llog -lesp_http_client -ljson -lmesh -lesp32-camera -lnet80211 -lwpa_supplicant -lc -lmqtt -lcxx -lesp_https_ota -lulp -lefuse -lpp -lmdns -lbt -lwpa -lspiffs -lheap -limage_util -lunity -lrtc -lmbedtls -lface_recognition -lnghttp -ljsmn -lopenssl -lcore -lfatfs -lm -lprotocomm -lsmartconfig -lxtensa-debug-module -ldl -lesp_event -lesp-tls -lfd -lespcoredump -lesp_http_server -lfr -lsmartconfig_ack -lwear_levelling -ltcp_transport -llwip -lphy -lvfs -lcoap -lesp32 -llibsodium -lbootloader_support -ldriver -lcoexist -lasio -lod -lmicro-ecc -lesp_ringbuf -ldetection_cat_face -lapp_update -lespnow -lface_detection -lapp_trace -lnewlib -lbtdm_app -lwifi_provisioning -lfreertos -lfreemodbus -lethernet -lnvs_flash -lspi_flash -lc_nano -lexpat -lfb_gfx -lprotobuf-c -lesp_adc_cal -ltcpip_adapter  -lstdc++  -Wl,--end-group -Wl,-EL -o "C:\Users\pedro\Documents\sloeber-workspace\SCE_Project\Release/SCE_Project.elf"
	@echo 'Finished building: $@'
	@echo ' '

SCE_Project.hex: $(ELF)
	@echo 'Do all objcopy commands'
	${recipe.objcopy.bin.pattern}
	${recipe.objcopy.hex.pattern}
	${recipe.objcopy.partitions.bin.pattern}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

pre-build:
	-${recipe.hooks.prebuild.1.pattern}
	${recipe.hooks.prebuild.2.pattern}
	-@echo ' '

.PHONY: all clean dependents main-build pre-build

-include ..\makefile.targets
