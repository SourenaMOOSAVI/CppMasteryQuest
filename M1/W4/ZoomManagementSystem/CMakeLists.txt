cmake_minimum_required(VERSION 3.10)
project(ZooManagementSystem)

set(CMAKE_CXX_STANDARD 17)

# Include directories for all headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for source and tests
add_subdirectory(src)
add_subdirectory(tests)
