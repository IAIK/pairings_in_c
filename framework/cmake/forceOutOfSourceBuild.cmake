# check if binary dir is equal to source dir and abort
# to force an out of source build
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR
    "In-source builds are not allowed."
    "Please create a new directory and run CMake from there."
    "(Don't forget to remove the CMakeCache.txt and the CMakeFiles directory!)")
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR}) 
