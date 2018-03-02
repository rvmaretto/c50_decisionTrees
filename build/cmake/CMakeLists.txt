# Description: Build configuration for the GeoDMA Gui Components module
#
#  Author: Raian Vargas Maretto <raian@dpi.inpe.br>
#          Thales Sehn Korting <tkorting@dpi.inpe.br>
#          Emiliano Ferreira Castejon <castejon@dpi.inpe.br>
#

cmake_minimum_required(VERSION 3.4)
project(C50_Library)
set(C50_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../..)
set(C50_SRC_DIR ${C50_ROOT}/src)
include_directories(${C50_SRC_DIR})

file(GLOB C50_SRC_FILES ${C50_SRC_DIR}/c50/*.c)
file(GLOB C50_HDR_FILES ${C50_SRC_DIR}/c50/*.h)
file(GLOB C50_SRC_FILES_AUX ${C50_SRC_DIR}/auxiliaryFunctions/*.c)
file(GLOB C50_HDR_FILES_AUX ${C50_SRC_DIR}/auxiliaryFunctions/*.h)

file(GLOB C50LIB_SRC_FILES ${C50_SRC_DIR}/c50lib/*.c)
file(GLOB C50LIB_HDR_FILES ${C50_SRC_DIR}/c50lib/*.h)
#file(GLOB C50LIB_R_SRC_FILES ${C50_SRC_DIR}/c50lib/Rbased/*.c)
#file(GLOB C50LIB_R_HDR_FILES ${C50_SRC_DIR}/c50lib/Rbased/*.h)

if(MSVC)
    add_definitions(/MP)
    set(CMAKE_DEBUG_POSTFIX "d")
endif()

if(UNIX)
    if(CMAKE_COMPILER_IS_GNUCC)
      add_definitions(-fPIC)
    endif()
endif()

# Creating source groups for IDEs
source_group("Source Files\\C5.0"  FILES ${C50_SRC_FILES})
source_group("Source Files\\C5.0 Lib" FILES  ${C50LIB_SRC_FILES})
source_group("Source Files\\Auxiliary Functions" FILES ${C50_SRC_FILES_AUX})
#source_group("Source Files\\Rbased" FILES ${C50LIB_R_SRC_FILES})
source_group("Header Files\\C5.0"  FILES ${C50_HDR_FILES})
source_group("Header Files\\C5.0 Lib"  FILES ${C50LIB_HDR_FILES})
source_group("Header Files\\Auxiliary Functions" FILES ${C50_HDR_FILES_AUX})
#source_group("Header Files\\Rbased" FILES ${C50LIB_R_HDR_FILES})

# @TODO(Raian): Refactor the whole CMake Code
set(C50LIB_FILES ${C50LIB_SRC_FILES} ${C50LIB_HDR_FILES} ${C50_SRC_FILES} ${C50_HDR_FILES} ${C50_SRC_FILES_AUX} ${C50_HDR_FILES_AUX})

add_library(c50lib STATIC ${C50LIB_FILES})

# -----------------------------------------------------------------------------
# Tests

file(GLOB C50_TEST_SRC_FILES ${C50_SRC_DIR}/tests/*.c)

add_executable(c50_tests ${C50_TEST_SRC_FILES})

set(C50_TESTS_DEPENDENCIES c50lib)

target_link_libraries(c50_tests ${C50_TESTS_DEPENDENCIES})

# -----------------------------------------------------------------------------
# Install

install(TARGETS c50lib
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static)

set(C50_INSTALL_HDR_FILES ${C50LIB_HDR_FILES} ${C50_HDR_FILES})

install(FILES ${C50_INSTALL_HDR_FILES}
        DESTINATION "include/c50lib"
        COMPONENT devel)

