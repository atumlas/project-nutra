cmake_minimum_required(VERSION 3.25)
project(Project-Nutra VERSION 0.1.0 LANGUAGES CXX C)

# CMake variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# CMake Macros
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(AddDependency)
include(AddNutra)

add_subdirectory(src)