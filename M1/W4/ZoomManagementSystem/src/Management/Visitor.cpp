#include "Visitor.h"
#include <iostream>

Visitor::Visitor(const std::string& name, int age) : name(name), age(age) {}

void Visitor::visitHabitat(const std::string& habitat) {
    visitedHabitats.push_back(habitat);
}

void Visitor::displayVisitedHabitats() const {
    std::cout << "Habitats visited by " << name << ":\n";
    for (const auto& habitat : visitedHabitats) {
        std::cout << "- " << habitat << "\n";
    }
}

std::vector<std::string> Visitor::getVisitedHabitats() const {
    return visitedHabitats;
}

std::string Visitor::getName() const {
    return name;
}

int Visitor::getAge() const {
    return age;
}