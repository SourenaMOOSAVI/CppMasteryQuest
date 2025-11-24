#include "ZooSettings.h"
#include <gtest/gtest.h>

TEST(ZooSettingsTests, SingletonBehavior) {
    auto settings1 = ZooSettings::getInstance();
    auto settings2 = ZooSettings::getInstance();

    EXPECT_EQ(settings1, settings2);
}

TEST(ZooSettingsTests, GetAndSetOpeningHours) {
    auto settings = ZooSettings::getInstance();
    settings->setOpeningHours("9 AM - 6 PM");
    EXPECT_EQ(settings->getOpeningHours(), "9 AM - 6 PM");
}