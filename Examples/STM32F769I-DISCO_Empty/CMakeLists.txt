#############################################################################################################################
# file:  CMakeLists.txt
# brief: Template "CMakeLists.txt" for building of executables and static libraries.
#
# usage: Edit "VARIABLES"-section to suit project requirements.
#        For debug build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Debug -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug
#          make -C Debug VERBOSE=1
#        For release build:
#          cmake -DCMAKE_TOOLCHAIN_FILE=cubeide-gcc.cmake  -S ./ -B Release -G"Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
#          make -C Release VERBOSE=1
#############################################################################################################################
cmake_minimum_required(VERSION 3.20)

# Path conventions
file(REAL_PATH "${CMAKE_CURRENT_LIST_DIR}/../.." ROOT_PROJECT_DIR
     BASE_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}" EXPAND_TILDE)
set(PROJECT_DIR "${CMAKE_CURRENT_LIST_DIR}" CACHE INTERNAL "")
set(STM32FW_DIR "${ROOT_PROJECT_DIR}" CACHE INTERNAL "")

###################### CONSTANTS ######################################
set (PROJECT_TYPE_EXECUTABLE          "exe")
set (PROJECT_TYPE_STATIC_LIBRARY      "static-lib")
set (MISA_STATES_ARM                  "-marm")
set (MISA_STATES_THUMB                "-mthumb")
set (MEND_LITTLE                      "-mlittle-endian")
set (MEND_BIG                         "-mbig-endian")
set (MCPU_CORTEX_M0                   "-mcpu=cortex-m0")
set (MCPU_CORTEX_M0PLUS               "-mcpu=cortex-m0plus")
set (MCPU_CORTEX_M3                   "-mcpu=cortex-m3")
set (MCPU_CORTEX_M4                   "-mcpu=cortex-m4")
set (MCPU_CORTEX_M7                   "-mcpu=cortex-m7")
set (MCPU_CORTEX_M33                  "-mcpu=cortex-m33")
set (MFPU_FPV4_SP_D16                 "-mfpu=fpv4-sp-d16")
set (MFPU_FPV5_SP_D16                 "-mfpu=fpv5-sp-d16")
set (MFPU_FPV5_D16                    "-mfpu=fpv5-d16")
set (RUNTIME_LIBRARY_REDUCED_C        "--specs=nano.specs")
set (RUNTIME_LIBRARY_STD_C            "")
set (RUNTIME_LIBRARY_SYSCALLS_MINIMAL "--specs=nosys.specs")
set (RUNTIME_LIBRARY_SYSCALLS_NONE    "")
set (MFLOAT_ABI_SOFTWARE              "-mfloat-abi=soft")
set (MFLOAT_ABI_HARDWARE              "-mfloat-abi=hard")
set (MFLOAT_ABI_MIX                   "-mfloat-abi=softfp")
#######################################################################

###################### VARIABLES ######################################
set (PROJECT_NAME             "STM32F769I-DISCO_Empty")
set (PROJECT_TYPE             "${PROJECT_TYPE_EXECUTABLE}")
set (LINKER_SCRIPT            "${PROJECT_DIR}/STM32F769NIHX_FLASH.ld")
set (MISA                     "${MISA_STATES_THUMB}")
set (MEND                     "${MEND_LITTLE}")
set (MCPU                     "${MCPU_CORTEX_M7}")
set (MFPU                     "${MFPU_FPV5_D16}")
set (MFLOAT_ABI               "")
set (RUNTIME_CSTD             "-std=gnu11")
set (RUNTIME_CFLAGS           "-ffunction-sections -fstack-usage -fcyclomatic-complexity")
set (RUNTIME_CXXSTD           "-std=gnu++14")
set (RUNTIME_CXXFLAGS         "${RUNTIME_CFLAGS} -fno-exceptions -fno-rtti -fno-use-cxa-atexit")
set (RUNTIME_WARNINGS         "-Wall -Wno-strict-aliasing -Werror")
set (RUNTIME_ASFLAGS          "-x assembler-with-cpp")
set (RUNTIME_LIBRARY          "${RUNTIME_LIBRARY_REDUCED_C}")
set (RUNTIME_LIBRARY_SYSCALLS "${RUNTIME_LIBRARY_SYSCALLS_MINIMAL}")
set (RUNTIME_LDFLAGS          "-Wl,-Map=test.map -Wl,--gc-sections -static -Wl,--start-group -lc -lm -Wl,--end-group")


set (PROJECT_SOURCES
	# LIST SOURCE FILES HERE
	#
	# Application Startup Code
	#
	${PROJECT_DIR}/Startup/startup_stm32f769nihx.s
	#
	# Application Main Entries
	#
	${PROJECT_DIR}/Sources/syscalls.c
	${PROJECT_DIR}/Sources/sysmem.c
	${PROJECT_DIR}/Sources/main.c
)

set (PROJECT_DEFINES
	# LIST COMPILER DEFINITIONS HERE
	STM32F769xx
	USE_HAL_DRIVER
	USE_STM32F769I_DISCO
)

set (PROJECT_INCLUDES
	# LIST INCLUDE DIRECTORIES HERE
	${STM32FW_DIR}/Drivers/CMSIS/Include
	${STM32FW_DIR}/Drivers/CMSIS/Device/ST/STM32F7xx/Include
	${STM32FW_DIR}/Drivers/STM32F7xx_HAL_Driver/Inc
	${STM32FW_DIR}/Drivers/BSP/Components/Common
	${STM32FW_DIR}/Drivers/BSP/STM32F769I-Discovery
	${PROJECT_DIR}/Includes
)

set (PROJECT_LIBRARIES
	# LIST LIBRARY DIRECTORIES HERE
)

############ MODIFY ACCORDING TO REQUIREMENTS) ########################

#######################################################################

################## PROJECT SETUP ######################################
project(${PROJECT_NAME})
enable_language(ASM)

if (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_EXECUTABLE})
  add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
  add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${CMAKE_PROJECT_NAME}>)
elseif (${PROJECT_TYPE} MATCHES ${PROJECT_TYPE_STATIC_LIBRARY})
  add_library(${PROJECT_NAME} ${PROJECT_SOURCES})
endif()

add_compile_definitions (${PROJECT_DEFINES})
include_directories (${PROJECT_INCLUDES})

target_link_libraries (${PROJECT_NAME} ${PROJECT_LIBRARIES})

set (CMAKE_EXECUTABLE_SUFFIX ".elf")
set (CMAKE_STATIC_LIBRARY_SUFFIX ".a")
set (CMAKE_C_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_CSTD} ${RUNTIME_LIBRARY} ${RUNTIME_CFLAGS} ${RUNTIME_WARNINGS}")
set (CMAKE_CXX_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_CXXSTD} ${RUNTIME_LIBRARY} ${RUNTIME_CXXFLAGS} ${RUNTIME_WARNINGS}")
set (CMAKE_ASM_FLAGS "${MCPU} ${MISA} ${MEND} ${MFPU} ${MFLOAT_ABI} ${RUNTIME_LIBRARY} ${RUNTIME_ASFLAGS}")
set (CMAKE_EXE_LINKER_FLAGS "-T${LINKER_SCRIPT} ${RUNTIME_LIBRARY_SYSCALLS} ${RUNTIME_LDFLAGS}")
