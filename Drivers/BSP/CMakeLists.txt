# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Drivers/BSP/<board>

# BSP 32F723EDISCOVERY Component
CloneRepository(
  "${STMGitHub_URL}/32f723ediscovery-bsp.git" "v1.0.3" "32f723ediscovery-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F723E-Discovery"
)

# BSP STM32F7308-DK Component
CloneRepository(
  "${STMGitHub_URL}/stm32f7308-dk-bsp.git" "v1.0.1" "stm32f7308-dk-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F7308-Discovery"
)

# BSP 32F746GDISCOVERY Component
CloneRepository(
  "${STMGitHub_URL}/32f746gdiscovery-bsp.git" "v2.0.4" "32f746gdiscovery-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32746G-Discovery"
)

# BSP STM32F7508-DK Component
CloneRepository(
  "${STMGitHub_URL}/stm32f7508-dk-bsp.git" "v1.0.1" "stm32f7508-dk-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F7508-Discovery"
)

# BSP STM32756G-EVAL Component
CloneRepository(
  "${STMGitHub_URL}/stm32756g-eval-bsp.git" "v2.1.0" "stm32756g-eval-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32756G_EVAL"
)

# BSP 32F769IDISCOVERY Component
CloneRepository(
  "${STMGitHub_URL}/32f769idiscovery-bsp.git" "v2.1.0" "32f769idiscovery-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F769I-Discovery"
)

# BSP STM32F769I-EVAL Component
CloneRepository(
  "${STMGitHub_URL}/stm32f769i-eval-bsp.git" "v2.1.0" "stm32f769i-eval-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F769I_EVAL"
)

# BSP STM32F7xx Nucleo-144 Component
CloneRepository(
  "${STMGitHub_URL}/stm32f7xx-nucleo-144-bsp.git" "v1.0.1" "stm32f7xx-nucleo-144-bsp"
  "${CMAKE_CURRENT_LIST_DIR}/STM32F7xx_Nucleo_144"
)

##### Drivers/BSP/<comp>

add_subdirectory(Adafruit_Shield)
add_subdirectory(Components)
