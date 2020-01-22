cmake_minimum_required(VERSION 3.15)
project(Earley)

set(CMAKE_CXX_STANDARD 17)

add_executable(Earley main.cpp)

include_directories(Grammar)
include_directories(Scan)
include_directories(Predict)
include_directories(Complete)
include_directories(Algo)

add_subdirectory(Grammar)
add_subdirectory(Complete)
add_subdirectory(Predict)
add_subdirectory(Scan)
add_subdirectory(Algo)