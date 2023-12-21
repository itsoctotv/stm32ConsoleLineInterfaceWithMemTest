#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit "VARIABLES"-section to suit project requirements.
#        For debug build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug VERBOSE=1
#        For release build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make -C Release VERBOSE=1
#############################################################################################################################
cmake_minimum_required(VERSION 3.20)

# Path conventions
file(REAL_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ROOT_PROJECT_DIR
     BASE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" EXPAND_TILDE)
set(PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE INTERNAL "")
set(STM32FW_DIR "${ROOT_PROJECT_DIR}" CACHE INTERNAL "")

###################### CONSTANTS ######################################
set (PROJECT_TYPE_EXECUTABLE          "exe")
set (PROJECT_TYPE_STATIC_LIBRARY      "static-lib")
set (MISA_STATES_ARM                  "-marm")
set (MISA_STATES_THUMB                "-mthumb")
set (MEND_LITTLE                      "-mlittle-endian")
set (MEND_BIG                         "-mbig-endian")
set (MCPU_CORTEX_M0                   "-mcpu=cortex-m0")
set (MCPU_CORTEX_M0PLUS               "-mcpu=cortex-m0plus")
set (MCPU_CORTEX_M3                   "-mcpu=cortex-m3")
set (MCPU_CORTEX_M4                   "-mcpu=cortex-m4")
set (MCPU_CORTEX_M7                   "-mcpu=cortex-m7")
set (MCPU_CORTEX_M33                  "-mcpu=cortex-m33")
set (MFPU_FPV4_SP_D16                 "-mfpu=fpv4-sp-d16")
set (MFPU_FPV5_SP_D16                 "-mfpu=fpv5-sp-d16")
set (MFPU_FPV5_D16                    "-mfpu=fpv5-d16")
set (RUNTIME_LIBRARY_REDUCED_C        "--specs=nano.specs")
set (RUNTIME_LIBRARY_STD_C            "")
set (RUNTIME_LIBRARY_SYSCALLS_MINIMAL "--specs=nosys.specs")
set (RUNTIME_LIBRARY_SYSCALLS_NONE    "")
set (MFLOAT_ABI_SOFTWARE              "-mfloat-abi=soft")
set (MFLOAT_ABI_HARDWARE              "-mfloat-abi=hard")
set (MFLOAT_ABI_MIX                   "-mfloat-abi=softfp")
#######################################################################

###################### VARIABLES ######################################
set (PROJECT_NAME             "STM32F769I-DISCO_TouchGFX")
set (PROJECT_TYPE             "${PROJECT_TYPE_EXECUTABLE}")
set (LINKER_SCRIPT            "${PROJECT_DIR}/STM32F769NIHx_FLASH.ld")
set (MISA                     "${MISA_STATES_THUMB}")
set (MEND                     "${MEND_LITTLE}")
set (MCPU                     "${MCPU_CORTEX_M7}")
set (MFPU                     "${MFPU_FPV5_D16}")
set (MFLOAT_ABI               "${MFLOAT_ABI_HARDWARE}")
set (RUNTIME_CSTD             "-std=gnu11")
set (RUNTIME_CFLAGS           "-ffunction-sections -fstack-usage -fcyclomatic-complexity")
set (RUNTIME_CXXSTD           "-std=gnu++14")
set (RUNTIME_CXXFLAGS         "${RUNTIME_CFLAGS} -fno-exceptions -fno-rtti -fno-use-cxa-atexit")
set (RUNTIME_WARNINGS         "-Wall -Wno-main -Wno-implicit-fallthrough -Wno-strict-aliasing -Werror")
set (RUNTIME_ASFLAGS          "-x assembler-with-cpp")
set (RUNTIME_LIBRARY          "${RUNTIME_LIBRARY_REDUCED_C}")
set (RUNTIME_LIBRARY_SYSCALLS "${RUNTIME_LIBRARY_SYSCALLS_MINIMAL}")
set (RUNTIME_LDFLAGS          "-Wl,-Map=test.map -Wl,--gc-sections -static -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group")


set(USBHLIB_DIR "${STM32FW_DIR}/Middlewares/ST/STM32_USB_Host_Library" CACHE INTERNAL "")
set(USBH_CORE_DIR "${USBHLIB_DIR}/Core" CACHE INTERNAL "")
set(USBH_MSC_DIR "${USBHLIB_DIR}/Class/MSC" CACHE INTERNAL "")
set(FATFS_DIR "${STM32FW_DIR}/Middlewares/Third_Party/FatFs" CACHE INTERNAL "")
set(UTILJPEG_DIR "${STM32FW_DIR}/Utilities/JPEG" CACHE INTERNAL "")
set(LIBJPEG_DIR "${STM32FW_DIR}/Middlewares/Third_Party/LibJPEG" CACHE INTERNAL "")
set(TOUCHGFX_DIR "${STM32FW_DIR}/Middlewares/ST/TouchGFX/touchgfx" CACHE INTERNAL "")
set(TGFX_FW_DIR "${TOUCHGFX_DIR}/framework" CACHE INTERNAL "")
set(TGFX_OS_DIR "${TOUCHGFX_DIR}/os" CACHE INTERNAL "")
set(FREERTOS_DIR "${STM32FW_DIR}/Middlewares/Third_Party/FreeRTOS/Source" CACHE INTERNAL "")

set(PRJ_GUI_DIR "${PROJECT_DIR}/Sources/Gui" CACHE INTERNAL "")
set(PRJGUIT_DIR "${PRJ_GUI_DIR}/target" CACHE INTERNAL "")
set(PRJGUIF_DIR "${PRJ_GUI_DIR}/generated/fonts" CACHE INTERNAL "")
set(PRJGUIX_DIR "${PRJ_GUI_DIR}/generated/texts" CACHE INTERNAL "")
set(PRJGUII_DIR "${PRJ_GUI_DIR}/generated/images" CACHE INTERNAL "")
set(PRJGUIM_DIR "${PRJ_GUI_DIR}/gui" CACHE INTERNAL "")

set (PROJECT_SOURCES
	# LIST SOURCE FILES HERE
	#
	# STM32F7 Hardware Abstraction Layer (HAL), incl. Low-Level (LL) drivers
	#
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_can.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cec.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cortex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_crc_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_cryp_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dac_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dcmi_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dfsdm.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma2d.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dma_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_dsi.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_eth.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_exti.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_flash_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hash_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_hcd.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2c_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_i2s.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_irda.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_iwdg.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_jpeg.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_lptim.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_ltdc_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mdios.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_mmc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nand.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_nor.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pcd_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_pwr_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_qspi.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rcc_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rng.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_rtc_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sai_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sd.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sdram.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smartcard_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_smbus.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spdifrx.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_spi_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_sram.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_tim_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_uart_ex.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_usart.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_wwdg.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_adc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_crc.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dac.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma2d.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dma.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_exti.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_fmc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_gpio.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_i2c.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_lptim.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_pwr.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rcc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rng.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_rtc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_spi.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_tim.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usart.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_utils.c
	#
	# STM32F769I-Discovery Board-Support-Package (BSP)
	#
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_audio.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_eeprom.c
#	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_lcd.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_qspi.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sd.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_sdram.c
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery/stm32f769i_discovery_ts.c
	#
	# Common BSP Chip Components driver
	#
	${STM32FW_DIR}/Drivers/BSP/Components/ft6x06/ft6x06.c
	${STM32FW_DIR}/Drivers/BSP/Components/otm8009a/otm8009a.c
	${STM32FW_DIR}/Drivers/BSP/Components/wm8994/wm8994.c
	#
	# STM32 USB Host Library
	#
	${USBH_CORE_DIR}/Src/usbh_core.c
	${USBH_CORE_DIR}/Src/usbh_ctlreq.c
	${USBH_CORE_DIR}/Src/usbh_ioreq.c
	${USBH_CORE_DIR}/Src/usbh_pipes.c
	${USBH_MSC_DIR}/Src/usbh_msc.c
	${USBH_MSC_DIR}/Src/usbh_msc_bot.c
	${USBH_MSC_DIR}/Src/usbh_msc_scsi.c
	#
	# FatFS Core and Optional Components
	#
	${FATFS_DIR}/src/ff.c
#	${FATFS_DIR}/src/ff_gen_drv.c
#	${FATFS_DIR}/src/diskio.c
#	${FATFS_DIR}/src/option/cc932.c
#	${FATFS_DIR}/src/option/cc936.c
#	${FATFS_DIR}/src/option/cc949.c
#	${FATFS_DIR}/src/option/cc950.c
#	${FATFS_DIR}/src/option/ccsbcs.c
	${FATFS_DIR}/src/option/syscall.c
	${FATFS_DIR}/src/option/unicode.c
	#
	# ST JPEG Utilities
	#
	${UTILJPEG_DIR}/jpeg_utils.c
	#
	# LibJPEG Core and Optional Components
	#
#	${LIBJPEG_DIR}/source/cdjpeg.c
#	${LIBJPEG_DIR}/source/cjpeg.c
#	${LIBJPEG_DIR}/source/ckconfig.c
#	${LIBJPEG_DIR}/source/djpeg.c
#	${LIBJPEG_DIR}/source/example.c
	${LIBJPEG_DIR}/source/jaricom.c
#	${LIBJPEG_DIR}/source/jcapimin.c
#	${LIBJPEG_DIR}/source/jcapistd.c
#	${LIBJPEG_DIR}/source/jcarith.c
#	${LIBJPEG_DIR}/source/jccoefct.c
#	${LIBJPEG_DIR}/source/jccolor.c
#	${LIBJPEG_DIR}/source/jcdctmgr.c
#	${LIBJPEG_DIR}/source/jchuff.c
#	${LIBJPEG_DIR}/source/jcinit.c
#	${LIBJPEG_DIR}/source/jcmainct.c
#	${LIBJPEG_DIR}/source/jcmarker.c
#	${LIBJPEG_DIR}/source/jcmaster.c
	${LIBJPEG_DIR}/source/jcomapi.c
#	${LIBJPEG_DIR}/source/jcparam.c
#	${LIBJPEG_DIR}/source/jcprepct.c
#	${LIBJPEG_DIR}/source/jcsample.c
#	${LIBJPEG_DIR}/source/jctrans.c
	${LIBJPEG_DIR}/source/jdapimin.c
	${LIBJPEG_DIR}/source/jdapistd.c
	${LIBJPEG_DIR}/source/jdarith.c
	${LIBJPEG_DIR}/source/jdatadst.c
	${LIBJPEG_DIR}/source/jdatasrc.c
	${LIBJPEG_DIR}/source/jdcoefct.c
	${LIBJPEG_DIR}/source/jdcolor.c
	${LIBJPEG_DIR}/source/jddctmgr.c
	${LIBJPEG_DIR}/source/jdhuff.c
	${LIBJPEG_DIR}/source/jdinput.c
	${LIBJPEG_DIR}/source/jdmainct.c
	${LIBJPEG_DIR}/source/jdmarker.c
	${LIBJPEG_DIR}/source/jdmaster.c
	${LIBJPEG_DIR}/source/jdmerge.c
	${LIBJPEG_DIR}/source/jdpostct.c
	${LIBJPEG_DIR}/source/jdsample.c
	${LIBJPEG_DIR}/source/jdtrans.c
	${LIBJPEG_DIR}/source/jerror.c
#	${LIBJPEG_DIR}/source/jfdctflt.c
#	${LIBJPEG_DIR}/source/jfdctfst.c
#	${LIBJPEG_DIR}/source/jfdctint.c
	${LIBJPEG_DIR}/source/jidctflt.c
	${LIBJPEG_DIR}/source/jidctfst.c
	${LIBJPEG_DIR}/source/jidctint.c
#	${LIBJPEG_DIR}/source/jmemansi.c
#	${LIBJPEG_DIR}/source/jmemdos.c
#	${LIBJPEG_DIR}/source/jmemmac.c
	${LIBJPEG_DIR}/source/jmemmgr.c
#	${LIBJPEG_DIR}/source/jmemname.c
	${LIBJPEG_DIR}/source/jmemnobs.c
#	${LIBJPEG_DIR}/source/jpegtran.c
	${LIBJPEG_DIR}/source/jquant1.c
	${LIBJPEG_DIR}/source/jquant2.c
	${LIBJPEG_DIR}/source/jutils.c
#	${LIBJPEG_DIR}/source/rdbmp.c
#	${LIBJPEG_DIR}/source/rdcolmap.c
#	${LIBJPEG_DIR}/source/rdgif.c
#	${LIBJPEG_DIR}/source/rdjpgcom.c
#	${LIBJPEG_DIR}/source/rdppm.c
#	${LIBJPEG_DIR}/source/rdrle.c
#	${LIBJPEG_DIR}/source/rdswitch.c
#	${LIBJPEG_DIR}/source/rdtarga.c
#	${LIBJPEG_DIR}/source/transupp.c
#	${LIBJPEG_DIR}/source/wrbmp.c
#	${LIBJPEG_DIR}/source/wrgif.c
#	${LIBJPEG_DIR}/source/wrjpgcom.c
#	${LIBJPEG_DIR}/source/wrppm.c
#	${LIBJPEG_DIR}/source/wrrle.c
#	${LIBJPEG_DIR}/source/wrtarga.c
	#
	# FreeRTOS Porting against CMSIS/ARM Cortex-M7
	#
	${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1/port.c
#	${FREERTOS_DIR}/portable/MemMang/heap_1.c
#	${FREERTOS_DIR}/portable/MemMang/heap_2.c
#	${FREERTOS_DIR}/portable/MemMang/heap_3.c
	${FREERTOS_DIR}/portable/MemMang/heap_4.c
#	${FREERTOS_DIR}/portable/MemMang/heap_5.c
	${FREERTOS_DIR}/CMSIS_RTOS/cmsis_os.c
	#
	# FreeRTOS Core Components
	#
	${FREERTOS_DIR}/croutine.c
	${FREERTOS_DIR}/event_groups.c
	${FREERTOS_DIR}/list.c
	${FREERTOS_DIR}/queue.c
#	${FREERTOS_DIR}/stream_buffer.c
	${FREERTOS_DIR}/tasks.c
#	${FREERTOS_DIR}/timers.c
	#
	# TouchGFX OS Wrapping (against FreeRTOS, always ported to CMSIS)
	#
#	${TGFX_OS_DIR}/os/OSWrappers_cmsis.cpp
	${TGFX_OS_DIR}/OSWrappers.cpp
	#
	# TouchGFX Platfrom Porting (mostly for simulation on top of SDL2)
	#
#	${TGFX_FW_DIR}/platform/driver/touch/ST1232TouchController.cpp
#	${TGFX_FW_DIR}/platform/driver/touch/SDL2TouchController.cpp
#	${TGFX_FW_DIR}/platform/hal/simulator/sdl2/HALSDL2_icon.cpp
#	${TGFX_FW_DIR}/platform/hal/simulator/sdl2/HALSDL2.cpp
#	${TGFX_FW_DIR}/platform/hal/simulator/sdl2/OSWrappers.cpp
	#
	# TouchGFX Widgest and Containers (mostly for simulation on top of SDL2)
	#
#	${TGFX_FW_DIR}/source/touchgfx/widgets/Box.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/TextureMapper.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/AnimatedImage.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/AbstractButton.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/Keyboard.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/SnapshotWidget.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/RadioButton.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/ScalableImage.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/ButtonWithLabel.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/TextArea.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/RepeatButton.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/Image.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/TouchArea.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/Circle.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterBW.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainterGRAY4.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainterGRAY2.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterBWBitmap.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainter.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterRGB888Bitmap.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterGRAY2Bitmap.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/Line.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/Canvas.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainterBW.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractShape.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterRGB565.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterGRAY2.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterRGB565Bitmap.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterRGB888.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/CanvasWidget.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainterRGB565.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterGRAY4Bitmap.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/AbstractPainterRGB888.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/canvas/PainterGRAY4.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/TextAreaWithWildcard.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/BoxWithBorder.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/ToggleButton.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/PixelDataWidget.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/AnimationTextureMapper.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/Button.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/TiledImage.cpp
#	${TGFX_FW_DIR}/source/touchgfx/widgets/ButtonWithIcon.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/ListLayout.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/ModalWindow.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/SwipeContainer.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/Container.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/ScrollWheel.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/ScrollWheelBase.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/ScrollWheelWithSelectionStyle.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/ScrollBase.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/ScrollList.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/scrollers/DrawableList.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/CircleProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/BoxProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/LineProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/AbstractProgressIndicator.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/TextProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/AbstractDirectionProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/progress_indicators/ImageProgress.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/ZoomAnimationImage.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/clock/AnalogClock.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/clock/AbstractClock.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/clock/DigitalClock.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/SlideMenu.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/ScrollableContainer.cpp
#	${TGFX_FW_DIR}/source/touchgfx/containers/Slider.cpp
	#
	# Application Startup Code
	#
	${PROJECT_DIR}/Startup/startup_stm32f769xx.s
	${PROJECT_DIR}/Startup/system_stm32f7xx.c
	${PROJECT_DIR}/Startup/stm32f7xx_it.c
#	${PROJECT_DIR}/Startup/stm32f7xx_hal_msp.c
#	${PROJECT_DIR}/Startup/stm32f7xx_hal_timebase_rtc_alarm.c
#	${PROJECT_DIR}/Startup/stm32f7xx_hal_timebase_rtc_wakeup.c
	${PROJECT_DIR}/Startup/stm32f7xx_hal_timebase_tim.c
	#
	# Application Main Entries
	#
	${PROJECT_DIR}/Sources/syscalls.c
#	${PROJECT_DIR}/Sources/ppp_diskio.c
#	${PROJECT_DIR}/Sources/sd_diskio_dma_rtos_bspv1.c
#	${PROJECT_DIR}/Sources/sd_diskio_dma_rtos_bspv2.c
#	${PROJECT_DIR}/Sources/sd_diskio_dma_bspv1.c
#	${PROJECT_DIR}/Sources/sd_diskio_dma_bspv2.c
#	${PROJECT_DIR}/Sources/sd_diskio_bspv1.c
#	${PROJECT_DIR}/Sources/sd_diskio_bspv2.c
#	${PROJECT_DIR}/Sources/sdram_diskio_bspv1.c
#	${PROJECT_DIR}/Sources/sdram_diskio_bspv2.c
#	${PROJECT_DIR}/Sources/sram_diskio.c
#	${PROJECT_DIR}/Sources/usbh_diskio_dma.c
	${PROJECT_DIR}/Sources/usbh_diskio.c
	${PROJECT_DIR}/Sources/usbh_conf.c
	${PROJECT_DIR}/Sources/hwjpeg_decode.c
#	${PROJECT_DIR}/Sources/jdata_conf.c
	${PROJECT_DIR}/Sources/audio_player_app.c
	${PROJECT_DIR}/Sources/storage_app.c
	${PROJECT_DIR}/Sources/rtc_app.c
	${PROJECT_DIR}/Sources/main.cpp
	#
	# Application GUI, target part
	#
	${PRJGUIT_DIR}/BoardConfiguration.cpp
	${PRJGUIT_DIR}/GPIO.cpp
	${PRJGUIT_DIR}/OTM8009TouchController.cpp
	${PRJGUIT_DIR}/STM32F7DMA.cpp
	${PRJGUIT_DIR}/STM32F7HAL_DSI.cpp
	${PRJGUIT_DIR}/STM32F7Instrumentation.cpp
	#
	# Application GUI, generated fonts part
	#
	${PRJGUIF_DIR}/src/ApplicationFontProvider.cpp
	${PRJGUIF_DIR}/src/FontGetters.cpp
	# Noto Sans, Weight: Regular
	# Fonts by Google - Personal-use only. FREE
	# For commercial use please contact owner.
	${PRJGUIF_DIR}/src/Font_NotoSans_Regular_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_NotoSans_Regular_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_NotoSans_Regular_22_4bpp.cpp
	# Asap ("as soon as possible"), Weight: Regular
	# Copyright 2016 The Asap Project Authors (omnibus.type@gmail.com). FREE
	${PRJGUIF_DIR}/src/Font_Asap_Regular_13_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_21_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_28_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_42_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_13_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_21_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_28_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_42_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_13_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_21_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_28_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_42_4bpp.cpp
	# Asap ("as soon as possible"), Weight: Bold
	# Copyright 2016 The Asap Project Authors (omnibus.type@gmail.com). FREE
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_27_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_27_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_27_4bpp.cpp
	# Roboto Medium, Weight: Regular
	# Fonts by developer.android.com FREE
	${PRJGUIF_DIR}/src/Font_Roboto_Medium_30_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Roboto_Medium_30_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Roboto_Medium_30_4bpp.cpp
	# Roboto Bold, Weight: Bold
	# Fonts by developer.android.com FREE
	${PRJGUIF_DIR}/src/Font_Roboto_Bold_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Roboto_Bold_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Roboto_Bold_22_4bpp.cpp
	# Roboto Condensed, Weight: Regular
	# Fonts by developer.android.com FREE
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_110_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_38_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_40_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Regular_54_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_110_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_38_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_40_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Regular_54_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_110_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_38_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_40_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Regular_54_4bpp.cpp
	# Roboto Condensed, Weight: Bold
	# Fonts by developer.android.com FREE
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_30_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_32_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_42_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_56_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_60_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_RobotoCondensed_Bold_90_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_30_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_32_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_42_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_56_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_60_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_RobotoCondensed_Bold_90_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_20_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_22_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_30_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_32_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_42_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_56_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_60_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_RobotoCondensed_Bold_90_4bpp.cpp
	#
	# Application GUI, generated texts part
	#
	${PRJGUIX_DIR}/src/Texts.cpp
	${PRJGUIX_DIR}/src/TypedTextDatabase.cpp
	${PRJGUIX_DIR}/src/LanguageGbr.cpp
	#
	# Application GUI, generated images part
	#
	${PRJGUII_DIR}/src/BitmapDatabase.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/Animating_buttons_background.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/Animating_buttons_full_table_shadow_bottom.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/Animating_buttons_full_table_shadow_left.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/Animating_buttons_full_table_shadow_right.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_2048_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_audio_player_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_controls_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_game_2d_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_home_automation_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_settings_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/animating_buttons_menu_icons_video_player_tiny.cpp
	${PRJGUII_DIR}/src/AnimatingButtonsMenu/Animating_buttons_table_element_shadow.cpp
	${PRJGUII_DIR}/src/Audio/back_notPressed.cpp
	${PRJGUII_DIR}/src/Audio/back_Pressed.cpp
	${PRJGUII_DIR}/src/Audio/fore_not_pressed.cpp
	${PRJGUII_DIR}/src/Audio/fore_pressed.cpp
	${PRJGUII_DIR}/src/Audio/pause_notPressed.cpp
	${PRJGUII_DIR}/src/Audio/pause_pressed.cpp
	${PRJGUII_DIR}/src/Audio/play_notPressed.cpp
	${PRJGUII_DIR}/src/Audio/play_Pressed1.cpp
	${PRJGUII_DIR}/src/Audio/speaker_down_notPressed.cpp
	${PRJGUII_DIR}/src/Audio/speaker_down_Pressed.cpp
	${PRJGUII_DIR}/src/Audio/speaker_mute.cpp
	${PRJGUII_DIR}/src/Audio/speaker_notmute.cpp
	${PRJGUII_DIR}/src/Audio/speaker_up_Pressed.cpp
	${PRJGUII_DIR}/src/Audio/stop_notPressed.cpp
	${PRJGUII_DIR}/src/Audio/stop_Pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/album_circle_256.cpp
	${PRJGUII_DIR}/src/AudioPlayer/album_circle_shadow.cpp
	${PRJGUII_DIR}/src/AudioPlayer/back_icon_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/cover_no_media.cpp
	${PRJGUII_DIR}/src/AudioPlayer/cover_small.cpp
	${PRJGUII_DIR}/src/AudioPlayer/cover_tiny.cpp
	${PRJGUII_DIR}/src/AudioPlayer/cover_unknown_artist.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_background.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_bar_fill.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_bar_knop.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_bar_unfill.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_db_value.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/equalizer_icon_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/folder_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/folder_list_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/loudness_knop.cpp
	${PRJGUII_DIR}/src/AudioPlayer/next_button.cpp
	${PRJGUII_DIR}/src/AudioPlayer/next_button_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/pause_button.cpp
	${PRJGUII_DIR}/src/AudioPlayer/play_button.cpp
	${PRJGUII_DIR}/src/AudioPlayer/player-_list_process_circle_.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_cover_mask.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_cover_overlay.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_cover_shadow.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_icon_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_remove.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_remove_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_underline.cpp
	${PRJGUII_DIR}/src/AudioPlayer/playlist_underline_playing.cpp
	${PRJGUII_DIR}/src/AudioPlayer/previous_button.cpp
	${PRJGUII_DIR}/src/AudioPlayer/previous_button_pressed.cpp
	${PRJGUII_DIR}/src/AudioPlayer/process_circle.cpp
	${PRJGUII_DIR}/src/AudioPlayer/process_circle_knop.cpp
	${PRJGUII_DIR}/src/AudioPlayer/song_list_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/volume_bar.cpp
	${PRJGUII_DIR}/src/AudioPlayer/volume_bar_fill.cpp
	${PRJGUII_DIR}/src/AudioPlayer/volume_icon.cpp
	${PRJGUII_DIR}/src/AudioPlayer/volume_knob.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_background.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_2048_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_2048_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_2048_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_audio_player_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_audio_player_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_audio_player_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_controls_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_controls_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_controls_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_game_2d_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_game_2d_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_game_2d_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_home_automation_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_home_automation_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_home_automation_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_settings_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_settings_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_settings_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_video_player_large.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_video_player_medium.cpp
	${PRJGUII_DIR}/src/CarouselMenu/carousel_menu_icons_video_player_small.cpp
	${PRJGUII_DIR}/src/CarouselMenu/menu_toggle_button.cpp
	${PRJGUII_DIR}/src/CarouselMenu/menu_toggle_button_pressed.cpp
	${PRJGUII_DIR}/src/CarouselMenu/st_menu_button.cpp
	${PRJGUII_DIR}/src/CarouselMenu/st_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/Common/back.cpp
	${PRJGUII_DIR}/src/Common/common_player_bar.cpp
	${PRJGUII_DIR}/src/Common/overlay_background.cpp
	${PRJGUII_DIR}/src/Common/overlay_background_shadow.cpp
	${PRJGUII_DIR}/src/Controls/board_image.cpp
	${PRJGUII_DIR}/src/Controls/clock/blue_glow.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_00_background.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_00_hour_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_00_minute_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_00_second_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_01_background.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_01_hour_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_01_minute_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_01_second_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_02_background.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_02_hour_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_02_minute_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock/clock_02_second_hand.cpp
	${PRJGUII_DIR}/src/Controls/clock_settings_AM.cpp
	${PRJGUII_DIR}/src/Controls/clock_settings_PM.cpp
	${PRJGUII_DIR}/src/Controls/clock_settings_circle.cpp
	${PRJGUII_DIR}/src/Controls/clock_settings_circleSelected.cpp
	${PRJGUII_DIR}/src/Controls/clock_settings_colon.cpp
	${PRJGUII_DIR}/src/Controls/control_line_indicator.cpp
	${PRJGUII_DIR}/src/Controls/controls_2dots.cpp
	${PRJGUII_DIR}/src/Controls/controls_3dots.cpp
	${PRJGUII_DIR}/src/Controls/controls_background.cpp
	${PRJGUII_DIR}/src/Controls/date_picker_background.cpp
	${PRJGUII_DIR}/src/Controls/date_picker_bar.cpp
	${PRJGUII_DIR}/src/Controls/date_picker_shadow_bottom.cpp
	${PRJGUII_DIR}/src/Controls/date_picker_shadow_top.cpp
	${PRJGUII_DIR}/src/Controls/dot_indicator_.cpp
	${PRJGUII_DIR}/src/Controls/dot_indicator_highlighted.cpp
	${PRJGUII_DIR}/src/Controls/eval_board_image.cpp
	${PRJGUII_DIR}/src/Controls/icon_brightness_large.cpp
	${PRJGUII_DIR}/src/Controls/icon_brightness_small.cpp
	${PRJGUII_DIR}/src/Controls/menu_icon.cpp
	${PRJGUII_DIR}/src/Controls/menu_icon_pressed.cpp
	${PRJGUII_DIR}/src/Controls/settings_button.cpp
	${PRJGUII_DIR}/src/Controls/settings_button_pressed.cpp
	${PRJGUII_DIR}/src/Controls/settings_calendar.cpp
	${PRJGUII_DIR}/src/Controls/settings_done.cpp
	${PRJGUII_DIR}/src/Controls/settings_done_pressed.cpp
	${PRJGUII_DIR}/src/Controls/settings_next.cpp
	${PRJGUII_DIR}/src/Controls/settings_next_pressed.cpp
	${PRJGUII_DIR}/src/Controls/slider.cpp
	${PRJGUII_DIR}/src/Controls/slider_full.cpp
	${PRJGUII_DIR}/src/Controls/slider_knop.cpp
	${PRJGUII_DIR}/src/Controls/value_indicator_arrow.cpp
	${PRJGUII_DIR}/src/Controls/value_indicator_circle.cpp
	${PRJGUII_DIR}/src/Controls/value_indicator_glow.cpp
	${PRJGUII_DIR}/src/Controls/value_indicator_wheel.cpp
	${PRJGUII_DIR}/src/Game2048/auto_play_button.cpp
	${PRJGUII_DIR}/src/Game2048/auto_play_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_background.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_dot_off.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_dot_on.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_game_over.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_menu_button.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2048/game_2048_you_win.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_00.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_01.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_02.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_background.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_button.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2048/how_to_play_close_button.cpp
	${PRJGUII_DIR}/src/Game2048/new_game_button.cpp
	${PRJGUII_DIR}/src/Game2048/new_game_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0002.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0004.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0008.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0016.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0032.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0064.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0128.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0256.cpp
	${PRJGUII_DIR}/src/Game2048/tile_0512.cpp
	${PRJGUII_DIR}/src/Game2048/tile_1024.cpp
	${PRJGUII_DIR}/src/Game2048/tile_2048.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_00.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_01.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_02.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_03.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_04.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_05.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_06.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_07.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_08.cpp
	${PRJGUII_DIR}/src/Game2D/collectible_item_09.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_background.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_fly_button.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_fly_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2D/game_2d_frame_background.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_ground.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_menu_button.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_st_button_off.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_st_button_off_pressed.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_st_button_on.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_st_button_pressed.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_topLeaves.cpp
	${PRJGUII_DIR}/src/Game2D/game2d_TreeTops.cpp
	${PRJGUII_DIR}/src/Game2D/sphere1.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_00.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_01.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_02.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_03.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_04.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_05.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_06.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_07.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_08.cpp
	${PRJGUII_DIR}/src/Game2D/sprite_09.cpp
	${PRJGUII_DIR}/src/HomeAutomation/blinds_icon_32.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_automation_background.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_back_button.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_back_button_pressed.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_login_background.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_00.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_01.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_02.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_03.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_04.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_05.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_06.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_07.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_08.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_image_09.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_selected_light.cpp
	${PRJGUII_DIR}/src/HomeAutomation/home_room_selected_lock.cpp
	${PRJGUII_DIR}/src/HomeAutomation/lights_icon_32.cpp
	${PRJGUII_DIR}/src/HomeAutomation/lock_icon_32.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_00.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_01.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_02.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_03.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_04.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_05.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_06.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_07.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_08.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_09.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_10.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_11.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_12.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_13.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_14.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_15.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_16.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_17.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_18.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_19.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_20.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_21.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_22.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_23.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_24.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_25.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_26.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_27.cpp
	${PRJGUII_DIR}/src/HomeAutomation/login/login_node_28.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_blinds.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_blinds_pressed.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_light.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_light_pressed.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_security.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_security_pressed.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_statistics.cpp
	${PRJGUII_DIR}/src/HomeAutomation/main_button_statistics_pressed.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_blue.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_blue_line.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_green.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_green_line.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_red.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_gradient_red_line.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_lower.cpp
	${PRJGUII_DIR}/src/HomeAutomation/statistics_upper.cpp
	${PRJGUII_DIR}/src/Movie/back_bar.cpp
	${PRJGUII_DIR}/src/Movie/back_button.cpp
	${PRJGUII_DIR}/src/Movie/back_button_pressed.cpp
	${PRJGUII_DIR}/src/Movie/back_icon.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_listitem_bar.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_listitem_bar_selected.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_navi_bar.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_shadow_bottom.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_shadow_right.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_shadow_top.cpp
	${PRJGUII_DIR}/src/Movie/browse_folder_title_bar.cpp
	${PRJGUII_DIR}/src/Movie/default_background.cpp
	${PRJGUII_DIR}/src/Movie/directory.cpp
	${PRJGUII_DIR}/src/Movie/document.cpp
	${PRJGUII_DIR}/src/Movie/done_button.cpp
	${PRJGUII_DIR}/src/Movie/done_button_pressed.cpp
	${PRJGUII_DIR}/src/Movie/empty_slot.cpp
	${PRJGUII_DIR}/src/Movie/folder.cpp
	${PRJGUII_DIR}/src/Movie/folder_icon_pressed.cpp
	${PRJGUII_DIR}/src/Movie/folder_large.cpp
	${PRJGUII_DIR}/src/Movie/folder_large_pressed.cpp
	${PRJGUII_DIR}/src/Movie/grid.cpp
	${PRJGUII_DIR}/src/Movie/grid_background.cpp
	${PRJGUII_DIR}/src/Movie/grid_large.cpp
	${PRJGUII_DIR}/src/Movie/grid_large_pressed.cpp
	${PRJGUII_DIR}/src/Movie/grid_pressed.cpp
	${PRJGUII_DIR}/src/Movie/loop.cpp
	${PRJGUII_DIR}/src/Movie/loop_active.cpp
	${PRJGUII_DIR}/src/Movie/menu_icon_white.cpp
	${PRJGUII_DIR}/src/Movie/minus.cpp
	${PRJGUII_DIR}/src/Movie/pause.cpp
	${PRJGUII_DIR}/src/Movie/play.cpp
	${PRJGUII_DIR}/src/Movie/play_overlay_grid.cpp
	${PRJGUII_DIR}/src/Movie/plus.cpp
	${PRJGUII_DIR}/src/Movie/selected.cpp
	${PRJGUII_DIR}/src/Movie/time_line.cpp
	${PRJGUII_DIR}/src/Movie/time_line_active.cpp
	${PRJGUII_DIR}/src/Movie/toggle_off.cpp
	${PRJGUII_DIR}/src/Movie/toggle_on.cpp
	${PRJGUII_DIR}/src/Movie/up_button.cpp
	${PRJGUII_DIR}/src/Movie/up_button_pressed.cpp
	#
	# Application GUI, functional model part
	#
	${PRJGUIM_DIR}/src/audio_player_screen/AudioBottomBar.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/AudioFolderWidget.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/AudioPlayer.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/AudioPlayerPlaylist.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/AudioPlayerPresenter.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/AudioPlayerView.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/BMPFileLoader.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/CoverWidget.cpp
	${PRJGUIM_DIR}/src/audio_player_screen/Equalizer.cpp
	${PRJGUIM_DIR}/src/common/AnimationTextureMapper.cpp
	${PRJGUIM_DIR}/src/common/BottomBar.cpp
	${PRJGUIM_DIR}/src/common/Carousel.cpp
	${PRJGUIM_DIR}/src/common/CollapsibleMenu.cpp
	${PRJGUIM_DIR}/src/common/DemoPresenter.cpp
	${PRJGUIM_DIR}/src/common/DotIndicator.cpp
	${PRJGUIM_DIR}/src/common/FrontendApplication.cpp
	${PRJGUIM_DIR}/src/common/LoginWidget.cpp
	${PRJGUIM_DIR}/src/common/SwipeContainer.cpp
	${PRJGUIM_DIR}/src/common/TiledImage.cpp
	${PRJGUIM_DIR}/src/common/TopBar.cpp
	${PRJGUIM_DIR}/src/common/ZoomAnimationBox.cpp
	${PRJGUIM_DIR}/src/controls_screen/CircularValueIndicator.cpp
	${PRJGUIM_DIR}/src/controls_screen/ControlsPresenter.cpp
	${PRJGUIM_DIR}/src/controls_screen/ControlsView.cpp
	${PRJGUIM_DIR}/src/game2048_screen/Game2048Presenter.cpp
	${PRJGUIM_DIR}/src/game2048_screen/Game2048View.cpp
	${PRJGUIM_DIR}/src/game2048_screen/GameBoard.cpp
	${PRJGUIM_DIR}/src/game2D_screen/CollectibleItem.cpp
	${PRJGUIM_DIR}/src/game2D_screen/Game2DPresenter.cpp
	${PRJGUIM_DIR}/src/game2D_screen/Game2DView.cpp
	${PRJGUIM_DIR}/src/game2D_screen/ParallaxBackground.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/Graph.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/GraphLine.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/HomeAutomationPresenter.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/HomeAutomationView.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/PainterRGB888TiledBitmap.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/RoomControl.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/RoomControlAdjustable.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/RoomControlToggle.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/RoomControlWheel.cpp
	${PRJGUIM_DIR}/src/home_automation_screen/StatisticsContainer.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuAnimatingButtonsView.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuCarouselView.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuPresenter.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuView.cpp
	${PRJGUIM_DIR}/src/model/Model.cpp
	${PRJGUIM_DIR}/src/settings_screen/AnalogClock.cpp
	${PRJGUIM_DIR}/src/settings_screen/AnalogClockWithSetTimeFunctionality.cpp
	${PRJGUIM_DIR}/src/settings_screen/ClockSelectorContainer.cpp
	${PRJGUIM_DIR}/src/settings_screen/DatePicker.cpp
	${PRJGUIM_DIR}/src/settings_screen/DateSelectorContainer.cpp
	${PRJGUIM_DIR}/src/settings_screen/SettingsPresenter.cpp
	${PRJGUIM_DIR}/src/settings_screen/SettingsView.cpp
	${PRJGUIM_DIR}/src/settings_screen/TimeSettingContainer.cpp
	${PRJGUIM_DIR}/src/settings_screen/WheelSelector.cpp
	${PRJGUIM_DIR}/src/video_player_screen/FatFSFileInput.cpp
	${PRJGUIM_DIR}/src/video_player_screen/FolderWidget.cpp
	${PRJGUIM_DIR}/src/video_player_screen/JPEGFileInput.cpp
	${PRJGUIM_DIR}/src/video_player_screen/MJPEGReader.cpp
	${PRJGUIM_DIR}/src/video_player_screen/PlaylistWidget.cpp
	${PRJGUIM_DIR}/src/video_player_screen/StdFileInput.cpp
	${PRJGUIM_DIR}/src/video_player_screen/VideoBottomBar.cpp
	${PRJGUIM_DIR}/src/video_player_screen/VideoPlayerPresenter.cpp
	${PRJGUIM_DIR}/src/video_player_screen/VideoPlayerView.cpp
	${PRJGUIM_DIR}/src/video_player_screen/VideoProgressBar.cpp
)

set (PROJECT_DEFINES
	# LIST COMPILER DEFINITIONS HERE
	ST
	STM32F769xx
	USE_HAL_DRIVER
	USE_STM32769I_DISCO
	USE_FLOATING_POINT
	USE_OS_SYSTICK
	USE_BPP=24
)

set (PROJECT_INCLUDES
	# LIST INCLUDE DIRECTORIES HERE
	${STM32FW_DIR}/Drivers/CMSIS/Include
	${STM32FW_DIR}/Drivers/CMSIS/Device/ST/STM32F7xx/Include
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Inc
	${STM32FW_DIR}/Drivers/BSP/Components/Common
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery
	${USBH_CORE_DIR}/Inc
	${USBH_MSC_DIR}/Inc
	${FATFS_DIR}/src
	${UTILJPEG_DIR}
	${LIBJPEG_DIR}/include
	${FREERTOS_DIR}/portable/GCC/ARM_CM7/r0p1
	${FREERTOS_DIR}/CMSIS_RTOS
	${FREERTOS_DIR}/include
	${TGFX_FW_DIR}/include
	${PROJECT_DIR}/Includes
	${PRJGUIM_DIR}/include
	${PRJGUII_DIR}/include
	${PRJGUIX_DIR}/include
	${PRJGUIF_DIR}/include
	${PRJGUIT_DIR}
)

set (PROJECT_LIBRARIES
	# LIST LIBRARY DIRECTORIES HERE
	-L${TOUCHGFX_DIR}/lib/core/cortex_m7/gcc
	-l:libtouchgfx-float-abi-hard.a
)

############ MODIFY ACCORDING TO REQUIREMENTS) ########################

#######################################################################

################## PROJECT SETUP ######################################
project(${PROJECT_NAME})
enable_language(ASM)

if (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_EXECUTABLE})
  add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
  add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
elseif (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_STATIC_LIBRARY})
  add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

add_compile_definitions (${PROJECT_DEFINES})
include_directories (${PROJECT_INCLUDES})

target_link_libraries (${PROJECT_NAME} ${PROJECT_LIBRARIES})

set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")
set (CMAKE_C_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_CSTD} ${RUNTIME_LIBRARY} ${RUNTIME_CFLAGS} ${RUNTIME_WARNINGS}")
set (CMAKE_CXX_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_CXXSTD} ${RUNTIME_LIBRARY} ${RUNTIME_CXXFLAGS} ${RUNTIME_WARNINGS}")
set (CMAKE_ASM_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_LIBRARY} ${RUNTIME_ASFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} ${RUNTIME_LIBRARY_SYSCALLS} ${RUNTIME_LDFLAGS}")
