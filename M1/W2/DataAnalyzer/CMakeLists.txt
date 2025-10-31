cmake_minimum_required(VERSION 3.16)
project(DataAnalyzer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Allow building in-tree for simplicity if needed
if(NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
endif()

# ---------------------
# Project targets
# ---------------------
add_executable(data_analyzer
    main.cpp
    src/Analyzer.cpp
    src/utils.cpp
)

target_include_directories(data_analyzer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(data_analyzer PRIVATE -Wall -Wextra -Wpedantic)

# ---------------------
# Tests (Catch2)
# ---------------------
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0 # pick a stable-ish tag; change if you prefer another
)
FetchContent_MakeAvailable(catch2)

enable_testing()

add_executable(tests
    tests/test_utils.cpp
    tests/test_analyzer.cpp
    src/utils.cpp        # include implementation for test linking convenience
    src/Analyzer.cpp
)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME unit_tests COMMAND tests)

