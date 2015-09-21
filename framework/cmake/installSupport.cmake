# This script provides install related targets and functions. This includes
# an simple uninstall target.
#
# Processed variables:
#   SUB_PROJECT...........install_lib is a NOP in sub projects
#
# Provided targets:
#   uninstall.............uninstalls files based on the install_manifest
#
# Provided macros/functions:
#   install_lib...........wrapper for cmakes install function

FUNCTION(install_lib)
  IF(SUB_PROJECT)
    RETURN()
  ENDIF()
  install(${ARGV})
ENDFUNCTION()

# the master project is responsible for the installation
IF(SUB_PROJECT)
  RETURN()
ENDIF()

IF(WIN32)
  list(APPEND CPACK_GENERATOR "NSIS" "ZIP")
ENDIF()

# configure file which is needed for uninstall target
CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

# add uninstall target to the make file
ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake") 
