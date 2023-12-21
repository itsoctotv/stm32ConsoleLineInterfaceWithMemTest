# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Drivers/BSP/Components/<chip>

# BSP COMMON Component
CloneRepository(
  "${STMGitHub_URL}/stm32-bsp-common.git" "v4.0.1" "stm32-bsp-common"
  "${CMAKE_CURRENT_LIST_DIR}/Common"
)

# BSP ADV7533 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-adv7533.git" "v1.0.2" "stm32-adv7533"
  "${CMAKE_CURRENT_LIST_DIR}/adv7533"
)

# BSP AM-480272 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ampire480272.git" "v1.0.1" "stm32-ampire480272"
  "${CMAKE_CURRENT_LIST_DIR}/ampire480272"
)

# BSP AM-640480 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ampire640480.git" "v1.0.1" "stm32-ampire640480"
  "${CMAKE_CURRENT_LIST_DIR}/ampire640480"
)

# BSP DP83848 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-dp83848.git" "v1.0.0" "stm32-dp83848"
  "${CMAKE_CURRENT_LIST_DIR}/dp83848"
)

# BSP EXC7200 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-exc7200.git" "v1.0.2" "stm32-exc7200"
  "${CMAKE_CURRENT_LIST_DIR}/exc7200"
)

# BSP FT3X67 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ft3x67.git" "v1.0.1" "stm32-ft3x67"
  "${CMAKE_CURRENT_LIST_DIR}/ft3x67"
)

# BSP FT5336 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ft5336.git" "v1.0.1" "stm32-ft5336"
  "${CMAKE_CURRENT_LIST_DIR}/ft5336"
)

# BSP FT6X06 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ft6x06.git" "v1.0.2" "stm32-ft6x06"
  "${CMAKE_CURRENT_LIST_DIR}/ft6x06"
)

# BSP LAN8742 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-lan8742.git" "v1.0.1" "stm32-lan8742"
  "${CMAKE_CURRENT_LIST_DIR}/lan8742"
)

# BSP MFXSTM32L152 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-mfxstm32l152.git" "v2.0.1" "stm32-mfxstm32l152"
  "${CMAKE_CURRENT_LIST_DIR}/mfxstm32l152"
)

# BSP MX25L512 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-mx25l512.git" "v1.0.3" "stm32-mx25l512"
  "${CMAKE_CURRENT_LIST_DIR}/mx25l512"
)

# BSP N25Q128A Component
CloneRepository(
  "${STMGitHub_URL}/stm32-n25q128a.git" "v1.0.1" "stm32-n25q128a"
  "${CMAKE_CURRENT_LIST_DIR}/n25q128a"
)

# BSP N25Q256A Component
CloneRepository(
  "${STMGitHub_URL}/stm32-n25q256a.git" "v1.0.1" "stm32-n25q256a"
  "${CMAKE_CURRENT_LIST_DIR}/n25q256a"
)

# BSP N25Q512A Component
CloneRepository(
  "${STMGitHub_URL}/stm32-n25q512a.git"
  "v1.0.0"
# "v1.0.1" <-- Tag is missing, but it is pointless,
#              because only the comment was changed.
  "stm32-n25q512a"
  "${CMAKE_CURRENT_LIST_DIR}/n25q512a"
)

# BSP NT35510 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-nt35510.git"
  "v1.0.0"
# "v1.0.1" <-- Tag is missing, but it is pointless,
#              because only the comment was changed.
  "stm32-nt35510"
  "${CMAKE_CURRENT_LIST_DIR}/nt35510"
)

# BSP OTM8009A Component
CloneRepository(
  "${STMGitHub_URL}/stm32-otm8009a.git" "v1.0.5" "stm32-otm8009a"
  "${CMAKE_CURRENT_LIST_DIR}/otm8009a"
)

# BSP OV5640 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ov5640.git" "v2.0.0" "stm32-ov5640"
  "${CMAKE_CURRENT_LIST_DIR}/ov5640"
)

# BSP OV9655 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ov9655.git" "v1.0.1" "stm32-ov9655"
  "${CMAKE_CURRENT_LIST_DIR}/ov9655"
)

# BSP RK043FN48H Component
CloneRepository(
  "${STMGitHub_URL}/stm32-rk043fn48h.git" "v1.0.1" "stm32-rk043fn48h"
  "${CMAKE_CURRENT_LIST_DIR}/rk043fn48h"
)

# BSP S5K5CAG Component
CloneRepository(
  "${STMGitHub_URL}/stm32-s5k5cag.git" "v1.0.1" "stm32-s5k5cag"
  "${CMAKE_CURRENT_LIST_DIR}/s5k5cag"
)

# BSP ST7735 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-st7735.git" "v1.1.2" "stm32-st7735"
  "${CMAKE_CURRENT_LIST_DIR}/st7735"
)

# BSP ST7789H2 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-st7789h2.git" "v1.1.2" "stm32-st7789h2"
  "${CMAKE_CURRENT_LIST_DIR}/st7789h2"
)

# BSP STMPE811 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-stmpe811.git" "v2.0.1" "stm32-stmpe811"
  "${CMAKE_CURRENT_LIST_DIR}/stmpe811"
)

# BSP TS3510 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-ts3510.git" "v1.0.2" "stm32-ts3510"
  "${CMAKE_CURRENT_LIST_DIR}/ts3510"
)

# BSP WM8994 Component
CloneRepository(
  "${STMGitHub_URL}/stm32-wm8994.git" "v2.2.1" "stm32-wm8994"
  "${CMAKE_CURRENT_LIST_DIR}/wm8994"
)
