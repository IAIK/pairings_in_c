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

function(info_msg message)
  set(messagePrefix "")
  if(SUB_PROJECT)
    set(messagePrefix "${PROJECT_NAME}: ")
  endif()
  if(NOT QUIET)
    message(STATUS "${messagePrefix}${message}")
  endif()
endfunction()

function(help_msg message)
  if(NOT SUB_PROJECT)
    info_msg("${message}")
  endif()
endfunction()

function(help_target target message)
  if(TARGET ${target} OR
            "${target}" STREQUAL "install" OR
            "${target}" STREQUAL "package" OR
            "${target}" STREQUAL "package_source")
    string(LENGTH "${target}" targetLength)
    if(targetLength LESS 11)
      help_msg("  ${target}\t\t${message}")
    else()
      help_msg("  ${target}\t${message}")
    endif()
  endif()
endfunction()
