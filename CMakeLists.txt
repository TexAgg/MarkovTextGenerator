CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
project(Markov)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11")

# Set bin and lib dirrectories.
# http://stackoverflow.com/a/6595001/5415895
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include_directories(${PROJECT_SOURCE_DIR})

# Set a global variable declaring the source directory.
set(MARKOV_DIR ${PROJECT_SOURCE_DIR}/Markov)
# Set a global variable for the web directory.
set(WEB_DIR ${PROJECT_SOURCE_DIR}/web)
set(TEXT_DIR ${PROJECT_SOURCE_DIR}/text)

#############################
# Include Boost and Python. #
#############################

FIND_PACKAGE(PythonInterp)
FIND_PACKAGE(PythonLibs)
find_package(Boost 1.58 REQUIRED python)
include_directories(${Boost_INCLUDE_DIRS} ${PYTHON_INCLUDE_DIRS})

###########
# cpprest #
###########

# Include cpprest.
# If you have cpprest installed and built somewhere else, then change these lines.
# http://stackoverflow.com/a/1635999/5415895
include_directories("/usr/local/lib/casablanca/Release/include")
link_directories("/usr/local/lib/casablanca/Release/build.release/Binaries")

include_directories(/usr/local/lib/casablanca)

######################
# Add subdirectories #
######################

add_subdirectory(${MARKOV_DIR})
add_subdirectory(${WEB_DIR}/modules)