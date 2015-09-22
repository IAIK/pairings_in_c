# This script discovers the Doxygen binary and creates a doxygen target when
# binary and configuration file could be found.
#
# Processed variables:
#   DOXYGEN_CONFIG_IN_FILE................(mandatory) path to the config file
#   DEFAULT_DOXYGEN_OUTPUT_DIR............custom output directory for the documentation
#   SUB_PROJECT...........................doxygen support is disabled for sub projects
#
# Provided targets:
#   doxygen...............generate the doxygen documentation of the project
#
# Provided macros/functions:
#   ---

# As feedback if the target is available the DOXYGEN_GENERATION_POSSIBLE variable
# is set.
#

# the master project is responsible for the documentation target
IF(SUB_PROJECT)
  RETURN()
ENDIF()

FIND_PACKAGE(Doxygen)
SET(DOXYFILE_FOUND false)
SET(DOXYGEN_GENERATION_POSSIBLE 0)

IF(EXISTS ${DOXYGEN_CONFIG_IN_FILE} )
  SET(DOXYFILE_FOUND true)
ENDIF(EXISTS ${DOXYGEN_CONFIG_IN_FILE} )

FIND_PROGRAM(QHC_EXECUTABLE qhelpgenerator)
MARK_AS_ADVANCED(QHC_EXECUTABLE)

IF( DOXYGEN_FOUND )
  IF( DOXYFILE_FOUND )
    SET( DOXYGEN_GENERATION_POSSIBLE 1)

    # configure default output directory
    IF(NOT DEFAULT_DOXYGEN_OUTPUT_DIR)
      SET(DEFAULT_DOXYGEN_OUTPUT_DIR "${PROJECT_BINARY_DIR}/_doxygen")
    ENDIF(NOT DEFAULT_DOXYGEN_OUTPUT_DIR)

    IF(NOT DOXYGEN_OUTPUT_DIR AND DEFAULT_DOXYGEN_OUTPUT_DIR)
      SET(DOXYGEN_OUTPUT_DIR "${DEFAULT_DOXYGEN_OUTPUT_DIR}"
        CACHE PATH "Output directory for the generated doxygen documentation.")
    ENDIF(NOT DOXYGEN_OUTPUT_DIR AND DEFAULT_DOXYGEN_OUTPUT_DIR)

    SET_PROPERTY(
      DIRECTORY "${PROJECT_SOURCE_DIR}"
      APPEND
      PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${DOXYGEN_OUTPUT_DIR}"
    )

    IF(QHC_EXECUTABLE)
        SET(CMAKE_QHC_ENABLE "YES")
        SET(CMAKE_QHC_OUTPUT_FILE "${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME}.qch")
        SET(CMAKE_QHC_LOCATION "${QHC_EXECUTABLE}")
    ENDIF(QHC_EXECUTABLE)

    CONFIGURE_FILE(
      "${DOXYGEN_CONFIG_IN_FILE}"
      "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.doxygen"
      IMMEDIATE @ONLY)


    # Add target
    ADD_CUSTOM_TARGET(doxygen ${DOXYGEN_EXECUTABLE} "${PROJECT_BINARY_DIR}/${CMAKE_PROJECT_NAME}.doxygen")

  ELSE( DOXYFILE_FOUND )
    INFO_MSG("Doxygen configuration file (${DOXYGEN_CONFIG_IN_FILE}) not found." )
    INFO_MSG("Documentation target will not be added!" )
  ENDIF( DOXYFILE_FOUND )
ELSE( DOXYGEN_FOUND )
  INFO_MSG("Doxygen not found. Documentation can not be generated!" )
ENDIF( DOXYGEN_FOUND )
