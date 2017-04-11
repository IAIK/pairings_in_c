# This script handles the initialization of the most important and used
# cmake variables. The values are only updated when they don't exist at
# this time and default values are available. Furthermore the default values are
# exported to the cache where they can be manipulated later on.
#
# In addition to the default values toolchain variables are processed as well.
# They are automatically appended to the CMAKE flags. Therefore the default
# values are not used in this case.
#
# Processed variables:
# * Defining of the default output directories for the different artifacts:
#   DEFAULT_ARCHIVE_OUTPUT_DIRECTORY....directory for static libs
#   DEFAULT_LIBRARY_OUTPUT_DIRECTORY....directory for dynamic/shared libs
#   DEFAULT_RUNTIME_OUTPUT_DIRECTORY....directory for executables
#
# * Defining the default build type:
#   TOOLCHAIN_BUILD_TYPE or
#   DEFAULT_BUILD_TYPE..................usually Debug or Release
#
# * Defining the ASM, C, and CXX compiler flags:
#   TOOLCHAIN_ASM_FLAGS
#   TOOLCHAIN_C_FLAGS or
#   DEFAULT_C_FLAGS_GCC.................flags when gcc and clang is used (C)
#   DEFAULT_C_FLAGS_MSVC................flags when cl is used (C)
#   TOOLCHAIN_CXX_FLAGS or
#   DEFAULT_CXX_FLAGS_GCC...............flags when g++ and clang++ is used (C++)
#   DEFAULT_CXX_FLAGS_MSVC..............flags when cl is used (C++)
#
# * Defining the linker flags:
#   TOOLCHAIN_LINKER_FLAGS or
#   DEFAULT_EXE_LINKER_FLAGS_GCC........flags for linking executables with GCC
#   DEFAULT_EXE_LINKER_FLAGS_MSVC.......flags for linking executables with MSVC
#   DEFAULT_SHARED_LINKER_FLAGS_GCC.....flags for linking shared libs with GCC
#   DEFAULT_SHARED_LINKER_FLAGS_MSVC....flags for linking shared libs with MSVC
#
# Provided targets:
#   ---
#
# Provided macros/functions:
#   cache_with_default..................cache the variable and use a default
#                                       value if it was empty
#   cache_new_with_default..............cache the variable and use a default
#                                       value if it was undefined
#

# enable the compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

# helper macro to to export a variable to the cache
# the variable is set to an default value when it was empty
# e.g. cache_with_default(MD_ENGINE "foo" "STRING" "The used markdown engine.")
macro(cache_with_default name default type description)
  if(NOT ${name})
    set("${name}" "${default}" CACHE "${type}" "${description}" FORCE)
  else()
    set("${name}" "${${name}}" CACHE "${type}" "${description}" FORCE)
  endif()
endmacro()

# helper macro to to export a variable to the cache
# the variable is set to an default value when it was undefined
# e.g. cache_with_default(MD_ENGINE "foo" "STRING" "The used markdown engine.")
macro(cache_new_with_default name default type description)
  if(NOT DEFINED "${name}")
    set("${name}" "${default}" CACHE "${type}" "${description}" FORCE)
  else()
    set("${name}" "${${name}}" CACHE "${type}" "${description}" FORCE)
  endif()
endmacro()

# determine if the project is built as subproject of another project
if(SUB_PROJECT_${PROJECT_NAME} OR NOT "${PROJECT_NAME}" STREQUAL "${CMAKE_PROJECT_NAME}")
  set(SUB_PROJECT TRUE)
  cache_with_default("SUB_PROJECT_${PROJECT_NAME}"
                     "TRUE"
                     "BOOL"
                     "The project is built as subproject. (no install, no documentation, no format)"
  )
  mark_as_advanced("SUB_PROJECT_${PROJECT_NAME}")
endif()

#------------------------------------------------------------------------------
# Set build directories
#------------------------------------------------------------------------------
# place all the built static libraries into a common directory
cache_with_default(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
                   "${DEFAULT_ARCHIVE_OUTPUT_DIRECTORY}"
                   "PATH"
                   "Single output directory for building all static and import libraries."
)

# place all the built shared libraries into a common directory
cache_with_default(CMAKE_LIBRARY_OUTPUT_DIRECTORY
                   "${DEFAULT_LIBRARY_OUTPUT_DIRECTORY}"
                   "PATH"
                   "Single output directory for building all shared libraries."
)

# place all the built binaries into a common directory
cache_with_default(CMAKE_RUNTIME_OUTPUT_DIRECTORY
                   "${DEFAULT_RUNTIME_OUTPUT_DIRECTORY}"
                   "PATH"
                   "Single output directory for building all executables."
)

mark_as_advanced(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
                 CMAKE_LIBRARY_OUTPUT_DIRECTORY
                 CMAKE_RUNTIME_OUTPUT_DIRECTORY
)

#------------------------------------------------------------------------------
# Set build type
#------------------------------------------------------------------------------
# set the default build type to the value of ${TOOLCHAIN_BUILD_TYPE} or
# ${DEFAULT_BUILD_TYPE}
# (Values: None, Debug, Release, RelWithDebInfo, MinSizeRel)
cache_with_default(CMAKE_BUILD_TYPE
                   "${TOOLCHAIN_BUILD_TYPE}"
                   "STRING"
                   "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
)

