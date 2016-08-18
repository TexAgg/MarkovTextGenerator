CMAKE_MINIMUM_REQUIRED(VERSION 2.6.0)
project(Markov)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(FILES_DIR ${PROJECT_SOURCE_DIR}/Markov)

# Include Boost.
find_package(Boost 1.58 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

add_library(Utility ${FILES_DIR}/Utility.cpp ${FILES_DIR}/Utility.h)
add_library(Markov ${FILES_DIR}/Markov.cpp ${FILES_DIR}/Markov.h)

add_executable(Main ${FILES_DIR}/Main.cpp)
# Copy the text files over to the build directory.
add_custom_command(
  TARGET Main
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${FILES_DIR}/text $<TARGET_FILE_DIR:Main>
)

target_link_libraries(Main Markov Utility ${Boost_LIBRARIES})