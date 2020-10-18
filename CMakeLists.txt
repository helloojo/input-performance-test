cmake_minimum_required(VERSION 3.17)
project(input_test)

set(CMAKE_FLAG -std=c++11)
set(CMAKE_CXX_STANDARD 11)

add_executable(input_test main.cc OutputMaker.cc OutputMaker.h InputTest.h TestMode.h InputTest.cc)