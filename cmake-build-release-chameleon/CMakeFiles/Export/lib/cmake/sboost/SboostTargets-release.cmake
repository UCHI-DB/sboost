#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELEASE".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sboost_static" for configuration "RELEASE"
set_property(TARGET sboost_static APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sboost_static PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsboost.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS sboost_static )
list(APPEND _IMPORT_CHECK_FILES_FOR_sboost_static "${_IMPORT_PREFIX}/lib/libsboost.a" )

# Import target "sboost_shared" for configuration "RELEASE"
set_property(TARGET sboost_shared APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(sboost_shared PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libsboost.so.1.0.0"
  IMPORTED_SONAME_RELEASE "libsboost.so.1.0.0"
  )

list(APPEND _IMPORT_CHECK_TARGETS sboost_shared )
list(APPEND _IMPORT_CHECK_FILES_FOR_sboost_shared "${_IMPORT_PREFIX}/lib/libsboost.so.1.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
