cmake_minimum_required(VERSION 3.15)

project(Earley)

set(SOURCE_LIB Grammar.cpp)

add_library(Grammar STATIC ${SOURCE_LIB})