# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Middlewares/ST/<comp>

# Middleware USB Device MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32_mw_usb_device.git" "v2.11.0" "stm32_mw_usb_device"
  "${CMAKE_CURRENT_LIST_DIR}/STM32_USB_Device_Library"
)

# Middleware USB Host MCU Component
CloneRepository(
  "${STMGitHub_URL}/stm32_mw_usb_host.git" "v3.4.1" "stm32_mw_usb_host"
  "${CMAKE_CURRENT_LIST_DIR}/STM32_USB_Host_Library"
)

# Middleware STM32 Audio PDM2PCM MCU Component - SLA protected, TODO:
#
# REQUIRED: gh auth login -p ssh
# OPTIONAL: gh release list -R lipro/stpdm2pcm
#
# gh release download -D "$(xdg-user-dir DOWNLOAD)" -R lipro/stpdm2pcm -A zip v3.2.0-20191106
# echo "c10c96d937dc3091de65745745b58f31  $(xdg-user-dir DOWNLOAD)/stpdm2pcm-3.2.0-20191106.zip" | md5sum -c
#
# unzip -n -d /tmp "$(xdg-user-dir DOWNLOAD)/stpdm2pcm-3.2.0-20191106.zip"
# mv /tmp/stpdm2pcm-3.2.0-20191106/* "${CMAKE_CURRENT_LIST_DIR}/STM32_Audio/Addons/PDM"
# rm -rf /tmp/stpdm2pcm-3.2.0-20191106
# rm -f "$(xdg-user-dir DOWNLOAD)/stpdm2pcm-3.2.0-20191106.zip"

# Middleware STemWin MCU Component - SLA protected, TODO:
#
# REQUIRED: gh auth login -p ssh
# OPTIONAL: gh release list -R lipro/stemwin
#
# gh release download -D "$(xdg-user-dir DOWNLOAD)" -R lipro/stemwin -A zip v5.44-20180322
# echo "fbf1bfd8e506f3e3052451ef5ff7d6f5  $(xdg-user-dir DOWNLOAD)/stemwin-5.44-20180322.zip" | md5sum -c
#
# unzip -n -d /tmp "$(xdg-user-dir DOWNLOAD)/stemwin-5.44-20180322.zip"
# mv /tmp/stemwin-5.44-20180322/* "${CMAKE_CURRENT_LIST_DIR}/STemWin"
# rm -rf /tmp/stemwin-5.44-20180322
# rm -f "$(xdg-user-dir DOWNLOAD)/stemwin-5.44-20180322.zip"

# Middleware TouchGFX MCU Component - SLA protected, TODO:
#
# REQUIRED: gh auth login -p ssh
# OPTIONAL: gh release list -R lipro/touchgfx
#
# gh release download -D "$(xdg-user-dir DOWNLOAD)" -R lipro/touchgfx -A zip v4.10.0-20181105
# echo "8822e161aba80674e2b0982a9b720833  $(xdg-user-dir DOWNLOAD)/touchgfx-4.10.0-20181105.zip" | md5sum -c
#
# unzip -n -d /tmp "$(xdg-user-dir DOWNLOAD)/touchgfx-4.10.0-20181105.zip"
# mv /tmp/touchgfx-4.10.0-20181105/* "${CMAKE_CURRENT_LIST_DIR}/TouchGFX"
# rm -rf /tmp/touchgfx-4.10.0-20181105
# rm -f "$(xdg-user-dir DOWNLOAD)/touchgfx-4.10.0-20181105.zip"
