#include "Visitor.h"
#include <gtest/gtest.h>

TEST(VisitorTests, AddVisitedHabitat) {
    Visitor visitor("John", 30);
    visitor.visitHabitat("Savannah");
    visitor.visitHabitat("Rainforest");

    const auto& habitats = visitor.getVisitedHabitats();
    ASSERT_EQ(habitats.size(), 2);
    EXPECT_EQ(habitats[0], "Savannah");
    EXPECT_EQ(habitats[1], "Rainforest");
}

TEST(VisitorTests, VisitorNameAndAge) {
    Visitor visitor("Alice", 25);
    EXPECT_EQ(visitor.getName(), "Alice");
    EXPECT_EQ(visitor.getAge(), 25);
}