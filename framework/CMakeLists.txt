CMAKE_MINIMUM_REQUIRED(VERSION 2.6.4) 

# set project name
PROJECT(bipair_in_c C)

# enable assembler support
ENABLE_LANGUAGE(ASM)

# SET(DEFAULT_BUILD_TYPE MinSizeRel)
SET (DEFAULT_BUILD_TYPE Debug)

SET(DEFAULT_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/static")
SET(DEFAULT_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/lib")
SET(DEFAULT_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out/bin")

SET(DEFAULT_C_FLAGS_GCC "-Wall")
SET(DEFAULT_ECLIPSE_SUPPORT_STATE "ON")
SET(DEFAULT_32BIT_COMPILE_STATE "OFF")

# set default Architecture
IF(NOT ARCHITECTURE)
  SET(ARCHITECTURE "ARCH_X86"
  CACHE STRING "ARCH_X86, ARCH_X86_64, ARCH_CORTEXM0, ..." FORCE)
ENDIF(NOT ARCHITECTURE)

IF(NOT BENCHMARK_SRC)
  SET(BENCHMARK_SRC "BM_CYCLE"
  CACHE STRING "BM_CYCLE, BM_CLOCK" FORCE)
ENDIF(NOT BENCHMARK_SRC)

# extend the compile flags with the needed parameters
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

INCLUDE(setDefaultSettings)          # processes and applies the DEFAULT variables
INCLUDE(forceOutOfSourceBuild)       # prohibit in-source builds

#------------------------------------------------------------------------------
# Project config
#------------------------------------------------------------------------------
INCLUDE_DIRECTORIES("include")

# build all source files into the target
#-----------------------------------------
FILE(GLOB CSources "src/*.c" "src/base/std/bigint/*.c" "src/base/std/fp/*.c" "src/base/std/ec/*.c"
                   "src/base/std/pbc/*.c" "src/hash/*.c" "src/aes/*.c" "src/ibe/*.c")               
FILE(GLOB ASMSources "src/${ASM_ARCH_DIR}/*.S" "src/${ASM_ARCH_DIR}/*/*.S")
#FILE(GLOB ASMSources "src/bi/${ASM_ARCH_DIR}/*.S"   "src/bi/${ASM_ARCH_DIR}/*.asm"
#                     "src/gfp/${ASM_ARCH_DIR}/*.S"  "src/gfp/${ASM_ARCH_DIR}/*.asm"
#                     "src/gf2m/${ASM_ARCH_DIR}/*.S" "src/gf2m/${ASM_ARCH_DIR}/*.asm")

FILE(GLOB TestSources "test/*.c" "demo/*.c")
FILE(GLOB BenchSources "benchmark/*.c")
FILE(GLOB SCSources "sccheck/*.c")

foreach( sourceFile ${TestSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    #message(${exeName})
    add_executable( ${exeName} ${sourceFile} ${CSources} ${ASMSources} ${ARCHITECTURE_C_SOURCES} )
    # add preprocessor define for the target
    SET_TARGET_PROPERTIES("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE}")
endforeach( sourceFile ${TestSources} )

foreach( sourceFile ${SCSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    #message(${exeName})
    add_executable( ${exeName} ${sourceFile} ${CSources} ${ASMSources} ${ARCHITECTURE_C_SOURCES} )
    # add preprocessor define for the target
    SET_TARGET_PROPERTIES("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE}")
endforeach( sourceFile ${TestSources} )

foreach( sourceFile ${BenchSources} )
    get_filename_component(exeName ${sourceFile} NAME_WE)
    #message(${exeName})
    add_executable( ${exeName} ${sourceFile} ${CSources} ${ASMSources} ${ARCHITECTURE_C_SOURCES} )
    if (BENCHMARK_SRC STREQUAL BM_CLOCK) 
	    target_link_libraries(${exeName} "rt")
	endif(BENCHMARK_SRC STREQUAL BM_CLOCK)
	# add preprocessor define for the target
    SET_TARGET_PROPERTIES("${exeName}" PROPERTIES
        COMPILE_FLAGS "-DARCHITECTURE=${ARCHITECTURE} -DBENCHMARK_SRC=${BENCHMARK_SRC}")
endforeach( sourceFile ${TestSources} )

