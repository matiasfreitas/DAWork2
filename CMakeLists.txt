cmake_minimum_required(VERSION 3.21)
project(DAWork2)

set(CMAKE_CXX_STANDARD 14)

add_executable(DAWork2 Source/main.cpp Source/Reader.cpp Source/Reader.h Source/Travel.cpp
        Source/Travel.h Source/Manager.cpp Source/Manager.h Source/Spots.cpp Source/Spots.h Source/pathCalculator.cpp Source/pathCalculator.h)
