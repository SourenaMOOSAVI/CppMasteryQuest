# Add executable for all tests
add_executable(zoo_tests
    ${PROJECT_SOURCE_DIR}/tests/AnimalTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/HabitatTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/VisitorTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/AnimalFactoryTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/MenuTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/ZooSettingsTests.cpp
    ${PROJECT_SOURCE_DIR}/tests/FeedingScheduleTests.cpp
)

# Link test executable with required libraries
target_link_libraries(zoo_tests
    zoo_management   # Link the main library
    gtest            # Link GoogleTest
    gmock            # Link GoogleMock
    gtest_main       # Link the main GTest entry point
)

# Enable testing
enable_testing()

# Add individual test commands for clarity
add_test(NAME AnimalTests COMMAND zoo_tests --gtest_filter=AnimalTests.*)
add_test(NAME HabitatTests COMMAND zoo_tests --gtest_filter=HabitatTests.*)
add_test(NAME VisitorTests COMMAND zoo_tests --gtest_filter=VisitorTests.*)
add_test(NAME AnimalFactoryTests COMMAND zoo_tests --gtest_filter=AnimalFactoryTests.*)
add_test(NAME MenuTests COMMAND zoo_tests --gtest_filter=MenuTests.*)
add_test(NAME ZooSettingsTests COMMAND zoo_tests --gtest_filter=ZooSettingsTests.*)
add_test(NAME FeedingScheduleTests COMMAND zoo_tests --gtest_filter=FeedingScheduleTests.*)