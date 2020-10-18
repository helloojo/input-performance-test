cmake_minimum_required(VERSION 3.17)
project(input_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(input_test main.cc OutputMaker.cc OutputMaker.h InputTest.h)