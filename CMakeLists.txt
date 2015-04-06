project(Phoenix CXX C)

cmake_minimum_required(VERSION 2.8.12)

# global variables
set(Phoenix_INCLUDE_DIR
  ${CMAKE_SOURCE_DIR}/include
)

set(Phoenix_TARGET_DIR
  ${CMAKE_BINARY_DIR}/target
)

set(Phoenix_LIB_DIR
  ${CMAKE_BINARY_DIR}/lib
)

set(APPLICATION_NAME ${PROJECT_NAME})

set(APPLICATION_VERSION_MAJOR "0")
set(APPLICATION_VERSION_MINOR "0")
set(APPLICATION_VERSION_PATCH "1")

set(APPLICATION_VERSION	"${APPLICATION_VERSION_MAJOR}.${APPLICATION_VERSION_MINOR}.${APPLICATION_VERSION_PATCH}")

# where to look first for cmake modules, before ${CMAKE_ROOT}/Modules/ isinc
# checked
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

# disallow in-source build
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please create a separate build directory and run 'cmake /path/to/${PROJECT_NAME} [options]' there.")

# Define output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Phoenix_TARGET_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${Phoenix_LIB_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${Phoenix_LIB_DIR})

add_subdirectory(src)
