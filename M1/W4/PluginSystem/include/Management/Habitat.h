#ifndef HABITAT_H
#define HABITAT_H

#include <string>
#include <vector>
#include <memory>
#include "Animal.h"

class Habitat {
private:
    std::string type;
    std::vector<std::shared_ptr<Animal>> residents;

public:
    explicit Habitat(const std::string& habitatType);

    void addAnimal(const std::shared_ptr<Animal>& animal);
    void showResidents() const;

    // Optional getter for type
    const std::string& getType() const;
};

#endif // HABITAT_H
