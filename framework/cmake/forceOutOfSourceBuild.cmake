# This script enforces that no in source builds can be performed.
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR
    "In-source builds are not allowed."
    "Please create a new directory and run CMake from there."
    "(Don't forget to remove the CMakeCache.txt and the CMakeFiles directory!)")
endif()
