# This script determines the git revision of the project if possible.
# Additionally, the version numbers are processed to build up a full version
# string.
#
# Processed variables:
#   RELEASE....................extend the PATCH version with the specified
#                              string instead of the git revision
#   VERSION_MAJOR..............the major version number
#   VERSION_MINOR..............the minor version number
#   VERSION_PATCH..............the patch level
#
# Provided variables:
#   GIT_INITIALIZED............true if the git revision of the project could
#                              be determined
#   GIT_MODIFIED...............true if the working directory has been modified
#   GIT_SHORT_HASH.............the short hash of the repository
#   GIT_COMBINED_SHORT_HASH....GIT_SHORT_HASH with an "M" prefix
#                              when GIT_MODIFIED == true
#
#   VERSION_PATCH_EXT..........VERSION_PATCH(-gitGIT_COMBINED_SHORT_HASH|RELEASE)
#   VERSION_FULL...............VERSION_MAJOR.VERSION_MINOR.VERSION_PATCH_EXT
#

find_program(GIT_COMMAND NAMES git)
mark_as_advanced(GIT_COMMAND)

set(GIT_INITIALIZED "OFF")
set(GIT_MODIFIED "OFF")
set(GIT_SHORT_HASH  "")
set(GIT_COMBINED_SHORT_HASH "")

if(GIT_COMMAND)
  SET(ENV{LC_ALL} "C")
  # fetch the hash from the last commit
  execute_process(COMMAND "${GIT_COMMAND}" "log" "--pretty=format:%h" "-1"
                  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                  OUTPUT_VARIABLE GIT_SHORT_HASH
  )

  set(GIT_COMBINED_SHORT_HASH "${GIT_SHORT_HASH}")

  # check if the source dir is a repository at all
  STRING(COMPARE NOTEQUAL "" "${GIT_SHORT_HASH}" GIT_INITIALIZED)
  if(GIT_INITIALIZED)
    execute_process(COMMAND "${GIT_COMMAND}" "status"
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    OUTPUT_VARIABLE GIT_MODIFIED
    )

    STRING(REGEX MATCH "modified:" GIT_MODIFIED "${GIT_MODIFIED}")
    if(GIT_MODIFIED)
      info_msg("GIT workspace has been modified")
      set(GIT_COMBINED_SHORT_HASH "M${GIT_SHORT_HASH}")
    endif()
  else()
    info_msg("GIT hash couldn't be determined")
  endif()
endif()

set(VERSION_PATCH_EXT "${VERSION_PATCH}-git${GIT_COMBINED_SHORT_HASH}")
if(DEFINED RELEASE)
  set(VERSION_PATCH_EXT "${VERSION_PATCH}${RELEASE}")
endif()

set(VERSION_FULL      "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH_EXT}")

set(CPACK_PACKAGE_VERSION_MAJOR "${VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${VERSION_PATCH_EXT}")
