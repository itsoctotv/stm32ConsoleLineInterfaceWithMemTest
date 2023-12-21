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
set (PROJECT_NAME             "STM32F746G-DISCO_TouchGFX")
set (PROJECT_TYPE             "${PROJECT_TYPE_EXECUTABLE}")
set (LINKER_SCRIPT            "${PROJECT_DIR}/STM32F746NGHx_FLASH.ld")
set (MISA                     "${MISA_STATES_THUMB}")
set (MEND                     "${MEND_LITTLE}")
set (MCPU                     "${MCPU_CORTEX_M7}")
set (MFPU                     "${MFPU_FPV5_SP_D16}")
set (MFLOAT_ABI               "${MFLOAT_ABI_HARDWARE}")
set (RUNTIME_CSTD             "-std=gnu11")
set (RUNTIME_CFLAGS           "-ffunction-sections -fstack-usage -fcyclomatic-complexity")
set (RUNTIME_CXXSTD           "-std=gnu++14")
set (RUNTIME_CXXFLAGS         "${RUNTIME_CFLAGS} -fno-exceptions -fno-rtti -fno-use-cxa-atexit")
set (RUNTIME_WARNINGS         "-Wall -Wno-strict-aliasing -Werror")
set (RUNTIME_ASFLAGS          "-x assembler-with-cpp")
set (RUNTIME_LIBRARY          "${RUNTIME_LIBRARY_REDUCED_C}")
set (RUNTIME_LIBRARY_SYSCALLS "${RUNTIME_LIBRARY_SYSCALLS_MINIMAL}")
set (RUNTIME_LDFLAGS          "-Wl,-Map=test.map -Wl,--gc-sections -static -Wl,--start-group -lc -lm -lstdc++ -lsupc++ -Wl,--end-group")


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
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_crc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_dac.c
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
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_sdmmc.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_spi.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_tim.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usart.c
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_usb.c
#	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_ll_utils.c
	#
	# STM32F746G-Discovery Board-Support-Package (BSP)
	#
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_audio.c
#	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_camera.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_eeprom.c
#	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_lcd.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_qspi.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sd.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_sdram.c
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery/stm32746g_discovery_ts.c
	#
	# Common BSP Chip Components driver
	#
	${STM32FW_DIR}/Drivers/BSP/Components/ft5336/ft5336.c
	${STM32FW_DIR}/Drivers/BSP/Components/wm8994/wm8994.c
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
	${FREERTOS_DIR}/timers.c
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
	${PROJECT_DIR}/Startup/startup_stm32f746xx.s
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
	${PROJECT_DIR}/Sources/main.cpp
	#
	# Application GUI, target part
	#
	${PRJGUIT_DIR}/BoardConfiguration.cpp
	${PRJGUIT_DIR}/GPIO.cpp
	${PRJGUIT_DIR}/STM32F746GTouchController.cpp
	${PRJGUIT_DIR}/STM32F7DMA.cpp
	${PRJGUIT_DIR}/STM32F7HAL.cpp
	${PRJGUIT_DIR}/STM32F7Instrumentation.cpp
	#
	# Application GUI, generated fonts part
	#
	${PRJGUIF_DIR}/src/ApplicationFontProvider.cpp
	${PRJGUIF_DIR}/src/FontGetters.cpp
	# Noto Sans, Weight: Regular
	# Fonts by Google - Personal-use only. FREE
	# For commercial use please contact owner.
	${PRJGUIF_DIR}/src/Font_NotoSans_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_NotoSans_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_NotoSans_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_NotoSans_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_NotoSans_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_NotoSans_Regular_18_4bpp.cpp
	# Asap ("as soon as possible"), Weight: Regular
	# Copyright 2016 The Asap Project Authors (omnibus.type@gmail.com). FREE
	${PRJGUIF_DIR}/src/Font_Asap_Regular_11_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_11_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Regular_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_11_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Regular_18_4bpp.cpp
	# Asap ("as soon as possible"), Weight: Bold
	# Copyright 2016 The Asap Project Authors (omnibus.type@gmail.com). FREE
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_Asap_Bold_otf_46_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_Asap_Bold_otf_46_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_15_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_Asap_Bold_otf_46_4bpp.cpp
	# IPA Japanese Extended Gothic
	# Copyright (c) 2010-2014 Information-technology Promotion Agency, Japan
	# IPA Font License Agreement v1.0 (https://opensource.org/licenses/IPA)
	${PRJGUIF_DIR}/src/Font_ipaexg_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Font_ipaexg_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_ipaexg_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Table_ipaexg_18_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_ipaexg_12_4bpp.cpp
	${PRJGUIF_DIR}/src/Kerning_ipaexg_18_4bpp.cpp
	#
	# Application GUI, generated texts part
	#
	${PRJGUIX_DIR}/src/Texts.cpp
	${PRJGUIX_DIR}/src/TypedTextDatabase.cpp
	${PRJGUIX_DIR}/src/LanguageDnk.cpp
	${PRJGUIX_DIR}/src/LanguageGbr.cpp
	${PRJGUIX_DIR}/src/LanguageJpn.cpp
	${PRJGUIX_DIR}/src/LanguageNld.cpp
	${PRJGUIX_DIR}/src/LanguageUkr.cpp
	#
	# Application GUI, generated images part
	#
	${PRJGUII_DIR}/src/BitmapDatabase.cpp
	${PRJGUII_DIR}/src/CustomControls/control_center_button.cpp
	${PRJGUII_DIR}/src/CustomControls/control_center_button_pressed.cpp
	${PRJGUII_DIR}/src/CustomControls/control_color_wheel.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_down.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_down_inactive.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_down_pressed.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_up.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_up-inactive.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_arrow_up-pressed.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_button.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_datepicker_large.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_datepicker_small.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_gauge_large.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_gauge_small.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_percentage_large.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_percentage_small.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_three_way_large.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_icon_three_way_small.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_shadow_bottom.cpp
	${PRJGUII_DIR}/src/CustomControls/control_menu_shadow_top.cpp
	${PRJGUII_DIR}/src/CustomControls/controls_background.cpp
	${PRJGUII_DIR}/src/CustomControls/controls_menu_background.cpp
	${PRJGUII_DIR}/src/CustomControls/controls_three_way_small_circle.cpp
	${PRJGUII_DIR}/src/CustomControls/controls_wheel_background.cpp
	${PRJGUII_DIR}/src/CustomControls/datepicker_bottom_shadow_overlay.cpp
	${PRJGUII_DIR}/src/CustomControls/datepicker_glass_overlay.cpp
	${PRJGUII_DIR}/src/CustomControls/datepicker_main_background.cpp
	${PRJGUII_DIR}/src/CustomControls/datepicker_top_shadow_overlay.cpp
	${PRJGUII_DIR}/src/CustomControls/gauge_background.cpp
	${PRJGUII_DIR}/src/CustomControls/gauge_needle_pin.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_bin_icon_active.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_bin_icon_inactive.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_folder_icon_active.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_folder_icon_inactive.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_papers_icon_active.cpp
	${PRJGUII_DIR}/src/CustomControls/small_circle_papers_icon_inactive.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_background.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_bottom_menu.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_bottom_menu_active.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_bottom_menu_selected.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_dot.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_menu_button.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_side_menu_button.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_side_menu_button_active.cpp
	${PRJGUII_DIR}/src/EasingEquation/easing_side_menu_button_selected.cpp
	${PRJGUII_DIR}/src/EasingEquation/graphDot.cpp
	${PRJGUII_DIR}/src/Graph/blue_area_button_active.cpp
	${PRJGUII_DIR}/src/Graph/blue_area_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/blue_dots_button_active.cpp
	${PRJGUII_DIR}/src/Graph/blue_dots_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/blue_line_button_active.cpp
	${PRJGUII_DIR}/src/Graph/blue_line_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/graph_background_bottom.cpp
	${PRJGUII_DIR}/src/Graph/graph_menu_button.cpp
	${PRJGUII_DIR}/src/Graph/graph_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/Graph/graph_toggle_button_active.cpp
	${PRJGUII_DIR}/src/Graph/graph_toggle_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/graph_top_menu_activate_button.cpp
	${PRJGUII_DIR}/src/Graph/graph_top_menu_line.cpp
	${PRJGUII_DIR}/src/Graph/green_area_button_active.cpp
	${PRJGUII_DIR}/src/Graph/green_area_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/green_dots_button_active.cpp
	${PRJGUII_DIR}/src/Graph/green_dots_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/green_line_button_active.cpp
	${PRJGUII_DIR}/src/Graph/green_line_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/half_circle_toggle_button_active.cpp
	${PRJGUII_DIR}/src/Graph/half_circle_toggle_button_inactive.cpp
	${PRJGUII_DIR}/src/Graph/new_graph.cpp
	${PRJGUII_DIR}/src/Graph/new_graph_pressed.cpp
	${PRJGUII_DIR}/src/Graph/new_pie_chart.cpp
	${PRJGUII_DIR}/src/Graph/new_pie_chart_pressed.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_blue.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_blue_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_green.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_green_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_orange.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_orange_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_purple.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_purple_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_red.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_red_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_yellow.cpp
	${PRJGUII_DIR}/src/Graph/pie_chart_legend_yellow_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_toggle_button_active.cpp
	${PRJGUII_DIR}/src/Graph/pie_toggle_button_inactive.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_01.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_01_pressed.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_02_03.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_02_03_pressed.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_04.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_04_pressed.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_05_06.cpp
	${PRJGUII_DIR}/src/MainMenu/demo_button_05_06_pressed.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_demo_screen_02.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_demo_screen_03.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_demo_screen_04.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_demo_screen_05.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_stage_stretch_left_side.cpp
	${PRJGUII_DIR}/src/MainMenu/menu_stage_stretch_right_side.cpp
	${PRJGUII_DIR}/src/MainMenu/screen_swipe_dots_active.cpp
	${PRJGUII_DIR}/src/MainMenu/screen_swipe_dots_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_dnk_active.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_dnk_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_gbr_active.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_gbr_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_jpn_active.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_jpn_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_nld_active.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_nld_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_ukr_active.cpp
	${PRJGUII_DIR}/src/ProductPresenter/flag_ukr_inactive.cpp
	${PRJGUII_DIR}/src/ProductPresenter/poster_image_00.cpp
	${PRJGUII_DIR}/src/ProductPresenter/poster_image_01.cpp
	${PRJGUII_DIR}/src/ProductPresenter/poster_image_02.cpp
	${PRJGUII_DIR}/src/ProductPresenter/product_presenter_menu_button.cpp
	${PRJGUII_DIR}/src/ProductPresenter/product_presenter_menu_button_pressed.cpp
	${PRJGUII_DIR}/src/ProductPresenter/product_presenter_nav_bar.cpp
	${PRJGUII_DIR}/src/ProductPresenter/product_presenter_next.cpp
	${PRJGUII_DIR}/src/ProductPresenter/product_presenter_next_pressed.cpp
	#
	# Application GUI, functional model part
	#
	${PRJGUIM_DIR}/src/common/CollapsibleMenu.cpp
	${PRJGUIM_DIR}/src/common/DemoPresenter.cpp
	${PRJGUIM_DIR}/src/common/DotIndicator.cpp
	${PRJGUIM_DIR}/src/common/FrontendApplication.cpp
	${PRJGUIM_DIR}/src/common/SwipeContainer.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/CircularProgress.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/CustomControlsPresenter.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/CustomControlsView.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/DatePicker.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/Gauge.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/ThreeWayProgressBar.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/ThreeWayProgressBarCircle.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/VerticalSlideMenu.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/WheelSelector.cpp
	${PRJGUIM_DIR}/src/custom_controls_screen/WheelSelectorExtra.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationButton.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationGraph.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationInOrOutOrInOut.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationPresenter.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationSelector.cpp
	${PRJGUIM_DIR}/src/easing_equation_screen/EasingEquationView.cpp
	${PRJGUIM_DIR}/src/graph_screen/AbstractGraph.cpp
	${PRJGUIM_DIR}/src/graph_screen/Graph.cpp
	${PRJGUIM_DIR}/src/graph_screen/GraphBelow.cpp
	${PRJGUIM_DIR}/src/graph_screen/GraphDots.cpp
	${PRJGUIM_DIR}/src/graph_screen/GraphLine.cpp
	${PRJGUIM_DIR}/src/graph_screen/GraphPresenter.cpp
	${PRJGUIM_DIR}/src/graph_screen/GraphView.cpp
	${PRJGUIM_DIR}/src/graph_screen/LegendEntry.cpp
	${PRJGUIM_DIR}/src/graph_screen/PainterVerticalAlpha.cpp
	${PRJGUIM_DIR}/src/graph_screen/PieChart.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuPresenter.cpp
	${PRJGUIM_DIR}/src/main_menu_screen/MainMenuView.cpp
	${PRJGUIM_DIR}/src/model/Model.cpp
	${PRJGUIM_DIR}/src/product_presenter_screen/ProductPresenterPresenter.cpp
	${PRJGUIM_DIR}/src/product_presenter_screen/ProductPresenterView.cpp
)

set (PROJECT_DEFINES
	# LIST COMPILER DEFINITIONS HERE
	ST
	STM32F746xx
	USE_HAL_DRIVER
	USE_STM32746G_DISCO
	USE_FLOATING_POINT
	USE_BPP=16
)

set (PROJECT_INCLUDES
	# LIST INCLUDE DIRECTORIES HERE
	${STM32FW_DIR}/Drivers/CMSIS/Include
	${STM32FW_DIR}/Drivers/CMSIS/Device/ST/STM32F7xx/Include
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Inc
	${STM32FW_DIR}/Drivers/BSP/Components/Common
	${STM32FW_DIR}/Drivers/BSP/STM32746G-Discovery
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
