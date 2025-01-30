#include "gtest/gtest.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include <sstream>

TEST(MammalTest, MakeSound) {
    Mammal mammal("Elephant", 10, "Herbivore");
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
    mammal.makeSound();
    std::cout.rdbuf(oldCoutBuf);
    EXPECT_EQ(oss.str(), "Elephant says: Roar!\n");
}

TEST(BirdTest, MakeSound) {
    Bird bird("Parrot", 2, "Omnivore");
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
    bird.makeSound();
    std::cout.rdbuf(oldCoutBuf);
    EXPECT_EQ(oss.str(), "Parrot chirps: Tweet-tweet!\n");
}

TEST(ReptileTest, MakeSound) {
    Reptile reptile("Snake", 5, "Carnivore");
    std::ostringstream oss;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(oss.rdbuf());
    reptile.makeSound();
    std::cout.rdbuf(oldCoutBuf);
    EXPECT_EQ(oss.str(), "Snake hisses: Ssssss!\n");
}

TEST(AnimalTests, PolymorphismTest) {
    Mammal lion("Lion", 5, "Carnivore");
    Bird parrot("Parrot", 2, "Omnivore");

    lion.makeSound();  // Expected: "Roar!"
    lion.move();       // Expected: "Moves on land."
    
    parrot.makeSound(); // Expected: "Chirp!"
    parrot.move();      // Expected: "Flies in the sky."
}