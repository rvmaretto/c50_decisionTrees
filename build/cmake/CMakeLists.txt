# Description: Build configuration for the GeoDMA Gui Components module
#
#  Author: Raian Vargas Maretto <raian@dpi.inpe.br>
#          Thales Sehn Korting <tkorting@dpi.inpe.br>
#          Emiliano Ferreira Castejon <castejon@dpi.inpe.br>
#

cmake_minimum_required(VERSION 3.8)
set(SEE5_DIR "C:/Users/Raian/OneDrive/INPE/Projeto_BNDES/References_for_source/Decision_trees/C50_cmake")
include_directories(${SEE5_DIR})

#if(Qt5_FOUND)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#endif()

set(C50_SRC_FILES global.c
                  c50.c
                  construct.c
                  formtree.c
                  info.c
                  discr.c
                  contin.c
                  subset.c
                  prune.c
                  p-thresh.c
                  trees.c
                  siftrules.c
                  ruletree.c
                  rules.c
                  getdata.c
                  implicitatt.c
                  mcost.c
                  confmat.c
                  sort.c
                  update.c
                  attwinnow.c
                  classify.c
                  formrules.c
                  getnames.c
                  modelfiles.c
                  utility.c
                  xval.c
)

set(REPORT_SRC_FILES  report.c)

#file(GLOB SEE5_SRC_FILES ${SEE5_DIR}/*.c)
file(GLOB SEE5_HDR_FILES ${SEE5_DIR}/*.h)
file(GLOB SEE5_PREP_FILES ${SEE5_DIR}/*.i)
#file(GLOB SEE5_UI_FILES ${SEE5_DIR}/geodmalib/guicomponents/ui/*.ui)

# Creating source groups for IDEs
source_group("Source Files"  FILES ${C50_SRC_FILES})
source_group("Header Files"  FILES ${SEE5_HDR_FILES})
source_group("Preprocessed Files"  FILES ${SEE5_PREP_FILES})
#source_group("UI Files"  FILES ${SEE5_UI_FILES})

#if(Qt5_FOUND)
# uic'ing
#QT5_WRAP_UI(SEE5_GEN_HDR_FILES ${SEE5_UI_FILES})
set(SEE5_FILES ${C50_SRC_FILES} ${SEE5_HDR_FILES} ${SEE5_PREP_FILES})# ${SEE5_GEN_HDR_FILES})
set(REPORT_FILES ${REPORT_SRC_FILES} ${SEE5_HDR_FILES} ${SEE5_PREP_FILES})
#add_library(geodma_mod_guicomponents SHARED ${SEE5_FILES})

add_executable(c50 ${SEE5_FILES})

add_executable(report ${REPORT_FILES})

#target_link_libraries(see5 ${GEODMA_EXEC_DEPENDENCIES})
#qt5_use_modules(geodma_mod_guicomponents Widgets)
#endif()
