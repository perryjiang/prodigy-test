add_executable("${CMAKE_PROJECT_NAME}" main.cpp)
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE core)
install(TARGETS "${CMAKE_PROJECT_NAME}")
