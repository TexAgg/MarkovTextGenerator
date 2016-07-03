
CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)
project(Markov)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
  Main.cpp
  Utility.h
  Markov.cpp
  Markov.h)

add_executable(Markov ${SOURCE_FILES})