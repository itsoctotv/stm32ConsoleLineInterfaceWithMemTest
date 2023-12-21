# Copyright (c) 2023 Stephan Linz
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.24)
project("RXT_STM32CubeEval")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
include(defaults)

add_subdirectory(Drivers)
add_subdirectory(Middlewares)
add_subdirectory(USB_HOST)
add_subdirectory(Utilities)
add_subdirectory(Documentation)
