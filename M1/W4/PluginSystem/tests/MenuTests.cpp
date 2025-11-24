#include "Menu.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(MenuTests, DisplayMainMenu) {
    testing::internal::CaptureStdout();

    Menu menu;
    menu.displayMainMenu();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_THAT(output, testing::HasSubstr("==== Zoo Management System ===="));
    EXPECT_THAT(output, testing::HasSubstr("1. Add Animal to Habitat"));
    EXPECT_THAT(output, testing::HasSubstr("2. View Habitat Details"));
    EXPECT_THAT(output, testing::HasSubstr("3. View Feeding Schedule"));
    EXPECT_THAT(output, testing::HasSubstr("4. Exit"));
    EXPECT_THAT(output, testing::HasSubstr("Enter your choice: "));
}