#ifndef ZOO_SETTINGS_H
#define ZOO_SETTINGS_H

#include <string>

class ZooSettings {
private:
    static ZooSettings* instance;
    std::string openingHours;

    ZooSettings(); // Private constructor

public:
    static ZooSettings* getInstance();

    void setOpeningHours(const std::string& hours);
    std::string getOpeningHours() const;
};

#endif // ZOO_SETTINGS_H