# This script adds clang-format support to the build system (format target).
#
# Files which should be formated have to be added using add_file_to_format
# function.
#
# Processed variables:
#   CLANGFORMAT_STYLE.............style which should be applied
#                                 (gets exported into the cache)
#   DEFAULT_CLANGFORMAT_STYLE.....when CLANGFORMAT_STYLE is undefined then this
#                                 default style is used to define it
#   SUB_PROJECT...................building the current project as sub project
#                                 disables the format functionality in order to
#                                 prevent reformat operations across projects
#
# Provided targets:
#   format........................reformat the specified source files
#
# Provided macros/functions:
#   add_file_to_format............specifiy files which should be formatted
#
#
# When neither CLANGFORMAT_STYLE nor DEFAULT_CLANGFORMAT_STYLE is set then
# "file" is set as fallback style.
#
# As feedback if the targets are available the CLANGFORMAT_POSSIBLE variable
# is set.

if(NOT SUB_PROJECT)
  # search for clang format and skip formatting support if it could not been found
  find_program(CLANGFORMAT_EXECUTABLE NAMES "clang-format")
  mark_as_advanced(CLANGFORMAT_EXECUTABLE)
  if(NOT CLANGFORMAT_EXECUTABLE AND NOT COMMAND add_file_to_format)
    info_msg("clang-format couldn't be found. Source code formatting will not be available.")
    function(add_file_to_format)
    endfunction()
    return()
  endif()

  # Use "file" as default style if nothing has been specified
  if(NOT DEFAULT_CLANGFORMAT_STYLE)
    set(DEFAULT_CLANGFORMAT_STYLE "file")
  endif()

  # Export the used style to the cache to enable modification
  cache_with_default(CLANGFORMAT_STYLE
                    "${DEFAULT_CLANGFORMAT_STYLE}"
                    "STRING"
                    "Argument for the style parameter of clang-format."
  )
  mark_as_advanced(CLANGFORMAT_STYLE)

  # create format target
  set(CLANGFORMAT_POSSIBLE 0)
  if(CLANGFORMAT_EXECUTABLE AND NOT TARGET format)
    add_custom_target(format)
    set(CLANGFORMAT_POSSIBLE 1)
  endif()
endif()

function(add_file_to_format)
  if(NOT CLANGFORMAT_POSSIBLE OR SUB_PROJECT)
    return()
  endif()

  foreach(absfile ${ARGN} )
    if(NOT IS_ABSOLUTE "${absfile}")
      set(absfile "${CMAKE_CURRENT_SOURCE_DIR}/${absfile}")
    endif( )

    # create a target name which is unique for all files in the project
    file(RELATIVE_PATH target "${PROJECT_SOURCE_DIR}" "${absfile}")
    string(REGEX REPLACE "/" "_" target "_format_${target}")

    # straight forward target which formats all files every time
    #add_custom_target("${target}" COMMAND "${CLANGFORMAT_EXECUTABLE}" "-i" "-style=${CLANGFORMAT_STYLE}" "${absfile}"
    #                    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    #                    COMMENT "Formatting \"${absfile}\"." VERBATIM)

    # cache the format runs and only format the changed ones
    add_custom_target(${target} DEPENDS "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}")
    add_custom_command(OUTPUT "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}"
                        COMMAND "${CLANGFORMAT_EXECUTABLE}" -i "-style=${CLANGFORMAT_STYLE}" "${absfile}"
                        COMMAND "${CMAKE_COMMAND}" -E make_directory "${PROJECT_BINARY_DIR}/_clangformat_cache"
                        COMMAND "${CMAKE_COMMAND}" -E touch "${PROJECT_BINARY_DIR}/_clangformat_cache/${target}"
                        DEPENDS "${absfile}"
                        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                        COMMENT "Formatting \"${absfile}\"." VERBATIM)

    add_dependencies(format ${target})
  endforeach()
endfunction()
