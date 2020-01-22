cmake_minimum_required(VERSION 3.15)

project(Earley)

set(SOURCE_LIB Predict.cpp)

add_library(Predict STATIC ${SOURCE_LIB})