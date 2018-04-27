cmake_minimum_required (VERSION 3.2 FATAL_ERROR)

# must be done before calling project()
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build type, Debug or Release" FORCE)
endif()

# configure the installation directory (artifact)
set(CMAKE_INSTALL_PREFIX "install" CACHE STRING "Where to install the library files (artifact)" FORCE)
#SET(CMAKE_INSTALL_PREFIX "install-package")

# WARNING: project() must be called AFTER the above lines (otherwise they will be ignored)
project(WESTGARD-SSM)

# adjust compilation flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Werror")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 3rd party libs
include(${CMAKE_SOURCE_DIR}/third_parties/Westgardlib-SSM.cmake)

# source code of the project
add_subdirectory(src)

# declare unit tests
enable_testing()
# calling testcase

add_test(NAME AllTest COMMAND Test --gtest_output=xml:gtest_report.xml)
