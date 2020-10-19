project(input_test)

set(CMAKE_CXX_FLAGS -std=c++11)
set(CMAKE_CXX_STANDARD 11)

add_executable(input_test main.cc OutputMaker.cc OutputMaker.h InputTest.h TestMode.h InputTest.cc)