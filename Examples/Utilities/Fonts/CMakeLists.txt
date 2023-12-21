# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Utilities/Fonts

# https://github.com/STMicroelectronics/32f769idiscovery-bsp/issues/2
# https://github.com/STMicroelectronics/STM32CubeF7/issues/66#issuecomment-1683969595
# --> https://github.com/pavius/the-dot-factory
# --> https://www.eran.io/the-dot-factory-an-lcd-font-and-image-generator

# STM32Cube Fonts Utilities Driver
DownloadObject(
  "utilities-fonts-rn" "MD5=c14758ce889d76488cb471850fca8100"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/Release_Notes.html"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-fonts-h" "MD5=f066f33f459e0bf7f667ad0e71ad1ddc"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/fonts.h"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-font-5x8-c" "MD5=0dfc8a07fe1c3dff3ab89ede5810018e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/font8.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-font-7x12-c" "MD5=053dd201c8d3e6a0a53437136fb0bd5e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/font12.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-font-11x16-c" "MD5=0da382df995f78e52ea27fabe063902e"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/font16.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-font-14x20-c" "MD5=079a341cda43835af4cd82757306cbc7"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/font20.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
DownloadObject(
  "utilities-font-17x24-c" "MD5=2c75c36836f7a4227392c8bef13896a5"
  "${STM32CubeF7_URL}/raw/${STM32CubeF7_REF}/Utilities/Fonts/font24.c"
  "${CMAKE_CURRENT_LIST_DIR}"
)
