#include "Mammal.h"
#include <iostream>

Mammal::Mammal(const std::string& name, int age, const std::string& diet)
    : Animal(name, age, diet) {}

void Mammal::makeSound() const {
    std::cout << name << " says: Roar!" << std::endl;
}

void Mammal::move() const {
    std::cout << name << " is walking." << std::endl;
}