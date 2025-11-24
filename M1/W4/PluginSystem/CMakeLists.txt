cmake_minimum_required(VERSION 3.16)
project(PluginSystem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Make include directory available
include_directories(${CMAKE_SOURCE_DIR}/include)

# Build the plugin manager CLI
add_executable(plugin_cli
    src/main.cpp
    src/PluginManager.cpp
)

target_compile_options(plugin_cli PRIVATE -Wall -Wextra -Wpedantic)
target_include_directories(plugin_cli PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Build plugins
add_subdirectory(plugins)

# Tests
enable_testing()
add_subdirectory(tests)
