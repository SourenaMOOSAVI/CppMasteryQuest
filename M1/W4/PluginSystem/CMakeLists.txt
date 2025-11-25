cmake_minimum_required(VERSION 3.16)
project(PluginSystem)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(plugins/EchoPlugin)
add_subdirectory(plugins/MathPlugin)

# Main application
add_executable(PluginSystem
    src/main.cpp
    src/PluginManager.cpp
)

target_include_directories(PluginSystem PUBLIC include)
target_link_libraries(PluginSystem PRIVATE EchoPlugin MathPlugin)
