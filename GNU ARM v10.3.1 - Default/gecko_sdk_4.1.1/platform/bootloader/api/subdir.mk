################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Nick\ Merola/SimplicityStudio/SDKs/gecko_sdk/platform/bootloader/api/btl_interface.c \
C:/Users/Nick\ Merola/SimplicityStudio/SDKs/gecko_sdk/platform/bootloader/api/btl_interface_storage.c 

OBJS += \
./gecko_sdk_4.1.1/platform/bootloader/api/btl_interface.o \
./gecko_sdk_4.1.1/platform/bootloader/api/btl_interface_storage.o 

C_DEPS += \
./gecko_sdk_4.1.1/platform/bootloader/api/btl_interface.d \
./gecko_sdk_4.1.1/platform/bootloader/api/btl_interface_storage.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.1.1/platform/bootloader/api/btl_interface.o: C:/Users/Nick\ Merola/SimplicityStudio/SDKs/gecko_sdk/platform/bootloader/api/btl_interface.c gecko_sdk_4.1.1/platform/bootloader/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DEFR32MG22C224F512IM40=1' '-DSL_APP_PROPERTIES=1' '-DBOOTLOADER_APPLOADER=1' '-DSL_BOARD_NAME="BRD4182A"' '-DSL_BOARD_REV="B06"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo\config" -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG22/Include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/icm20648/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/imu/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/in_place_ota_dfu" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc/public" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.1/platform/bootloader/api/btl_interface.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

gecko_sdk_4.1.1/platform/bootloader/api/btl_interface_storage.o: C:/Users/Nick\ Merola/SimplicityStudio/SDKs/gecko_sdk/platform/bootloader/api/btl_interface_storage.c gecko_sdk_4.1.1/platform/bootloader/api/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DEFR32MG22C224F512IM40=1' '-DSL_APP_PROPERTIES=1' '-DBOOTLOADER_APPLOADER=1' '-DSL_BOARD_NAME="BRD4182A"' '-DSL_BOARD_REV="B06"' '-DSL_COMPONENT_CATALOG_PRESENT=1' '-DMBEDTLS_CONFIG_FILE=<mbedtls_config.h>' '-DMBEDTLS_PSA_CRYPTO_CONFIG_FILE=<psa_crypto_config.h>' '-DSL_RAIL_LIB_MULTIPROTOCOL_SUPPORT=0' '-DSL_RAIL_UTIL_PA_CONFIG_HEADER=<sl_rail_util_pa_config.h>' '-DSLI_RADIOAES_REQUIRES_MASKING=1' -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo\config" -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/Device/SiliconLabs/EFR32MG22/Include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//app/common/util/app_assert" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//protocol/bluetooth/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/common/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/board/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/bootloader/api" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/CMSIS/Core/Include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/configuration_over_swo/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_cryptoacc_library/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/driver/debug/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/device_init/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/common/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emlib/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/hfxo_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/icm20648/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/imu/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//app/bluetooth/common/in_place_ota_dfu" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/config" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_mbedtls_support/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/include" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/mbedtls/library" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/mpu/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//hardware/driver/mx25_flash_shutdown/inc/sl_mx25_flash_shutdown_usart" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/emdrv/nvm3/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/power_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_psa_driver/inc/public" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/common" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ble" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/ieee802154" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/protocol/zwave" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/chip/efr32/efr32xg2x" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/pa-conversions/efr32xg22" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/radio/rail_lib/plugin/rail_util_pti" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/se_manager/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/silicon_labs/silabs_core/memory_manager" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/common/toolchain/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/system/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/sleeptimer/inc" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//util/third_party/crypto/sl_component/sl_protocol_crypto/src" -I"C:/Users/Nick Merola/SimplicityStudio/SDKs/gecko_sdk//platform/service/udelay/inc" -I"C:\Users\Nick Merola\SimplicityStudio\v5_workspace\BR450_Demo\autogen" -Os -Wall -Wextra -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.1.1/platform/bootloader/api/btl_interface_storage.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


