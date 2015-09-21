CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

# set project name
PROJECT(bipair_in_c C)
SET(VERSION_MAJOR "1")
SET(VERSION_MINOR "0")
SET(VERSION_PATCH "0")

#enable Assembler support
ENABLE_LANGUAGE(ASM)

SET(DEFAULT_BUILD_TYPE MinSizeRel)

SET(DEFAULT_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/static")
SET(DEFAULT_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/lib")
SET(DEFAULT_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/bin")

SET(DEFAULT_C_FLAGS_GCC "-Wall")
SET(DEFAULT_ECLIPSE_SUPPORT_STATE "ON")
SET(DEFAULT_32BIT_COMPILE_STATE "OFF")

# set default Architecture
IF(NOT ARCHITECTURE)
  SET(ARCHITECTURE "ARCH_X86"
  CACHE STRING "ARCH_X86, ARCH_X86_64, ARCH_CORTEXM0, ARCH_CORTEXA9, ARCH_CORTEXA11,..." FORCE)
ENDIF(NOT ARCHITECTURE)

IF(NOT BENCHMARK_SRC)
  SET(BENCHMARK_SRC "BM_CYCLE"
  CACHE STRING "BM_CYCLE, BM_CLOCK" FORCE)
ENDIF(NOT BENCHMARK_SRC)

SET(DOXYGEN_CONFIG_IN_FILE "${PROJECT_SOURCE_DIR}/template.doxy.in")

#------------------------------------------------------------------------------
# Compiler Flags 
#------------------------------------------------------------------------------
# adapt compiler flags according to architecture
SET(CMAKE_ASM_FLAGS        "${CMAKE_ASM_FLAGS}        ${ARCHITECTURE_ASM_FLAGS}")
SET(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS}          ${ARCHITECTURE_C_FLAGS}")
SET(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS}        ${ARCHITECTURE_CXX_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${ARCHITECTURE_LINKER_FLAGS}")
SET(CMAKE_ASM_FLAGS        "${CMAKE_ASM_FLAGS}        ${ARCHITECTURE_ASM_FLAGS}")

#------------------------------------------------------------------------------
# General config
#------------------------------------------------------------------------------
# add the project internal module directory to the module path
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

INCLUDE(forceOutOfSourceBuild)       # prohibit in-source builds
INCLUDE(setDefaultSettings)          # processes and applies the DEFAULT variables
INCLUDE(messages)                    # helper functions for messages
INCLUDE(clangformat)                 # add support for batch code reformating
INCLUDE(doxygenSupport)              # adds doxygen support
INCLUDE(installSupport)              # add uninstall target and install helpers
INCLUDE(versionSupport)              # build up version strings
INCLUDE(testCoverage)                # adds coverage test targets
INCLUDE(testing)                     # enables ctest and generates suite and check

#------------------------------------------------------------------------------
# Project config
#------------------------------------------------------------------------------
INCLUDE_DIRECTORIES("include")

set(CPACK_GENERATOR "TGZ")
set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_IGNORE_FILES "${PROJECT_BINARY_DIR}/" "/[.]git/")
INCLUDE(CPack)

# build the pairings_in_c library
#-----------------------------------------
FILE(GLOB PairingLibSources "src/*.c" "src/base/std/bigint/*.c" "src/base/std/fp/*.c" 
                   "src/base/std/ec/*.c" "src/base/std/pbc/*.c" "src/hash/*.c" 
                   "src/aes/*.c" "src/ibe/*.c" "src/gss/*.c" "src/sdh/*.c")
IF(ASM_ARCH_DIR)
    FILE(GLOB_RECURSE ArchLibSources "src/arch/${ASM_ARCH_DIR}/*.S")
ELSE(ASM_ARCH_DIR)
    SET(ArchLibSources "")
ENDIF(ASM_ARCH_DIR)

SET(LIBNAME "bipair_in_c-${ARCHITECTURE}")
ADD_LIBRARY("${LIBNAME}" ${PairingLibSources} ${ArchLibSources})
SET_TARGET_PROPERTIES("${LIBNAME}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE}")
        
install_lib(TARGETS "${LIBNAME}" DESTINATION "lib${LIBDIR_INSTALL_SUFFIX}")

OPTION(INSTALL_DOXYGEN "Install the doxygen documentation with the library." OFF)
IF(INSTALL_DOXYGEN)
  # hack to build the doxygen documentation before installing
  install_lib(CODE "execute_process(COMMAND ${CMAKE_COMMAND} --build . --target doxygen WORKING_DIRECTORY \"${CMAKE_CURRENT_BINARY_DIR}\")")
  install_lib(DIRECTORY "${DOXYGEN_OUTPUT_DIR}/" DESTINATION "share/doc/flecc_in_c-${VERSION_FULL}/doxygen")
ENDIF(INSTALL_DOXYGEN)

# build the demos
# -----------------------------------------
FILE(GLOB DemoSources "demo/*.c")
foreach( sourceFile ${DemoSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    add_executable( ${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES})
    target_link_libraries(${exeName} "${LIBNAME}")
    set_target_properties("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE}")
endforeach( sourceFile ${DemoSources} )

# build the benchmark
# -----------------------------------------
FILE(GLOB BenchSources "benchmark/*.c")
foreach( sourceFile ${BenchSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    add_executable( ${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES} )
    if (BENCHMARK_SRC STREQUAL BM_CLOCK) 
	    target_link_libraries(${exeName} "${LIBNAME}" "rt")
	else (BENCHMARK_SRC STREQUAL BM_CLOCK) 
	    target_link_libraries(${exeName} "${LIBNAME}")
	endif(BENCHMARK_SRC STREQUAL BM_CLOCK)
    set_target_properties("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE} -DBENCHMARK_SRC=${BENCHMARK_SRC}")
endforeach( sourceFile ${BenchSources} )

# build the test cases and generate test target
# -----------------------------------------
FILE(GLOB TestSources "test/*.c")
foreach( sourceFile ${TestSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    add_executable( ${exeName} EXCLUDE_FROM_ALL ${sourceFile} ${ARCHITECTURE_C_SOURCES})
    target_link_libraries(${exeName} "${LIBNAME}")
    set_target_properties("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE}")
    add_to_suite("${exeName}")
    add_test("${exeName}" "out/bin/${exeName}")
endforeach( sourceFile ${TestSources} )

#------------------------------------------------------------------------------
# Print help dialog (assuming make based build system)
#------------------------------------------------------------------------------
HELP_MSG("---------------------------------------------------------------------")
HELP_MSG("Configuration for ${CMAKE_PROJECT_NAME} ${VERSION_FULL} done.")
HELP_MSG("INSTALL PREFIX:      ${CMAKE_INSTALL_PREFIX}")
HELP_MSG("BUILD TYPE:          ${CMAKE_BUILD_TYPE}")
HELP_MSG("")
HELP_MSG("Available targets:")
HELP_TARGET(install        "Installing the library.")
HELP_TARGET(uninstall      "Uninstall the previously installed library.")
HELP_TARGET(package        "Build and pack the library.")
HELP_TARGET(package_source "Pack the source directory for distribution.")
HELP_TARGET(suite          "Build the test cases.")
#HELP_TARGET(check          "Build and execute the test suite.")
HELP_TARGET(doxygen        "Build doxygen documentation.")
HELP_TARGET(covReset       "Delete coverate counter files.")
HELP_TARGET(covGenerate    "Analyze counter files and generate report.")
HELP_TARGET(coverage       "Reset Counters + run tests + generate report.")
HELP_MSG("---------------------------------------------------------------------")



