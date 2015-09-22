# This script executes a complete coverage test cycle by:
# 1. reseting the coverage counters
# 2. running the ctest suite
# 3. analyzing the counters and generating the html report
#
# The following variables have to be defined to run this script:
#   COVERAGE_OUTPUT_DIR.................directory where the report will be stored
#   PROJECT_BINARY_DIR..................the root directory for the gcda and gcno files
#   LCOV_COMMAND........................path to the lcov binary
#   GENHTML_COMMAND.....................path to the genhtml binary
#   CMAKE_PROJECT_NAME..................the name of the project
#
# Example for adding a target using this script:
#  ADD_CUSTOM_TARGET( coverage COMMAND "${CMAKE_COMMAND}"
#                 -D "LCOV_COMMAND:STRING=${LCOV_COMMAND}"
#                 -D "GENHTML_COMMAND:STRING=${GENHTML_COMMAND}"
#                 -D "COVERAGE_OUTPUT_DIR:STRING=${COVERAGE_OUTPUT_DIR}"
#                 -D "PROJECT_BINARY_DIR:STRING=${PROJECT_BINARY_DIR}"
#                 -D "PROJECT_SOURCE_DIR:STRING=${PROJECT_SOURCE_DIR}"
#                 -D "CMAKE_PROJECT_NAME:STRING=${CMAKE_PROJECT_NAME}"
#                 -P "${PROJECT_SOURCE_DIR}/cmake/executeCoverageTest.cmake" ) 

IF(NOT COVERAGE_OUTPUT_DIR OR NOT PROJECT_BINARY_DIR OR NOT PROJECT_SOURCE_DIR OR NOT LCOV_COMMAND OR NOT GENHTML_COMMAND OR NOT CMAKE_PROJECT_NAME)
  MESSAGE(STATUS "The following variables have to be defined (-D) to run this script:")
  MESSAGE(STATUS "  COVERAGE_OUTPUT_DIR.................directory where the report will be stored")
  MESSAGE(STATUS "  PROJECT_BINARY_DIR..................the root directory for the gcda and gcno files")
  MESSAGE(STATUS "  PROJECT_SOURCE_DIR..................the root directory of the source")
  MESSAGE(STATUS "  LCOV_COMMAND........................path to the lcov binary")
  MESSAGE(STATUS "  GENHTML_COMMAND.....................path to the genhtml binary")
  MESSAGE(STATUS "  CMAKE_PROJECT_NAME..................the name of the project")
  RETURN()
ENDIF()

# reset the counters
EXECUTE_PROCESS(COMMAND "${LCOV_COMMAND}" -z -d "."
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# execute the test suite
EXECUTE_PROCESS(COMMAND "${CMAKE_CTEST_COMMAND}"
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# create the output directory if not present
EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" -E make_directory "${COVERAGE_OUTPUT_DIR}"
                WORKING_DIRECTORY "${PROJECT_BINARY_DIR}")

# delete the old info files if present
EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" -E remove "base.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" -E remove "coverage.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${CMAKE_COMMAND}" -E remove "${CMAKE_PROJECT_NAME}.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")

# extract the coverage information
EXECUTE_PROCESS(COMMAND "${LCOV_COMMAND}" -i -c -d "${PROJECT_BINARY_DIR}" -o "base.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${LCOV_COMMAND}" -c -d "${PROJECT_BINARY_DIR}" -o "coverage.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${LCOV_COMMAND}" -a "base.info" -a "coverage.info" -o "${CMAKE_PROJECT_NAME}.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${LCOV_COMMAND}" -r "${CMAKE_PROJECT_NAME}.info" "/usr/include/*" -o "${CMAKE_PROJECT_NAME}.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")
EXECUTE_PROCESS(COMMAND "${GENHTML_COMMAND}" -p "${PROJECT_SOURCE_DIR}" "${CMAKE_PROJECT_NAME}.info"
                WORKING_DIRECTORY "${COVERAGE_OUTPUT_DIR}")

