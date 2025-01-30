#include "Bird.h"
#include <iostream>

Bird::Bird(const std::string& name, int age, const std::string& diet)
    : Animal(name, age, diet) {}

void Bird::makeSound() const {
    std::cout << name << " chirps: Tweet-tweet!" << std::endl;
}

void Bird::move() const {
    std::cout << name << " is flying." << std::endl;
}