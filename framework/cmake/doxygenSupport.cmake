# This script discovers the Doxygen binary and creates a doxygen target when the
# binary and the configuration file could be found.
#
# Processed variables:
#   DOXYGEN_CONFIG_IN_FILE........(mandatory) path to the config file
#   DOXYGEN_OUTPUT_DIR............custom output directory for the documentation
#                                 (gets exported into the cache)
#   DEFAULT_DOXYGEN_OUTPUT_DIR....when DOXYGEN_OUTPUT_DIR is undefined then this
#                                 default directory is used to define it
#   SUB_PROJECT...................building the current project as sub project
#                                 disables the doxygen functionality
#
# Provided targets:
#   doxygen.......................generate the doxygen documentation
#
# Provided macros/functions:
#   ---
#
# When neither DOXYGEN_OUTPUT_DIR nor DEFAULT_DOXYGEN_OUTPUT_DIR is set then
# "${PROJECT_BINARY_DIR}/_doxygen" is set as fallback directory.

# the master project is responsible for the documentation target
if(SUB_PROJECT)
  return()
endif()

# search for doxygen and skip doxygen support if it could not been found
find_package(Doxygen)
if(NOT DOXYGEN_FOUND)
  info_msg("Doxygen not found. Documentation can not be generated!")
  return()
endif()

# check if the configuration file exists and error out if not
if(NOT EXISTS "${DOXYGEN_CONFIG_IN_FILE}")
  info_msg("Doxygen configuration file (${DOXYGEN_CONFIG_IN_FILE}) not found.")
  info_msg("Documentation target will not be added!")
  return()
endif()

# define a output directory if nothing has been specified
if(NOT DEFAULT_DOXYGEN_OUTPUT_DIR)
  set(DEFAULT_DOXYGEN_OUTPUT_DIR "${PROJECT_BINARY_DIR}/_doxygen")
endif()

# Export the used output directory to the cache to enable modification
cache_with_default(DOXYGEN_OUTPUT_DIR
                   "${DEFAULT_DOXYGEN_OUTPUT_DIR}"
                   "PATH"
                   "Output directory for the generated doxygen documentation."
)
mark_as_advanced(DOXYGEN_OUTPUT_DIR)

# add the output directory to the clean target of the project
set_property(
  DIRECTORY "${PROJECT_SOURCE_DIR}"
  APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${DOXYGEN_OUTPUT_DIR}"
)

# Check if the tools for qch file generation are available. The resulting file
# is located next to the doxygen directory as named "${CMAKE_PROJECT_NAME}.qch".
find_program(QCH_EXECUTABLE qhelpgenerator)
mark_as_advanced(QCH_EXECUTABLE)
if(QCH_EXECUTABLE)
    set(CMAKE_QCH_ENABLE "YES")
    set(CMAKE_QCH_OUTPUT_FILE "${DOXYGEN_OUTPUT_DIR}/../${CMAKE_PROJECT_NAME}.qch")
    set(CMAKE_QCH_LOCATION "${QCH_EXECUTABLE}")
endif()

# configure the doxygen file
configure_file(
  "${DOXYGEN_CONFIG_IN_FILE}"
  "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.doxygen"
  IMMEDIATE @ONLY
)

# add the doxygen target
add_custom_target(
  doxygen
  "${DOXYGEN_EXECUTABLE}"
  "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.doxygen"
)
