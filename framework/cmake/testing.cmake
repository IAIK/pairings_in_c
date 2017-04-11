# This script provides suite and check targets to simplify testing.

# Processed variables:
#   SUB_PROJECT...................building the current project as sub project
#                                 disables the testing functionality
# Provided targets:
#   suite.........................metatarget for building the test suite
#   check.........................build and run the test suite
#
# Provided macros/functions:
#   add_to_suite(target)....................add target to the test suite
#                                           as build dependency
#   add_stdin_test(name target stdinfile)...add a test which expects that a file
#                                           is piped in via stdin
#

if(NOT SUB_PROJECT)
  # enable the ctest support
  enable_testing()
endif()

# adds an arbitrary target to the test suite as building dependency
macro(add_to_suite target)
  if(SUB_PROJECT)
    return()
  endif()

  # add suite target which is used as meta target for building the tests
  if(NOT TARGET "suite")
    add_custom_target("suite")
  endif()

  # add check command which calls ctest
  # it additionally depends on the suite target to build the test cases
  if(NOT TARGET "check")
    add_custom_target("check" COMMAND ${CMAKE_CTEST_COMMAND}
                              WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                              COMMENT "Executing test suite.")
    add_dependencies("check" "suite")
  endif()

  add_dependencies("suite" ${target})
endmacro()

# adds a test with a file for stdin
macro(add_stdin_test name target stdinfile)
  if(SUB_PROJECT)
    return()
  endif()

  add_test(NAME "${name}"
           COMMAND "${CMAKE_COMMAND}" -D "PROGRAM:STRING=$<TARGET_FILE:${target}>"
                                      -D "INPUT_FILE:FILEPATH=${stdinfile}"
                                      -P "${PROJECT_SOURCE_DIR}/cmake/scripts/run.cmake")
endmacro()
