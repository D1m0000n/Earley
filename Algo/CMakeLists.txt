cmake_minimum_required(VERSION 3.15)

project(Earley)

set(SOURCE_LIB Algo.cpp)

add_library(Algo STATIC ${SOURCE_LIB})