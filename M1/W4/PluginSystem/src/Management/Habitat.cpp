#include "Habitat.h"
#include <iostream>

Habitat::Habitat(const std::string& habitatType) : type(habitatType) {}

void Habitat::addAnimal(const std::shared_ptr<Animal>& animal) {
    residents.push_back(animal);
}

void Habitat::showResidents() const {
    std::cout << "Residents in the " << type << " habitat:\n";
    for (const auto& animal : residents) {
        std::cout << "- " << animal->getName() << "\n";
        animal->makeSound();
        animal->move();
    }
}

const std::string& Habitat::getType() const {
    return type;
}