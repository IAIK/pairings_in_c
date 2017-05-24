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
# Processed variables:
#   COVERAGE_OUTPUT_DIR...........custom output directory for the report
#                                 (gets exported into the cache)
#   DEFAULT_COVERAGE_OUTPUT_DIR...when COVERAGE_OUTPUT_DIR is undefined then
#                                 this default directory is used to define it
#   SUB_PROJECT...................building the current project as sub project
#                                 disables the coverage functionality
#
# Provided targets:
#   covReset......................Delete coverage counter files.
#   covGenerate...................Analyze counter files and generate report.
#   coverage......................Reset Counters + run tests + generate report.
#
# When neither COVERAGE_OUTPUT_DIR nor DEFAULT_COVERAGE_OUTPUT_DIR is set then
# "${PROJECT_BINARY_DIR}/_coverage" is set as fallback directory.

# The master project is responsible for the coverage support.
if(SUB_PROJECT)
  return()
endif()

set(LCOV_GCOV_ARG --rc lcov_branch_coverage=1)
if(CLANG) # "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang"
  string(REGEX REPLACE "^([0-9]+\\.[0-9]+).*" "\\1" CLANG_MAJOR_MINOR_VERSION "${CMAKE_C_COMPILER_VERSION}")
  find_program(LLVM_COV_COMMAND NAMES llvm-cov-${CLANG_MAJOR_MINOR_VERSION} llvm-cov)
  mark_as_advanced(LLVM_COV_COMMAND)
  configure_file("${PROJECT_SOURCE_DIR}/cmake/scripts/llvm-gcov.sh.in"
                 "${CMAKE_CURRENT_BINARY_DIR}/llvm-gcov.sh"
                 @ONLY)
  list(APPEND LCOV_GCOV_ARG --gcov-tool "${CMAKE_CURRENT_BINARY_DIR}/llvm-gcov.sh")
endif()

# Search for lcov and genhtml and skip coverage support on error.
find_program(LCOV_COMMAND NAMES lcov)
find_program(GENHTML_COMMAND NAMES genhtml)
mark_as_advanced(LCOV_COMMAND GENHTML_COMMAND)
if(NOT LCOV_COMMAND OR NOT GENHTML_COMMAND OR (CLANG AND NOT LLVM_COV_COMMAND))
  info_msg("lcov, genhtml, or llvm-cov couldn't be found.")
  info_msg("Coverage testing will not be available.")
  return()
endif()

# add option to enable coverage builds
option(TEST_COVERAGE "Adds compile flags coverage testing." "OFF")
if(TEST_COVERAGE)
  set(CMAKE_C_FLAGS          "${CMAKE_C_FLAGS} --coverage")
  set(CMAKE_CXX_FLAGS        "${CMAKE_CXX_FLAGS} --coverage")
  # C and CXX FLAGS are also used during linking
else()
  return()
endif()

# define a output directory if nothing has been specified
if(NOT DEFAULT_COVERAGE_OUTPUT_DIR)
  set(DEFAULT_COVERAGE_OUTPUT_DIR "${PROJECT_BINARY_DIR}/_coverage")
endif()

# export the output directory to the cache to enable modification
cache_with_default(COVERAGE_OUTPUT_DIR
                   "${DEFAULT_COVERAGE_OUTPUT_DIR}"
                   "PATH"
                   "Output directory for the coverage report."
)
mark_as_advanced(COVERAGE_OUTPUT_DIR)

# add the output directory to the clean target of the project
set_property(
  DIRECTORY "${PROJECT_SOURCE_DIR}"
  APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${COVERAGE_OUTPUT_DIR}"
)

add_custom_target(covReset
                  COMMAND "${LCOV_COMMAND}" -z -d "${PROJECT_BINARY_DIR}"
                  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                  COMMENT "Reset the counters for the coverage tests."
                  VERBATIM
)

add_custom_target(covGenerate
                  COMMAND "${CMAKE_COMMAND}" -E make_directory "${COVERAGE_OUTPUT_DIR}"
                  COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/base.info"
                  COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/coverage.info"
                  COMMAND "${CMAKE_COMMAND}" -E remove "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                  COMMAND "${LCOV_COMMAND}" ${LCOV_GCOV_ARG} -i -c -d "${PROJECT_BINARY_DIR}" -o "${COVERAGE_OUTPUT_DIR}/base.info"
                  COMMAND "${LCOV_COMMAND}" ${LCOV_GCOV_ARG} -c -d "${PROJECT_BINARY_DIR}" -o "${COVERAGE_OUTPUT_DIR}/coverage.info"
                  COMMAND "${LCOV_COMMAND}" ${LCOV_GCOV_ARG} -a "${COVERAGE_OUTPUT_DIR}/base.info" -a "${COVERAGE_OUTPUT_DIR}/coverage.info" -o "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                  COMMAND "${LCOV_COMMAND}" ${LCOV_GCOV_ARG} -r "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info" "/usr/include/*" -o "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                  COMMAND "${LCOV_COMMAND}" ${LCOV_GCOV_ARG} -r "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info" "${PROJECT_SOURCE_DIR}/external/*" -o "${COVERAGE_OUTPUT_DIR}/${CMAKE_PROJECT_NAME}.info"
                  COMMAND "${CMAKE_COMMAND}" -E chdir "${COVERAGE_OUTPUT_DIR}" "${GENHTML_COMMAND}" -p "${PROJECT_SOURCE_DIR}" "${CMAKE_PROJECT_NAME}.info" --branch-coverage
                  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                  COMMENT "Collect coverage data and generate HTML."
                  VERBATIM
)

add_custom_target(coverage
                  COMMAND "${CMAKE_COMMAND}" "--build" "." "--target" "suite"
                  COMMAND "${CMAKE_COMMAND}" "--build" "." "--target" "covReset"
                  COMMAND "${CMAKE_COMMAND}" -D "PROGRAM:STRING=${CMAKE_CTEST_COMMAND}" -D "RETURN_VALUE:STRING=ZERO" -P "${PROJECT_SOURCE_DIR}/cmake/scripts/run.cmake"
                  COMMAND "${CMAKE_COMMAND}" "--build" "." "--target" "covGenerate"
                  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                  VERBATIM
)
