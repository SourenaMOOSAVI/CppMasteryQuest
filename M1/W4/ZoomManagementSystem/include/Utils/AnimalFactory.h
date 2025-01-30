#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "Animal.h"
#include "Mammal.h"
#include "Bird.h"
#include "Reptile.h"
#include <memory>
#include <string>

class AnimalFactory {
public:
    static std::shared_ptr<Animal> createAnimal(const std::string& type, const std::string& name, int age, const std::string& diet);
};

#endif // ANIMAL_FACTORY_H