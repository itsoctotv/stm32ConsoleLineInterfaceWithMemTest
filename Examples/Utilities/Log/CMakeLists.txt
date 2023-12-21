# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Utilities/Log

# STM32Cube Log Utilities Driver
DownloadObject(
  "utilities-log-rn" "MD5=ed6c23aceced3fff1cbed628d270666b"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Log/Release_Notes.html"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-log-cfg-h" "MD5=bc2c214be3939294a4542aacbe71d5c3"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Log/lcd_log_conf_template.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-log-h" "MD5=ec768842943555d62c522871ebd90912"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Log/lcd_log.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-log-c" "MD5=4e26d722ddd47b1761ce8209ef8f377e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Log/lcd_log.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
