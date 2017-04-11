# This script provides install related targets and functions. This includes
# a simple uninstall target.
#
# Processed variables:
#   SUB_PROJECT...........install_lib is a NOP in sub projects
#
# Provided targets:
#   uninstall.............uninstalls files based on the install_manifest
#
# Provided macros/functions:
#   install_lib..................wrapper for cmakes install function
#   export_and_install_config....Exports and installs config targets given a
#                                export name.
if(NOT SUB_PROJECT)
  if(WIN32)
    list(APPEND CPACK_GENERATOR "NSIS" "ZIP")
  endif()

  # configure file which is needed for uninstall target
  configure_file(
    "${CMAKE_SOURCE_DIR}/cmake/scripts/cmake_uninstall.cmake.in"
    "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

  # add uninstall target to the make file
  add_custom_target(uninstall
    "${CMAKE_COMMAND}" -P "${CMAKE_BINARY_DIR}/cmake_uninstall.cmake")
endif()

function(install_lib)
  if(SUB_PROJECT)
    return()
  endif()

  install(${ARGV})
endfunction()

#
# export_and_install_config( [ARGUMENTS] export_name)
#
# Optional Arguments:
#   NAMESPACE.............Define an install/export namespace.
#
function(export_and_install_config)
  if(SUB_PROJECT)
    return()
  endif()

  set(options "")
  set(oneValueArgs NAMESPACE)
  set(multiValueArgs "")
  cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN} )

  set(export_name ${ARG_UNPARSED_ARGUMENTS})
  string(TOLOWER ${export_name} export_filename)
  include(CMakePackageConfigHelpers)
  set(config_install_dir "lib${LIBDIR_INSTALL_SUFFIX}/cmake/${export_name}")
  set(version_config "${CMAKE_BINARY_DIR}/${export_filename}-config-version.cmake")
  set(project_config "${CMAKE_BINARY_DIR}/${export_filename}-config.cmake")

  # generate the version, config and target files into the build directory
  write_basic_package_version_file(
    "${version_config}"
    VERSION ${VERSION_FULL}
    COMPATIBILITY AnyNewerVersion
  )
  configure_package_config_file(
    "${CMAKE_SOURCE_DIR}/cmake/scripts/target-config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
  )
  export(
    EXPORT "${export_name}"
    NAMESPACE "${ARG_NAMESPACE}"
    FILE "${CMAKE_BINARY_DIR}/${export_filename}-targets.cmake"
  )

  # install version, config and target files
  install(
    FILES "${version_config}" "${project_config}"
    DESTINATION "${config_install_dir}"
  )
  install(
    EXPORT "${export_name}"
    NAMESPACE "${ARG_NAMESPACE}"
    DESTINATION "${config_install_dir}"
    FILE "${export_filename}-targets.cmake"
  )
endfunction()
