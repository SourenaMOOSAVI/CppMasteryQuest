#ifndef REPTILE_H
#define REPTILE_H

#include "Animal.h"

class Reptile : public Animal {
public:
    Reptile(const std::string& name, int age, const std::string& diet);

    void makeSound() const override;
    void move() const override;
};

#endif // REPTILE_H