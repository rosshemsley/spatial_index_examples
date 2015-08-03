find_path(SPATIALINDEX_INCLUDE_DIR
  NAMES SpatialIndex.h
  HINTS ${SpatialIndex_ROOT_DIR}/include/spatialindex
  PATH_SUFFIXES spatialindex
)

find_library(SPATIALINDEX_LIBRARY
  NAMES spatialindex_i spatialindex
  HINTS ${SpatialIndex_ROOT_DIR}/lib
)

find_library(SPATIALINDEX_LIBRARY_C
  NAMES spatialindex_c
  HINTS ${SpatialIndex_ROOT_DIR}/lib
)

set(SPATIALINDEX_LIBRARIES ${SPATIALINDEX_LIBRARY} ${SPATIALINDEX_LIBRARY_C})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
  SpatialIndex
  DEFAULT_MSG
  SPATIALINDEX_LIBRARIES
  SPATIALINDEX_INCLUDE_DIR)

mark_as_advanced(
  SpatialIndex_ROOT_DIR
  SPATIALINDEX_LIBRARIES
  SPATIALINDEX_INCLUDE_DIR)
