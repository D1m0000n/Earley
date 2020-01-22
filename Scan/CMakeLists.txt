cmake_minimum_required(VERSION 3.15)

project(Earley)

set(SOURCE_LIB Scan.cpp)

add_library(Scan STATIC ${SOURCE_LIB})
