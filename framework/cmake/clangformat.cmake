# This script adds clang-format support to the build system (format target).
#
# Files which should be formated have to be added using add_file_to_format
# function.
#
# Processed variables:
#   CLANGFORMAT_SYTLE.............style which should be applied
#                                 (gets exported into the cache)
#   DEFAULT_CLANGFORMAT_SYTLE.....when CLANGFORMAT_SYTLE is undefined then this
#                                 default style is used to define it
#   SUB_PROJECT...................building the current project as sub project
#                                 disables the format functionality in order to
#                                 prevent reformat operations across projects
#
# Provided targets:
#   format...............reformat the specified source files
#
# Provided macros/functions:
#   add_file_to_format...specifiy files which should be formatted
#
#
# When neither CLANGFORMAT_SYTLE nor DEFAULT_CLANGFORMAT_SYTLE is set then
# "file" is set as fallback style.
#
# As feedback if the targets are available the CLANGFORMAT_POSSIBLE variable
# is set.

# clang format enabled master projects should not reformat the sub project
IF(SUB_PROJECT)
  FUNCTION(add_file_to_format)
  ENDFUNCTION()
  RETURN()
ENDIF()

# Use LLVM as default style if nothing has been specified
IF(NOT DEFAULT_CLANGFORMAT_SYTLE)
  SET(DEFAULT_CLANGFORMAT_SYTLE "file")
ENDIF()

# Export the used style to the cache to enable modification
IF(NOT CLANGFORMAT_SYTLE AND DEFAULT_CLANGFORMAT_SYTLE)
  SET(CLANGFORMAT_SYTLE "${DEFAULT_CLANGFORMAT_SYTLE}")
ENDIF()

SET(CLANGFORMAT_SYTLE "${CLANGFORMAT_SYTLE}" CACHE STRING
    "Argument for the style parameter of clang-format." FORCE)

FIND_PROGRAM(CLANGFORMAT_EXECUTABLE NAMES "clang-format")
MARK_AS_ADVANCED(CLANGFORMAT_EXECUTABLE CLANGFORMAT_SYTLE)

IF(NOT CLANGFORMAT_EXECUTABLE)
  INFO_MSG("clang-format couldn't be found. Source code formatting will not be available.")
ENDIF()

# create format target
SET(CLANGFORMAT_POSSIBLE 0)
IF(CLANGFORMAT_EXECUTABLE AND NOT TARGET format)
  ADD_CUSTOM_TARGET(format)
  SET(CLANGFORMAT_POSSIBLE 1)
ENDIF()

FUNCTION(add_file_to_format)
  IF(CLANGFORMAT_POSSIBLE)
    FOREACH(absfile ${ARGN} )
      IF(NOT IS_ABSOLUTE "${absfile}")
        SET(absfile "${CMAKE_CURRENT_SOURCE_DIR}/${absfile}")
      ENDIF( )

      # create a target name which is unique for all files in the project
      FILE(RELATIVE_PATH target "${PROJECT_SOURCE_DIR}" "${absfile}")
      STRING(REGEX REPLACE "/" "_" target "_format_${target}")

      # straight forward target which formats all files every time
      #ADD_CUSTOM_TARGET("${target}" COMMAND "${CLANGFORMAT_EXECUTABLE}" "-i" "-style=${CLANGFORMAT_SYTLE}" "${absfile}"
      #                    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
      #                    COMMENT "Formatting \"${absfile}\"." VERBATIM)

      # cache the format runs and only format the changed ones
      ADD_CUSTOM_TARGET(${target} DEPENDS "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}")
      ADD_CUSTOM_COMMAND(OUTPUT "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}"
                         COMMAND "${CLANGFORMAT_EXECUTABLE}" -i "-style=${CLANGFORMAT_SYTLE}" "${absfile}"
                         COMMAND "${CMAKE_COMMAND}" -E make_directory "${PROJECT_BINARY_DIR}/_clangformat_cache"
                         COMMAND "${CMAKE_COMMAND}" -E touch "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}"
                         DEPENDS "${absfile}"
                         WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                         COMMENT "Formatting \"${absfile}\"." VERBATIM)

      ADD_DEPENDENCIES(format ${target})
    ENDFOREACH()
  ENDIF()
ENDFUNCTION()
