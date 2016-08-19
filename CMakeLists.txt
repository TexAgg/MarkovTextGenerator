CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
project(Markov)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

set(FILES_DIR ${PROJECT_SOURCE_DIR}/Markov)

#############################
# Include Boost and Python. #
#############################

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
find_package(Boost 1.58 REQUIRED python)
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})
#LINK_LIBRARIES(${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_library(Utility SHARED ${FILES_DIR}/Utility.cpp ${FILES_DIR}/Utility.h)
add_library(Markov SHARED ${FILES_DIR}/Markov.cpp ${FILES_DIR}/Markov.h)

add_executable(Main ${FILES_DIR}/Main.cpp)
# Copy the text files over to the build directory.
add_custom_command(
  TARGET Main
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${FILES_DIR}/text $<TARGET_FILE_DIR:Main>
)

target_link_libraries(Main Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

# Create the python module.
PYTHON_ADD_MODULE(markovp ${FILES_DIR}/python.cpp)
# Link it with the required libraries.
target_link_libraries(markovp Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

FILE(COPY ${PROJECT_SOURCE_DIR}/web/main.py DESTINATION ${PROJECT_SOURCE_DIR}/_build)