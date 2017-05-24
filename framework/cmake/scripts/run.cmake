# Executes a program, control the in and output, and compare the results to
# a reference
#
# The following variables have to be defined to run this script:
#   PROGRAM.............................The program and the parameters which should be executed
#
# The following variables can to be defined to control the behavior:
#   INPUT_FILE..........................Path to the file which is provided via stdin
#   OUTPUT_FILE.........................Path to the file where stdout should be stored
#   ERROR_FILE..........................Path to the file where stderr should be stored
#
#   PRINT_INPUT_FILE....................If an INPUT_FILE is used the output it before the PROGRAM execution
#   PRINT_OUTPUT_FILE...................If an OUTPUT_FILE is used the output it after the PROGRAM execution
#   PRINT_ERROR_FILE....................If an ERROR_FILE is used the output it after the PROGRAM execution
#
#   RETURN_VALUE........................Controls the return value of the script
#    - EXECUTION........................Zero if execution returned 0, non zero otherwhise (default)
#    - COMPARISON.......................Zero if comparison was successful, non zero otherwhise
#    - COMBINED.........................Zero if execution returned 0 and comparison was successful, non zero otherwhise
#    - ZERO.............................Always return zero
#
#   COMPARE_FILES.......................List of files which should be compared against some reference
#   REFERENCE_FILES.....................List of reference files
#   PRE_DELETE_COMPARE_FILES............Delete the files which are later compared before PROGRAM execution
#
# Example for adding a target using this script:
#  add_custom_target( foobar COMMAND "${CMAKE_COMMAND}"
#                 -D "PROGRAM:STRING=${PROGRAM}"
#                 -P "${PROJECT_SOURCE_DIR}/cmake/scripts/run.cmake" )
cmake_minimum_required(VERSION 3.0.0)

#
# Validate the parameters
#
if(NOT PROGRAM)
  message(STATUS "The following variables have to be defined (-D) to run this script:")
  message(STATUS "  PROGRAM.............................The program and the parameters which should be executed")
  message(SEND_ERROR "Invalid/insufficient parameters specified!")
endif()

# Validate that a valid option for the RETURN_VALUE parameter has been specified
set(RETURN_VALUE_OPTIONS EXECUTION COMPARISON COMBINED ZERO)
list(FIND RETURN_VALUE_OPTIONS "${RETURN_VALUE}" idx)
if(RETURN_VALUE AND idx EQUAL -1)
  message(SEND_ERROR "Invalid option (${RETURN_VALUE}) specified as RETURN_VALUE!")
endif()
if(NOT RETURN_VALUE)
  set(RETURN_VALUE EXECUTION)
endif()

# validate that there are as many reference as compare files
list(LENGTH COMPARE_FILES compare_files_length)
list(LENGTH REFERENCE_FILES reference_files_length)
if( NOT compare_files_length EQUAL reference_files_length )
  message(SEND_ERROR "Compare file count (${compare_files_length}) does not match reference file count (${reference_files_length})!")
endif()

#
# Perform pre execution steps
#

# delete compare files if requested
if( PRE_DELETE_COMPARE_FILES )
  foreach(file ${COMPARE_FILES})
    message(STATUS "Deleting \"${file}\" before executing the program")
    file(REMOVE ${file})
  endforeach()
endif()

# generate human readable program execution string
foreach(element IN ITEMS ${PROGRAM})
  if( NOT PROGRAM_STR )
    set(PROGRAM_STR "${element}")
  else()
    set(PROGRAM_STR "${PROGRAM_STR} ${element}")
  endif()
endforeach()

# build up parameters for execute process
set(EXEC_PARAMETERS RESULT_VARIABLE execution_result)
if(INPUT_FILE)
  list(APPEND EXEC_PARAMETERS INPUT_FILE ${INPUT_FILE})
endif()
if(OUTPUT_FILE)
  list(APPEND EXEC_PARAMETERS OUTPUT_FILE ${OUTPUT_FILE})
endif()
if(ERROR_FILE)
  list(APPEND EXEC_PARAMETERS ERROR_FILE ${ERROR_FILE})
endif()

#
# execute the program
#
if(PRINT_INPUT_FILE AND INPUT_FILE)
  file(READ "${INPUT_FILE}" input_data)
  message(STATUS "<Begin of input file (${INPUT_FILE})>\n${input_data}" )
  message(STATUS "<End of input file (${INPUT_FILE})>" )
endif()

message(STATUS "Executing \"${PROGRAM_STR}\"" )
execute_process(COMMAND ${PROGRAM} ${EXEC_PARAMETERS})
message(STATUS "Return Code: ${execution_result}" )

if(PRINT_OUTPUT_FILE AND OUTPUT_FILE)
  file(READ "${OUTPUT_FILE}" output_data)
  message(STATUS "<Begin of output file (${OUTPUT_FILE})>\n${output_data}" )
  message(STATUS "<End of output file (${OUTPUT_FILE})>" )
endif()
if(PRINT_ERROR_FILE AND ERROR_FILE)
  file(READ "${ERROR_FILE}" error_data)
  message(STATUS "<Begin of output file (${ERROR_FILE})>\n${error_data}" )
  message(STATUS "<End of output file (${ERROR_FILE})>" )
endif()

#
# compare all result files
#
set(compare_result "0")
if(compare_files_length GREATER 0)
  foreach(i RANGE 1 ${compare_files_length})
    math(EXPR idx "${i}-1")
    list(GET COMPARE_FILES ${idx} comp_file)
    list(GET REFERENCE_FILES ${idx} ref_file)

    message(STATUS "Comparing \"${comp_file}\" with \"${ref_file}\"")
    execute_process(COMMAND ${CMAKE_COMMAND} -E compare_files ${ref_file} ${comp_file}
                    RESULT_VARIABLE result)
    message(STATUS "Return Code: ${result}" )

    # capture the first error
    if(NOT compare_result AND result )
      set(compare_result ${result})
    endif()
  endforeach()
endif()

if( ( RETURN_VALUE STREQUAL "EXECUTION" AND execution_result ) OR
    ( RETURN_VALUE STREQUAL "COMPARISON" AND compare_result ) OR
    ( RETURN_VALUE STREQUAL "COMBINED" AND (compare_result OR execution_result ) ) )
  message(SEND_ERROR "Run failed!")
endif()
