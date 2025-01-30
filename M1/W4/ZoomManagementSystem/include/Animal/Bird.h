#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"

class Bird : public Animal {
public:
    Bird(const std::string& name, int age, const std::string& diet);

    void makeSound() const override;
    void move() const override;
};

#endif // BIRD_H