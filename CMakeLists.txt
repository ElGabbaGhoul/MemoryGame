cmake_minimum_required(VERSION 3.26)
project(MemoryGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(MemoryGame main.cpp
        memorySource.cpp
        memorySource.h
        memoryHelper.cpp
        memoryHelper.h)
