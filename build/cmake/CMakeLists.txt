# Description: Build configuration for the GeoDMA Gui Components module
#
#  Author: Raian Vargas Maretto <raian@dpi.inpe.br>
#          Thales Sehn Korting <tkorting@dpi.inpe.br>
#          Emiliano Ferreira Castejon <castejon@dpi.inpe.br>
#

cmake_minimum_required(VERSION 3.8)
project(C50_Library)
set(C50_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(C50_SRC_DIR ${C50_ROOT}/src)
include_directories(${C50_SRC_DIR})

file(GLOB C50_SRC_FILES ${C50_SRC_DIR}/c50/*.c)
file(GLOB C50_SRC_FILES_AUX ${C50_SRC_DIR}/auxiliaryFunctions/*.c)
file(GLOB C50_HDR_FILES ${C50_SRC_DIR}/auxiliaryFunctions/*.h)
file(GLOB C50_PREP_FILES ${C50_SRC_DIR}/*.h)

file(GLOB C50LIB_SRC_FILES ${C50_SRC_DIR}/c50_lib/*.c)
file(GLOB C50LIB_HDR_FILES ${C50_SRC_DIR}/c50_lib/*.h)
file(GLOB C50LIB_R_SRC_FILES ${C50_SRC_DIR}/c50_lib/Rbased/*.c)
file(GLOB C50LIB_R_HDR_FILES ${C50_SRC_DIR}/c50_lib/Rbased/*.h)

if(MSVC)
    add_definitions(/MP)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

# Creating source groups for IDEs
source_group("Source Files"  FILES ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50LIB_SRC_FILES})
source_group("Source Files\\Rbased" FILES ${C50LIB_R_SRC_FILES})
source_group("Header Files"  FILES ${C50_HDR_FILES} ${C50LIB_HDR_FILES})
source_group("Header Files\\Rbased" FILES ${C50LIB_R_HDR_FILES})
source_group("Preprocessed Files" FILES FILES ${C50_PREP_FILES})

# @TODO(Raian): Refactor the whole CMake Code
set(C50_FILES ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50_HDR_FILES} ${C50_PREP_FILES} ${C50LIB_R_SRC_FILES} ${C50LIB_R_HDR_FILES})

set(C50LIB_FILES ${C50LIB_SRC_FILES} ${C50LIB_HDR_FILES} ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50_HDR_FILES} ${C50_PREP_FILES} ${C50LIB_R_SRC_FILES} ${C50LIB_R_HDR_FILES})

add_library(c50_lib STATIC ${C50LIB_FILES})
