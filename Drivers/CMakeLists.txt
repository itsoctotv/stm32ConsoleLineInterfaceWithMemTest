# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Drivers/CMSIS

# CMSIS-V5
CloneRepository(
  "${STMGitHub_URL}/cmsis_core.git" "v5.4.0_cm7" "cmsis_core"
  "${CMAKE_CURRENT_LIST_DIR}/CMSIS"
)

# STM32CubeF7 CMSIS Device MCU Component
CloneRepository(
  "${STMGitHub_URL}/cmsis_device_f7.git" "v1.2.8" "cmsis_device_f7"
  "${CMAKE_CURRENT_LIST_DIR}/CMSIS/Device/ST/STM32F7xx"
)

##### Drivers/<hal>

# STM32CubeF7 HAL Driver MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32f7xx_hal_driver.git" "v1.3.0" "stm32f7xx_hal_driver"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F7xx_HAL_Driver"
)

##### Drivers/BSP

add_subdirectory(BSP)
