# This script handles the initialization of the most important and used
# cmake variables. The values are only updated when they don't exist at this
# time and default values are available. Furthermore the default values are
# exported to the cache where they can be manipulated later on.
# 
# Functions:
# * Defining of the default output directories for the different artifacts:
#   DEFAULT_ARCHIVE_OUTPUT_DIRECTORY....directory for static libs
#   DEFAULT_LIBRARY_OUTPUT_DIRECTORY....directory for dynamic/shared libs
#   DEFAULT_RUNTIME_OUTPUT_DIRECTORY....directory for executables
#
# * Defining the default build type:
#   DEFAULT_BUILD_TYPE..................usually Debug or Release
#
# * Defining the C and CXX compiler flags:
#   DEFAULT_C_FLAGS_GCC.................flags when gcc is used (C)
#   DEFAULT_CXX_FLAGS_GCC...............flags when g++ is used (C++)
#   DEFAULT_C_FLAGS_MSVC................flags when cl is used (C)
#   DEFAULT_CXX_FLAGS_MSVC..............flags when cl is used (C++) 
#
# * Defining the linker flags:
#   DEFAULT_EXE_LINKER_FLAGS_GCC........flags for linking executables with GCC
#   DEFAULT_SHARED_LINKER_FLAGS_GCC.....flags for linking shared libs with GCC
#   DEFAULT_EXE_LINKER_FLAGS_MSVC.......flags for linking executables with MSVC
#   DEFAULT_SHARED_LINKER_FLAGS_MSVC....flags for linking shared libs with MSVC
#
# * Enables optional features when the variable is set
#   DEFAULT_ECLIPSE_SUPPORT_STATE....... (ON/OFF) adds compiler flags for better
#                                        error parsing when using eclipse
#                                        (GCC only)
#   DEFAULT_32BIT_COMPILE_STATE......... (ON/OFF) adds compiler flags for doing
#                                        a cross compile to 32-bit while using
#                                        a 64-bit compiler (GCC only)                            
#


#------------------------------------------------------------------------------
# Set build directories
#------------------------------------------------------------------------------
# place all the built static libraries into a common directory
IF(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY AND DEFAULT_ARCHIVE_OUTPUT_DIRECTORY)
  SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${DEFAULT_ARCHIVE_OUTPUT_DIRECTORY}"
  CACHE PATH "Single output directory for building all static and import libraries." FORCE)
ENDIF(NOT CMAKE_ARCHIVE_OUTPUT_DIRECTORY AND DEFAULT_ARCHIVE_OUTPUT_DIRECTORY)

# place all the built shared libraries into a common directory
IF(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY AND DEFAULT_LIBRARY_OUTPUT_DIRECTORY)
  SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${DEFAULT_LIBRARY_OUTPUT_DIRECTORY}"
  CACHE PATH "Single output directory for building all shared libraries." FORCE)
ENDIF(NOT CMAKE_LIBRARY_OUTPUT_DIRECTORY AND DEFAULT_LIBRARY_OUTPUT_DIRECTORY)

# place all the built binaries into a common directory
IF(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY AND DEFAULT_RUNTIME_OUTPUT_DIRECTORY)
  SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${DEFAULT_RUNTIME_OUTPUT_DIRECTORY}"
  CACHE PATH "Single output directory for building all executables." FORCE)
ENDIF(NOT CMAKE_RUNTIME_OUTPUT_DIRECTORY AND DEFAULT_RUNTIME_OUTPUT_DIRECTORY)

