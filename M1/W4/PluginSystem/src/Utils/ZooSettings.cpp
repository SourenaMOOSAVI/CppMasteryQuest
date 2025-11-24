#include "ZooSettings.h"

ZooSettings* ZooSettings::instance = nullptr;

ZooSettings::ZooSettings() : openingHours("9:00 AM - 5:00 PM") {}

ZooSettings* ZooSettings::getInstance() {
    if (instance == nullptr) {
        instance = new ZooSettings();
    }
    return instance;
}

void ZooSettings::setOpeningHours(const std::string& hours) {
    openingHours = hours;
}

std::string ZooSettings::getOpeningHours() const {
    return openingHours;
}