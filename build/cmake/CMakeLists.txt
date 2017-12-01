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


set(REPORT_SRC_FILES  ${C50_SRC_DIR}/report.c)

file(GLOB C50_SRC_FILES ${C50_SRC_DIR}/c50/*.c)
file(GLOB C50_SRC_FILES_AUX ${C50_SRC_DIR}/auxiliaryFunctions/*.c)
file(GLOB C50_HDR_FILES ${C50_SRC_DIR}/auxiliaryFunctions/*.h)
file(GLOB C50_PREP_FILES ${C50_SRC_DIR}/*.i)

file(GLOB C50LIB_SRC_FILES ${C50_SRC_DIR}/c50_lib/*.c)
file(GLOB C50LIB_HDR_FILES ${C50_SRC_DIR}/c50_lib/*.h)
file(GLOB C50LIB_R_SRC_FILES ${C50_SRC_DIR}/c50_lib/Rbased/*.c)
file(GLOB C50LIB_R_HDR_FILES ${C50_SRC_DIR}/c50_lib/Rbased/*.h)

# Creating source groups for IDEs
source_group("Source Files"  FILES ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50LIB_SRC_FILES})
source_group("Source Files\\Rbased" ${C50LIB_R_SRC_FILES})
source_group("Header Files"  FILES ${C50_HDR_FILES} ${C50LIB_HDR_FILES})
source_group("Header Files\\Rbased" ${C50LIB_R_HDR_FILES})
source_group("Preprocessed Files"  FILES ${C50_PREP_FILES})

# @TODO(Raian): Verify here what files are really necessary to each component (C50 and Report)
# @TODO(Raian): Refactor the whole CMake Code
set(C50_FILES ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50_HDR_FILES} ${C50_PREP_FILES})
set(REPORT_FILES ${REPORT_SRC_FILES})# ${C50_HDR_FILES} ${C50_PREP_FILES})

set(C50LIB_FILES ${C50LIB_SRC_FILES} ${C50LIB_HDR_FILES} ${C50_SRC_FILES} ${C50_SRC_FILES_AUX} ${C50_HDR_FILES} ${C50_PREP_FILES})

add_executable(c50 ${C50_FILES})

add_executable(report ${REPORT_FILES})

add_library(c50_lib SHARED ${C50LIB_FILES})
