#ifndef FEEDINGSCHEDULE_H
#define FEEDINGSCHEDULE_H

#include <map>
#include <string>
#include "Animal/Animal.h"

class FeedingSchedule {
private:
    std::map<Animal*, std::string> schedule;

public:
    void addSchedule(Animal* animal, const std::string& time);
    void displaySchedule() const;
};

#endif // FEEDINGSCHEDULE_H