cmake_minimum_required(VERSION 3.1)

# set project name
project(bipair_in_c C)
set(VERSION_MAJOR "1")
set(VERSION_MINOR "0")
set(VERSION_PATCH "0")

#enable Assembler support
ENABLE_LANGUAGE(ASM)

set(DEFAULT_BUILD_TYPE MinSizeRel)
set(DEFAULT_C_FLAGS_GCC "-Wall -Wextra -Wno-unused-parameter")
set(DOXYGEN_CONFIG_IN_FILE "${PROJECT_SOURCE_DIR}/template.doxy.in")

set(CMAKE_C_STANDARD     99)
set(CMAKE_C_EXTENSIONS   ON)

# set default Architecture
set(ARCHITECTURE "ARCH_X86" CACHE STRING "ARCH_X86, ARCH_X86_64, ARCH_CORTEXM0, ARCH_CORTEXA9, ARCH_CORTEXA11,...")

set(BENCHMARK_SRC "BM_CYCLE" CACHE STRING "BM_CYCLE, BM_CLOCK")

#------------------------------------------------------------------------------
# General config
#------------------------------------------------------------------------------
# add the project internal module directory to the module path
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

include(forceOutOfSourceBuild)       # prohibit in-source builds
include(setDefaultSettings)          # processes and applies the DEFAULT variables
include(messages)                    # helper functions for messages
include(versionSupport)              # build up version strings
include(installSupport)              # add an primitiv uninstall target
include(testCoverage)                # adds coverage test targets
include(testing)                     # enables ctest and generates suite and check
include(clangformat)                 # adds clang-format as format target
include(doxygenSupport)              # adds doxygen target

#------------------------------------------------------------------------------
# Project config
#------------------------------------------------------------------------------
set(CPACK_GENERATOR "TGZ")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "${PROJECT_BINARY_DIR}/" "/[.]git/")
include(CPack)

option(INSTALL_DOXYGEN "Install the doxygen documentation with the library." OFF)
if(INSTALL_DOXYGEN)
  # hack to build the doxygen documentation before installing
  install_lib(CODE "execute_process(COMMAND ${CMAKE_COMMAND} --build . --target doxygen WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\")")
  install_lib(DIRECTORY "${DOXYGEN_OUTPUT_DIR}/" DESTINATION "share/doc/flecc_in_c-${VERSION_FULL}/doxygen")
endif()

# build the pairings_in_c library
#-----------------------------------------
file(GLOB PairingLibSources "src/*.c" "src/base/std/bigint/*.c" "src/base/std/fp/*.c" 
                   "src/base/std/ec/*.c" "src/base/std/pbc/*.c" "src/hash/*.c" 
                   "src/aes/*.c" "src/ibe/*.c" "src/gss/*.c" "src/sdh/*.c")

set(ArchLibSources "")
if(ASM_ARCH_DIR)
  file(GLOB_RECURSE ArchLibSources "src/arch/${ASM_ARCH_DIR}/*.S")
endif()

set(LIBNAME bipair_in_c-${ARCHITECTURE})
add_library(${LIBNAME} ${PairingLibSources} ${ArchLibSources})
target_compile_definitions(${LIBNAME} PUBLIC ARCHITECTURE=${ARCHITECTURE} BENCHMARK_SRC=${BENCHMARK_SRC})
target_include_directories(${LIBNAME} PUBLIC include)

install_lib(TARGETS ${LIBNAME} DESTINATION lib${LIBDIR_INSTALL_SUFFIX})

# build the demos
# -----------------------------------------
file(GLOB DemoSources "demo/*.c")
foreach( sourceFile ${DemoSources} )
  get_filename_component(exeName ${sourceFile} NAME_WE)
  add_executable(${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES})
  target_link_libraries(${exeName} ${LIBNAME})
  add_to_suite(${exeName})
  add_test(NAME ${exeName} COMMAND $<TARGET_FILE:${exeName}>)
endforeach()

# build the benchmark
# -----------------------------------------
FILE(GLOB BenchSources "benchmark/*.c")
foreach( sourceFile ${BenchSources} )
  get_filename_component(exeName ${sourceFile} NAME_WE)
  add_executable( ${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES} )
  if(BENCHMARK_SRC STREQUAL BM_CLOCK) 
    target_link_libraries(${exeName} ${LIBNAME} rt)
  else()
    target_link_libraries(${exeName} ${LIBNAME})
  endif()
endforeach()

# build the test cases and generate test target
# -----------------------------------------
FILE(GLOB TestSources "test/*.c")
foreach( sourceFile ${TestSources} )
  get_filename_component(exeName ${sourceFile} NAME_WE)
  add_executable( ${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES})
  target_link_libraries(${exeName} ${LIBNAME})
  add_to_suite(${exeName})
  add_test(NAME ${exeName} COMMAND $<TARGET_FILE:${exeName}>)
endforeach()

#------------------------------------------------------------------------------
# Print help dialog with provided targets
#------------------------------------------------------------------------------
help_msg("---------------------------------------------------------------------")
help_msg("Configuration for ${CMAKE_PROJECT_NAME} ${VERSION_FULL} done.")
help_msg("INSTALL PREFIX:    ${CMAKE_INSTALL_PREFIX}")
help_msg("BUILD TYPE:        ${CMAKE_BUILD_TYPE}")
help_msg("")
help_msg("Available targets:")
help_target(examples       "Build the example programs.")
help_target(install        "Installing the library.")
help_target(uninstall      "Uninstall the previously installed library.")
help_target(package        "Build and pack the library.")
help_target(package_source "Pack the source directory for distribution.")
help_target(suite          "Build the test suite.")
help_target(check          "Build and execute the test suite.")
help_target(doxygen        "Build doxygen documentation.")
help_target(covReset       "Delete coverage counter files.")
help_target(covGenerate    "Analyze counter files and generate report.")
help_target(coverage       "Reset Counters + run tests + generate report.")
help_target(format         "Format the source files using clang-format.")
help_msg("---------------------------------------------------------------------")
