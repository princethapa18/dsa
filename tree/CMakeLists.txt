cmake_minimum_required(VERSION 3.10)

set(proj_name "Tree")

# set the project name and version
project(${proj_name} VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/utilities/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/utilities/*.h)

# add the executable
add_executable(${proj_name} ${sources} ${headers})

target_include_directories(${proj_name} PUBLIC "${PROJECT_BINARY_DIR}")
