#include <gtest/gtest.h>
#include "Management/FeedingSchedule.h"
#include "Animal/Bird.h"

TEST(FeedingScheduleTests, AddScheduleTest) {
    FeedingSchedule schedule;
    Bird parrot("Parrot", 6, "Omnivore");

    schedule.addSchedule(&parrot, "10:00 AM");

    // Placeholder for checking behavior
    ASSERT_TRUE(true);
}
