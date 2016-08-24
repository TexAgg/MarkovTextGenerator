# CMakeLists.txt for the Markov subdirectory.

#############
# Libraries #
#############

# These libraries must be shared, in order to be used by the python module.
add_library(Utility SHARED ${FILES_DIR}/Utility.cpp ${FILES_DIR}/Utility.h)
add_library(Markov SHARED ${FILES_DIR}/Markov.cpp ${FILES_DIR}/Markov.h)

###################
# Main executable #
###################

add_executable(Main ${FILES_DIR}/Main.cpp)
# Copy the text files over to the build directory.
add_custom_command(
  TARGET Main
  PRE_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEXT_DIR} $<TARGET_FILE_DIR:Main>
)

# Link the libraries with the main executable.
target_link_libraries(Main Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

#################
# Python module #
#################

# Create the python module.
PYTHON_ADD_MODULE(markovp ${FILES_DIR}/python.cpp)

# Link it with the required libraries.
target_link_libraries(markovp Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

###################
# Test executable #
###################

add_executable(Test ${FILES_DIR}/Test.cpp)
target_link_libraries(Test Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

#############################################
# Copy necessary libraries to web directory #
#############################################

# http://stackoverflow.com/questions/9994045/copy-target-file-to-another-location-in-a-post-build-step-in-cmake
add_custom_command(
  TARGET Markov
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Markov> ${WEB_DIR}
)
add_custom_command(
  TARGET Utility
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Utility> ${WEB_DIR}
)
add_custom_command(
  TARGET markovp
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:markovp> ${WEB_DIR}
)