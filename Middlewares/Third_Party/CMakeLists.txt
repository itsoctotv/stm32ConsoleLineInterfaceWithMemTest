# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Middlewares/Third_Party/<comp>

# Middleware FatFS MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32_mw_fatfs.git" "r0.12c" "stm32_mw_fatfs"
  "${CMAKE_CURRENT_LIST_DIR}/FatFs"
)

# Middleware FreeRTOS MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32_mw_freertos.git" "v10.2.1" "stm32_mw_freertos"
  "${CMAKE_CURRENT_LIST_DIR}/FreeRTOS"
)

# Middleware LibJPEG MCU Component
CloneRepository(
  "${LPNGitHub_URL}/stm32_mw_libjpeg.git" "v8d-20190329" "stm32_mw_libjpeg"
  "${CMAKE_CURRENT_LIST_DIR}/LibJPEG"
)

# Middleware LwIP MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32_mw_lwip.git" "v2.1.2" "stm32_mw_lwip"
  "${CMAKE_CURRENT_LIST_DIR}/LwIP"
)

# Middleware MbedTLS MCU Component
CloneRepository(
  "${LPNGitHub_URL}/stm32_mw_mbedtls.git" "v2.16.2-20200825" "stm32_mw_mbedtls"
  "${CMAKE_CURRENT_LIST_DIR}/mbedTLS"
)
