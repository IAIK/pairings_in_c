# This script provides suite and check targets to simplify testing.
#
# Provided targets:
#   suite.............metatarget for building the test suite
#   check.............build and run the test suite
#
# Provided macros/functions:
#   add_to_suite(target)....................add target to the test suite
#                                           as build dependency
#   add_stdin_test(name target stdinfile)...add a test which expects that a file
#                                           is piped in via stdin
#

IF(SUB_PROJECT)
  RETURN()
ENDIF()

# enable the ctest support
enable_testing()

# add suite target which is used as meta target for building the tests
IF(NOT TARGET "suite")
  add_custom_target("suite")
ENDIF()

# adds an arbitrary target to the test suite as building dependency
macro(add_to_suite target)
  add_dependencies("suite" ${target})
endmacro()

# add check command which calls ctest
# it additionally depends on the suite target to build the test cases
IF(NOT TARGET "check")
  add_custom_target("check" COMMAND ${CMAKE_CTEST_COMMAND}
                            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
                            COMMENT "Executing test suite.")
  add_dependencies("check" "suite")
ENDIF()

# adds a test with a file for stdin
macro(add_stdin_test name target stdinfile)
  add_test(NAME "${name}"
           COMMAND "${CMAKE_SOURCE_DIR}/cmake/run_with_stdin_pipe.sh"
                   $<TARGET_FILE:${target}> "${stdinfile}")
endmacro()
