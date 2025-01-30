cmake_minimum_required(VERSION 3.10)

project(CustomSmartPointer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -g")

# Include directories
include_directories(include)

# Add executables for tests
add_executable(SharedPtrTests tests/SharedPtrTests.cpp)
add_executable(MemoryPoolTests tests/MemoryPoolTests.cpp)
add_executable(WeakPtrTests tests/WeakPtrTests.cpp)
