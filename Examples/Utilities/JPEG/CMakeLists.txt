# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Utilities/JPEG

# STM32Cube JPEG Utilities Driver
DownloadObject(
  "utilities-jpeg-rn" "MD5=f3f34fb46933322149bbfdfcc7a6738e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/JPEG/Release_Notes.html"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-jpeg-cfg-h" "MD5=ca1fb811002243ba7da069f2f096fd4e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/JPEG/jpeg_utils_conf_template.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-jpeg-h" "MD5=e373ad7f6fab6c2d0d449d01d3dfc9b6"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/JPEG/jpeg_utils.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-jpeg-c" "MD5=091c669b5e73d978d4f6c15623eaff6e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/JPEG/jpeg_utils.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
