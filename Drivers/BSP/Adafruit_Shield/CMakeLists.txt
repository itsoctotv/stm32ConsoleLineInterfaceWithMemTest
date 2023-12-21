# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Drivers/BSP/Adafruit_Shield

# STM32CubeF7 BSP Driver Adafruit_Shield Component
DownloadObject(
  "BSP-Adafruit_Shield-rn" "MD5=c9481974d31f6a636d6ee5b3cf5e049f"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Drivers/BSP/Adafruit_Shield/Release_Notes.html"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "BSP-Adafruit_Shield-lcd-c" "MD5=8d77715c738f1bd7f73eaa3501f43fb4"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "BSP-Adafruit_Shield-lcd-h" "MD5=2a836aa787fbb034b6df50c0dda537d5"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Drivers/BSP/Adafruit_Shield/stm32_adafruit_lcd.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "BSP-Adafruit_Shield-sd-c" "MD5=4da3746929d9f7ad05cd580b4bf9caff"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "BSP-Adafruit_Shield-sd-h" "MD5=d59584428e9e731bf183891144550b7b"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Drivers/BSP/Adafruit_Shield/stm32_adafruit_sd.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