cache_with_default(CMAKE_BUILD_TYPE
                   "${DEFAULT_BUILD_TYPE}"
                   "STRING"
                   "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
)

#------------------------------------------------------------------------------
# Set compiler flags
#------------------------------------------------------------------------------
if("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  set(CLANG "1")
endif()

# set flags using the toolchain variables
#----------------------------------------
if(TOOLCHAIN_C_FLAGS)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${TOOLCHAIN_C_FLAGS}")
endif()

if(TOOLCHAIN_CXX_FLAGS)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TOOLCHAIN_CXX_FLAGS}")
endif()

if(TOOLCHAIN_ASM_FLAGS)
  set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} ${TOOLCHAIN_ASM_FLAGS}")
endif()

# set flags using the default variables
#----------------------------------------
if(NOT CMAKE_C_FLAGS)
  if((CMAKE_COMPILER_IS_GNUCC OR MINGW OR CLANG) AND DEFAULT_C_FLAGS_GCC)
    set(CMAKE_C_FLAGS "${DEFAULT_C_FLAGS_GCC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  endif()

  if(MSVC AND DEFAULT_C_FLAGS_MSVC)
    set(CMAKE_C_FLAGS "${DEFAULT_C_FLAGS_MSVC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  endif()
endif()

if(NOT CMAKE_CXX_FLAGS)
  if((CMAKE_COMPILER_IS_GNUCC OR MINGW OR CLANG) AND DEFAULT_CXX_FLAGS_GCC)
    set(CMAKE_CXX_FLAGS "${DEFAULT_CXX_FLAGS_GCC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  endif()

  if(MSVC AND DEFAULT_CXX_FLAGS_MSVC)
    set(CMAKE_CXX_FLAGS "${DEFAULT_CXX_FLAGS_MSVC}" CACHE STRING
      "Flags used by the compiler during all build types." FORCE)
  endif()
endif()

#------------------------------------------------------------------------------
# Set linker flags
#------------------------------------------------------------------------------

# set flags using the toolchain variables
#----------------------------------------
if(TOOLCHAIN_LINKER_FLAGS)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${TOOLCHAIN_LINKER_FLAGS}")
endif()

if(TOOLCHAIN_LINKER_FLAGS)
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${TOOLCHAIN_LINKER_FLAGS}")
endif()

# set flags using the default variables
#----------------------------------------
if(NOT CMAKE_EXE_LINKER_FLAGS)
  if((CMAKE_COMPILER_IS_GNUCC OR MINGW OR CLANG) AND DEFAULT_EXE_LINKER_FLAGS_GCC)
    set(CMAKE_EXE_LINKER_FLAGS "${DEFAULT_EXE_LINKER_FLAGS_GCC}" CACHE STRING
      "Flags used by the linker." FORCE)
  endif()

  if(MSVC AND DEFAULT_EXE_LINKER_FLAGS_MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${DEFAULT_EXE_LINKER_FLAGS_MSVC}" CACHE STRING
      "Flags used by the linker." FORCE)
  endif()
endif()

if(NOT CMAKE_SHARED_LINKER_FLAGS)
  if((CMAKE_COMPILER_IS_GNUCC OR MINGW OR CLANG) AND DEFAULT_SHARED_LINKER_FLAGS_GCC)
    set(CMAKE_SHARED_LINKER_FLAGS "${DEFAULT_SHARED_LINKER_FLAGS_GCC}" CACHE STRING
      "Flags used by the linker during the creation of shared libs." FORCE)
  endif()

  if(MSVC AND DEFAULT_SHARED_LINKER_FLAGS_MSVC)
    set(CMAKE_SHARED_LINKER_FLAGS "${DEFAULT_SHARED_LINKER_FLAGS_MSVC}" CACHE STRING
      "Flags used by the linker during the creation of shared libs." FORCE)
  endif()
endif()

#------------------------------------------------------------------------------
# Enable optional features
#------------------------------------------------------------------------------
# add an option to specifiy a library install suffix
set(DEFAULT_LIBDIR_INSTALL_SUFFIX_INT "")
if(NOT CMAKE_CROSSCOMPILING AND CMAKE_SYSTEM_NAME STREQUAL "Linux")
  if(CMAKE_SIZEOF_VOID_P EQUAL 8 AND EXISTS "/usr/lib64")
    set(DEFAULT_LIBDIR_INSTALL_SUFFIX_INT "64")
  elseif(CMAKE_SIZEOF_VOID_P EQUAL 4 AND EXISTS "/usr/lib32")
    set(DEFAULT_LIBDIR_INSTALL_SUFFIX_INT "32")
  endif()
endif()

cache_new_with_default(LIBDIR_INSTALL_SUFFIX
                       "${DEFAULT_LIBDIR_INSTALL_SUFFIX_INT}"
                       "STRING"
                       "Define suffix of library directory name (e.g., 32 or 64)")
