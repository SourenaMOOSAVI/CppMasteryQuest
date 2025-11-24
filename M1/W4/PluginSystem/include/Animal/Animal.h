#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal
{
    protected:
        std::string name;
        std::string diet;
        int age;
    
    public:
        // Constructor
        Animal(const std::string& name, int age, const std::string& diet);

        // Virtual destructor
        virtual ~Animal() = default;

        // Getters
        std::string getName() const;
        std::string getDiet() const;
        int getAge() const;

        // Virtual methods
        virtual void makeSound() const = 0; // Pure virtual method
        virtual void move() const = 0;      // Pure virtual method

        // Feed method
        void feed() const;

};

#endif // ANIMAL_H