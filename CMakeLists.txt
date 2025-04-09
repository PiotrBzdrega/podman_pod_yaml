cmake_minimum_required(VERSION 3.10.0)
project(hello_world VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Force static linking
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(hello_world main.cpp)

