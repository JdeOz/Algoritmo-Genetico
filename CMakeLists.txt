cmake_minimum_required(VERSION 3.21)
project(AlgoritmoGenetico)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories($(CMAKE_CURRENT_SOURCE_DIR)/src)
add_executable(AlgoritmoGenetico src/main.cpp)
