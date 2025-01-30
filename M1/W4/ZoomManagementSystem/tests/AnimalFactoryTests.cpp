#include "AnimalFactory.h"
#include "Mammal.h"
#include "Bird.h"
#include <gtest/gtest.h>

TEST(AnimalFactoryTests, CreateMammal) {
    auto mammal = AnimalFactory::createAnimal("Mammal", "Lion", 5, "Carnivore");

    EXPECT_EQ(mammal->getName(), "Lion");
    EXPECT_EQ(mammal->getAge(), 5);
    EXPECT_EQ(mammal->getDiet(), "Carnivore");
}

TEST(AnimalFactoryTests, CreateBird) {
    auto bird = AnimalFactory::createAnimal("Bird", "Parrot", 2, "Herbivore");

    EXPECT_EQ(bird->getName(), "Parrot");
    EXPECT_EQ(bird->getAge(), 2);
    EXPECT_EQ(bird->getDiet(), "Herbivore");
}