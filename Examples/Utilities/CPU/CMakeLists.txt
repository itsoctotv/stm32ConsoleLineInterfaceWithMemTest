# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Utilities/CPU

# STM32Cube CPU Utilities Driver
DownloadObject(
  "utilities-cpu-rn" "MD5=6b1b1152d2ec881e3e8513643441709d"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/CPU/Release_Notes.html"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-cpu-h" "MD5=3e3dbcc66583202c494f2ffc1db62941"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/CPU/cpu_utils.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-cpu-c" "MD5=869fb08bc2cb2db3301707a7c88b8147"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/CPU/cpu_utils.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
