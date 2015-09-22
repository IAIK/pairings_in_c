# This script provides message related functions.
#
# Processed variables:
#   SUB_PROJECT...........help messages are not printed for sub projects
#   QUIET.................omit both help and info messages
#
# Provided targets:
#   ---
#
# Provided macros/functions:
#   info_msg..............print an info message
#   help_msg..............print a help message
#   help_target...........print help for a target if it exists

FUNCTION(info_msg message)
  SET(messagePrefix "")
  IF(SUB_PROJECT)
    SET(messagePrefix "${PROJECT_NAME}: ")
  ENDIF()
  IF(NOT QUIET)
    MESSAGE(STATUS "${messagePrefix}${message}")
  ENDIF()
ENDFUNCTION()

FUNCTION(help_msg message)
  IF(NOT SUB_PROJECT)
    INFO_MSG("${message}")
  ENDIF()
ENDFUNCTION()

FUNCTION(help_target target message)
  IF(TARGET ${target} OR
            "${target}" STREQUAL "install" OR
            "${target}" STREQUAL "package" OR
            "${target}" STREQUAL "package_source")
    string(LENGTH "${target}" targetLength)
    IF(targetLength LESS 11)
      HELP_MSG("  ${target}\t\t${message}")
    ELSE()
      HELP_MSG("  ${target}\t${message}")
    ENDIF()
  ENDIF()
ENDFUNCTION()
