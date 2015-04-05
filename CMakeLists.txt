cmake_minimum_required(VERSION 3.1)
project(assignment_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(assignment_3 ${SOURCE_FILES} src/HuffmanTree.cpp src/HuffmanTree.h src/HuffmanNode.cpp src/HuffmanNode.h src/UnitTests.cpp src/catch.hpp src/Utils.cpp src/Utils.h)