#------------------------------------------------------------------------------
# Set build type
#------------------------------------------------------------------------------
# set the default build type to the value of ${DEFAULT_BUILD_TYPE}
# (Values: None, Debug, Release, RelWithDebInfo, MinSizeRel)
IF(NOT CMAKE_BUILD_TYPE AND DEFAULT_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel Coverage." FORCE)
ENDIF(NOT CMAKE_BUILD_TYPE AND DEFAULT_BUILD_TYPE) 

#add buildtype coverage
IF(UNIX OR MINGW)
  SET(COMPILER_FLAGS_COVERAGE "-fprofile-arcs -ftest-coverage")
  SET(LINKER_FLAGS_COVERAGE "-lgcov")
ELSE()
  SET(COMPILER_FLAGS_COVERAGE "")
  SET(LINKER_FLAGS_COVERAGE "")
ENDIF()

SET(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} ${COMPILER_FLAGS_COVERAGE}" CACHE STRING "Flags used by the compiler during coverage builds.")
SET(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG} ${COMPILER_FLAGS_COVERAGE}" CACHE STRING "Flags used by the compiler during coverage builds.")
SET(CMAKE_EXE_LINKER_FLAGS_COVERAGE  "${CMAKE_EXE_LINKER_FLAGS_DEBUG} ${LINKER_FLAGS_COVERAGE}" CACHE STRING "Flags used by the linker during coverage builds.")
SET(CMAKE_MODULE_LINKER_FLAGS_COVERAGE  "${CMAKE_MODULE_LINKER_FLAGS_DEBUG} ${LINKER_FLAGS_COVERAGE}" CACHE STRING "Flags used by the linker during coverage builds.")
SET(CMAKE_SHARED_LINKER_FLAGS_COVERAGE  "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} ${LINKER_FLAGS_COVERAGE}" CACHE STRING "Flags used by the linker during coverage builds.")
MARK_AS_ADVANCED(CMAKE_CXX_FLAGS_COVERAGE CMAKE_C_FLAGS_COVERAGE
          CMAKE_EXE_LINKER_FLAGS_COVERAGE CMAKE_MODULE_LINKER_FLAGS_COVERAGE
          CMAKE_SHARED_LINKER_FLAGS_COVERAGE)

#------------------------------------------------------------------------------
# Set compiler flags
#------------------------------------------------------------------------------
IF(NOT CMAKE_C_FLAGS)
  IF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_C_FLAGS_GCC)
    SET(CMAKE_C_FLAGS "${DEFAULT_C_FLAGS_GCC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  ENDIF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_C_FLAGS_GCC)

  IF(MSVC AND DEFAULT_C_FLAGS_MSVC)
    SET(CMAKE_C_FLAGS "${DEFAULT_C_FLAGS_MSVC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  ENDIF(MSVC AND DEFAULT_C_FLAGS_MSVC)
ENDIF(NOT CMAKE_C_FLAGS)

IF(NOT CMAKE_CXX_FLAGS)
  IF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_CXX_FLAGS_GCC)
    SET(CMAKE_CXX_FLAGS "${DEFAULT_CXX_FLAGS_GCC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  ENDIF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_CXX_FLAGS_GCC)

  IF(MSVC AND DEFAULT_CXX_FLAGS_MSVC)
    SET(CMAKE_CXX_FLAGS "${DEFAULT_CXX_FLAGS_MSVC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  ENDIF(MSVC AND DEFAULT_CXX_FLAGS_MSVC)
ENDIF(NOT CMAKE_CXX_FLAGS)

#------------------------------------------------------------------------------
# Set linker flags
#------------------------------------------------------------------------------
IF(NOT CMAKE_EXE_LINKER_FLAGS)
  IF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_EXE_LINKER_FLAGS_GCC)
    SET(CMAKE_EXE_LINKER_FLAGS "${DEFAULT_EXE_LINKER_FLAGS_GCC}" CACHE STRING
      "Flags used by the linker." FORCE)
  ENDIF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_EXE_LINKER_FLAGS_GCC)

  IF(MSVC AND DEFAULT_EXE_LINKER_FLAGS_MSVC)
    SET(CMAKE_EXE_LINKER_FLAGS "${DEFAULT_EXE_LINKER_FLAGS_MSVC}" CACHE STRING
      "Flags used by the linker." FORCE)
  ENDIF(MSVC AND DEFAULT_EXE_LINKER_FLAGS_MSVC)
ENDIF(NOT CMAKE_EXE_LINKER_FLAGS)

IF(NOT CMAKE_SHARED_LINKER_FLAGS)
  IF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_SHARED_LINKER_FLAGS_GCC)
    SET(CMAKE_SHARED_LINKER_FLAGS "${DEFAULT_SHARED_LINKER_FLAGS_GCC}" CACHE STRING
      "Flags used by the linker during the creation of shared libs." FORCE)
  ENDIF((CMAKE_COMPILER_IS_GNUCC OR MINGW) AND DEFAULT_SHARED_LINKER_FLAGS_GCC)

  IF(MSVC AND DEFAULT_SHARED_LINKER_FLAGS_MSVC)
    SET(CMAKE_SHARED_LINKER_FLAGS "${DEFAULT_SHARED_LINKER_FLAGS_MSVC}" CACHE STRING
      "Flags used by the linker during the creation of shared libs." FORCE)
  ENDIF(MSVC AND DEFAULT_SHARED_LINKER_FLAGS_MSVC)
ENDIF(NOT CMAKE_SHARED_LINKER_FLAGS)

#------------------------------------------------------------------------------
# Enable optional features
#------------------------------------------------------------------------------
# add option to enable eclipse support (GCC only)
IF(CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND DEFINED DEFAULT_ECLIPSE_SUPPORT_STATE)
  OPTION(ENABLE_ECLIPSE_SUPPORT "Adds compile flags for easier error parsing." "${DEFAULT_ECLIPSE_SUPPORT_STATE}")
ENDIF(CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND DEFINED DEFAULT_ECLIPSE_SUPPORT_STATE)

# when building with eclipse support add the specific compile flag
IF(CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND ENABLE_ECLIPSE_SUPPORT)
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fmessage-length=0")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmessage-length=0")
ENDIF(CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND ENABLE_ECLIPSE_SUPPORT)


# add option to cross compile to 32-bit on a 64-bit mashine (GCC only)
IF(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND DEFINED DEFAULT_32BIT_COMPILE_STATE)
  OPTION(BUILD_32_BITS "Cross compile to 32-bit artifacts." "${DEFAULT_32BIT_COMPILE_STATE}")
ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND DEFINED DEFAULT_32BIT_COMPILE_STATE)

# when building for 32 bits add the specific compile flag (-m32 for gcc)
IF(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND BUILD_32_BITS)
  MESSAGE(STATUS "Building executables and libraries in 32 bits.")
  SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m32")
ENDIF(CMAKE_SIZEOF_VOID_P EQUAL 8 AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_COMPILER_IS_GNUCXX AND BUILD_32_BITS)
