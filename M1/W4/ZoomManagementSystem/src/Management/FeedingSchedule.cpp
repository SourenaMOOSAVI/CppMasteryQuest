#include "FeedingSchedule.h"
#include <iostream>

void FeedingSchedule::addSchedule(Animal* animal, const std::string& time) {
    schedule[animal] = time;
}

void FeedingSchedule::displaySchedule() const {
    std::cout << "Feeding Schedule:\n";
    for (const auto& entry : schedule) {
        std::cout << "- " << entry.first->getName() << " at " << entry.second << "\n";
    }
}
