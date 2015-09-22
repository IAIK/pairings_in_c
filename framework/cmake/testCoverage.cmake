# This script discovers the lcov and the genhtml binaries which are used to
# generate a coverage report. Custom targets for generating 
# a coverage report are registered.
#
# When the "coverage" target should be used it is mandatory to add tests via
# ADD_TEST to the CTest test suite. This suite is executed to create the report.
#
# For manually created coverage reports the targets "covReset" and "covGenerate"
# are defined. These can be used when the coverage of custom program executions
# should be determined.
#
# The following variables can be used to customize the function:
#   DEFAULT_COVERAGE_OUTPUT_DIR............custom output directory for the report
#
# As feedback if the targets are available the COVERAGE_TEST_POSSIBLE variable
# is set.
#

# include the coverage testing logic only once
IF( DEFINED COVERAGE_TEST_POSSIBLE )
  RETURN()
ENDIF()

FIND_PROGRAM(LCOV_COMMAND NAMES lcov)
FIND_PROGRAM(GENHTML_COMMAND NAMES genhtml)
MARK_AS_ADVANCED(LCOV_COMMAND GENHTML_COMMAND)

IF( NOT LCOV_COMMAND OR NOT GENHTML_COMMAND )
  INFO_MSG("lcov and/or genhtml couldn't be found. Coverage testing will not be available." )
ENDIF ( )

SET( COVERAGE_TEST_POSSIBLE 0)
IF( LCOV_COMMAND AND GENHTML_COMMAND AND (CMAKE_COMPILER_IS_GNUCC OR MINGW) )
  SET( COVERAGE_TEST_POSSIBLE 1)

  # add option to enable coverage builds
  OPTION(TEST_COVERAGE "Adds compile flags coverage testing." "OFF")

  IF(TEST_COVERAGE)
    SET(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
  ENDIF()

  # configure default output directory
  IF(NOT DEFAULT_COVERAGE_OUTPUT_DIR)
    SET(DEFAULT_COVERAGE_OUTPUT_DIR "${PROJECT_BINARY_DIR}/_coverage")
  ENDIF()

  IF(NOT COVERAGE_OUTPUT_DIR AND DEFAULT_COVERAGE_OUTPUT_DIR)
    SET(COVERAGE_OUTPUT_DIR "${DEFAULT_COVERAGE_OUTPUT_DIR}"
      CACHE PATH "Output directory for the coverage report.")
  ENDIF()

  SET_PROPERTY(
    DIRECTORY "${PROJECT_SOURCE_DIR}"
    APPEND
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${COVERAGE_OUTPUT_DIR}"
  )

  ADD_CUSTOM_TARGET(covReset COMMAND "${LCOV_COMMAND}" -z -d "${PROJECT_BINARY_DIR}"
                            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                            COMMENT "Reset the counters for the coverage tests."
                            VERBATIM )

  ADD_CUSTOM_TARGET(covGenerate
                            COMMAND "${CMAKE_COMMAND}" -E make_directory "${COVERAGE_OUTPUT_DIR}"
                            COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/base.info"
                            COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/coverage.info"
                            COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                            COMMAND "${LCOV_COMMAND}" -i -c -d "${PROJECT_BINARY_DIR}" -o "${COVERAGE_OUTPUT_DIR}/base.info"
                            COMMAND "${LCOV_COMMAND}" -c -d "${PROJECT_BINARY_DIR}" -o "${COVERAGE_OUTPUT_DIR}/coverage.info"
                            COMMAND "${LCOV_COMMAND}" -a "${COVERAGE_OUTPUT_DIR}/base.info" -a "${COVERAGE_OUTPUT_DIR}/coverage.info" -o "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                            COMMAND "${LCOV_COMMAND}" -r "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info" "/usr/include/*" -o "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                            COMMAND "${CMAKE_COMMAND}" -E chdir "${COVERAGE_OUTPUT_DIR}" "${GENHTML_COMMAND}" -p "${PROJECT_SOURCE_DIR}" "${CMAKE_PROJECT_NAME}.info"
                            WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                            COMMENT "Collect coverage data and generate HTML."
                            VERBATIM )

  ADD_CUSTOM_TARGET( coverage COMMAND "${CMAKE_COMMAND}" -D "LCOV_COMMAND:STRING=${LCOV_COMMAND}"
                                                      -D "GENHTML_COMMAND:STRING=${GENHTML_COMMAND}"
                                                      -D "COVERAGE_OUTPUT_DIR:STRING=${COVERAGE_OUTPUT_DIR}"
                                                      -D "PROJECT_BINARY_DIR:STRING=${PROJECT_BINARY_DIR}"
                                                      -D "PROJECT_SOURCE_DIR:STRING=${PROJECT_SOURCE_DIR}"
                                                      -D "CMAKE_PROJECT_NAME:STRING=${CMAKE_PROJECT_NAME}"
                                                      -P "${PROJECT_SOURCE_DIR}/cmake/executeCoverageTest.cmake"
                                                      VERBATIM )
ENDIF( )




