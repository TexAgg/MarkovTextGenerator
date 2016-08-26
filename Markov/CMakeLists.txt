# CMakeLists.txt for the Markov subdirectory.

#############
# Libraries #
#############

# These libraries must be shared, in order to be used by the python module.
add_library(Utility SHARED ${MARKOV_DIR}/Utility.cpp ${MARKOV_DIR}/Utility.h)
add_library(Markov SHARED ${MARKOV_DIR}/Markov.cpp ${MARKOV_DIR}/Markov.h)

###################
# Main executable #
###################

add_executable(Main ${MARKOV_DIR}/Main.cpp)
# Copy the text files over to the build directory.
add_custom_command(
  TARGET Main
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEXT_DIR} $<TARGET_FILE_DIR:Main>
)

# Link the libraries with the main executable.
target_link_libraries(Main Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

###################
# Test executable #
###################

add_executable(Test ${MARKOV_DIR}/Test.cpp)
target_link_libraries(Test Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
