cmake_minimum_required(VERSION 3.16)
project(MemoryMastery LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# include dir
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# library (MemoryPool has .cpp)
add_library(mm_lib
    src/MemoryPool.cpp
    src/MySharedPtr.cpp  # tiny file; main templated implementation lives in header
)

target_include_directories(mm_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(mm_lib PRIVATE -Wall -Wextra -Wpedantic)

# main executable
add_executable(memory_mastery main.cpp)
target_link_libraries(memory_mastery PRIVATE mm_lib)

# ---------------------
# Tests (Catch2 via FetchContent)
# ---------------------
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(catch2)

enable_testing()

add_executable(tests
    tests/test_shared_ptr.cpp
    tests/test_allocator.cpp
    tests/test_pool.cpp
)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (DEFINED catch2_SOURCE_DIR)
    target_include_directories(tests PRIVATE ${catch2_SOURCE_DIR}/single_include)
endif()

target_link_libraries(tests PRIVATE mm_lib Catch2::Catch2WithMain)
target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic)

add_test(NAME unit_tests COMMAND tests)