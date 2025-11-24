#include "Reptile.h"
#include <iostream>

Reptile::Reptile(const std::string& name, int age, const std::string& diet)
    : Animal(name, age, diet) {}

void Reptile::makeSound() const {
    std::cout << name << " hisses: Ssssss!" << std::endl;
}

void Reptile::move() const {
    std::cout << name << " is crawling." << std::endl;
}