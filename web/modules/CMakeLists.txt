
##################
# Python modules #
##################

# Create the markovp python module.
PYTHON_ADD_MODULE(markovp ${WEB_DIR}/modules/markovp.cpp)

# Link it with the required libraries.
target_link_libraries(markovp Markov Utility ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
add_custom_command(
  TARGET markovp
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:markovp> ${WEB_DIR}
)

# Create the buzzfeed python module.
PYTHON_ADD_MODULE(buzzfeed ${WEB_DIR}/modules/buzzfeed.cpp)

# ALWAYS link with ${Boost_LIBRARIES} and ${PYTHON_LIBRARIES} when wrapping C++ for Python.
target_link_libraries(buzzfeed cpprest ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})
add_custom_command(
  TARGET buzzfeed
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:buzzfeed> ${WEB_DIR}
)