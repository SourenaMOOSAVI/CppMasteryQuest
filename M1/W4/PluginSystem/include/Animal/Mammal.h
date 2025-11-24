#ifndef MAMMAL_H
#define MAMMAL_H

#include "Animal.h"

class Mammal : public Animal {
public:
    Mammal(const std::string& name, int age, const std::string& diet);

    void makeSound() const override;
    void move() const override;
};

#endif // MAMMAL_H