cmake_minimum_required(VERSION 3.22)
project(
    OOP
    VERSION 1.0
    LANGUAGES CXX
)

add_executable(Output FullOOP.cpp)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_EXE_LINKER_FLAGS "-static")