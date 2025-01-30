#include "AnimalFactory.h"

std::shared_ptr<Animal> AnimalFactory::createAnimal(const std::string& type, const std::string& name, int age, const std::string& diet) {
    if (type == "Mammal") {
        return std::make_shared<Mammal>(name, age, diet);
    } else if (type == "Bird") {
        return std::make_shared<Bird>(name, age, diet);
    } else if (type == "Reptile") {
        return std::make_shared<Reptile>(name, age, diet);
    }
    return nullptr;
}