# This is a minimalistic example of how to create build files for an application 
# making use of the esmini shared library.
# 
# Make sure that the headerfile esminiLib.hpp and library esminiLib 
# (exact filename depending on platform) is available, either in this folder or in 
# the original location (relative this folder).

cmake_minimum_required (VERSION 3.5.0 FATAL_ERROR)

set(TARGET leet_03)
set(CMAKE_BUILD_TYPE "Debug")

project(${TARGET})
include_directories(
  src/
)
add_executable(${TARGET}
  src/${TARGET}.cpp
)
target_link_libraries(${TARGET}
)

