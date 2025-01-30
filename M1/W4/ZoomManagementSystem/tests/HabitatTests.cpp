#include <gtest/gtest.h>
#include "Management/Habitat.h"
#include "Animal/Mammal.h"

TEST(HabitatTests, AddAnimalTest) {
    Habitat habitat("Savannah");

    // Provide the required arguments
    Mammal lion("Lion", 5, "Carnivore");
    auto mammal = std::make_shared<Mammal>("Lion", 5, "Carnivore");
    habitat.addAnimal(mammal);

    testing::internal::CaptureStdout();
    habitat.showResidents();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Lion"), std::string::npos);
}