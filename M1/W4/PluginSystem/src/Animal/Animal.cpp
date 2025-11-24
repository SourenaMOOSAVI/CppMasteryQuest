#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& name, int age, const std::string& diet)
    : name(name), age(age), diet(diet) {}

std::string Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

std::string Animal::getDiet() const {
    return diet;
}

void Animal::feed() const {
    std::cout << name << " is eating " << diet << "." << std::endl;
}
