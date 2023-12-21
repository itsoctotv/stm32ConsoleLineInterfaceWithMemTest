# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

include(fetch-sources)

##### Documentation

# STM32CubeF7 Developer Documentation
DownloadObject(
  "dm00180213-um1891" "MD5=94306d57d0337724982511671df4def5"
  "${STTECHDOC_URL}/user_manual/DM00180213.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

# STM32CubeCLT Developer Documentation
DownloadObject(
  "dm00915660-um3088" "MD5=7818fdda2e06ccf95f9197a789275b69"
  "${STTECHDOC_URL}/user_manual/DM00915660.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00915661-um3089" "MD5=87edb63d1fb6ceb147fecccd5df9f26b"
  "${STTECHDOC_URL}/user_manual/DM00915661.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

# STM32CubeIDE Developer Documentation
DownloadObject(
  "dm00629856-um2609" "MD5=8f978e2c6201f282501819101737f7de"
  "${STTECHDOC_URL}/user_manual/DM00629856.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00613038-um2576" "MD5=7d9335e055eeea706a8106986d1e2ff9"
  "${STTECHDOC_URL}/user_manual/DM00613038.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00965631-an5952" "MD5=53c8c2665c806f4cf87c1b07e95e7bb5"
  "${STTECHDOC_URL}/application_note/DM00965631.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00354244-an4989" "MD5=794a4039014f59687b3c8985e182bee2"
  "${STTECHDOC_URL}/application_note/DM00354244.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

# ST-LINK Developer Documentation
DownloadObject(
  "dm00290229-tn1235" "MD5=bc56aec20069294d60bbe918e8827a0b"
  "${STTECHDOC_URL}/technical_note/DM00290229.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00026748-um1075" "MD5=2f4efbcdfde709a475fde8de3d512e5e"
  "${STTECHDOC_URL}/user_manual/DM00026748.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00526767-um2448" "MD5=b4e77844816e694409816536fb06a997"
  "${STTECHDOC_URL}/user_manual/DM00526767.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00813040-um2910" "MD5=816722f84617629d26ed253ffda01f2a"
  "${STTECHDOC_URL}/user_manual/DM00813040.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "dm00555046-um2502" "MD5=6801bc26f11656467f1a7a80efe78178"
  "${STTECHDOC_URL}/user_manual/DM00555046.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)

DownloadObject(
  "cd00262073-um0892" "MD5=b6b5df38398b586c5dbfaa4e113e8144"
  "${STTECHDOC_URL}/user_manual/CD00262073.pdf"
  "${CMAKE_CURRENT_LIST_DIR}"
)
