#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <string>
#include <vector>

class Menu {
public:
    void displayMainMenu() const;
    void run();

private:
    void addAnimal();
    void viewHabitat();
    void viewFeedingSchedule();

    bool exitProgram = false;
};

#endif // MENU_H
