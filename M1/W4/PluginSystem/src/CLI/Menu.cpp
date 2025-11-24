#include "Menu.h"

void Menu::displayMainMenu() const {
    std::cout << "\n==== Zoo Management System ====\n";
    std::cout << "1. Add Animal to Habitat\n";
    std::cout << "2. View Habitat Details\n";
    std::cout << "3. View Feeding Schedule\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void Menu::run() {
    while (!exitProgram) {
        displayMainMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                addAnimal();
                break;
            case 2:
                viewHabitat();
                break;
            case 3:
                viewFeedingSchedule();
                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                exitProgram = true;
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}

void Menu::addAnimal() {
    std::string habitat, species;
    int age;
    std::cout << "Enter habitat: ";
    std::cin.ignore();
    std::getline(std::cin, habitat);
    std::cout << "Enter species: ";
    std::getline(std::cin, species);
    std::cout << "Enter age: ";
    std::cin >> age;

    // TODO: Link this to your Habitat and Animal logic
    std::cout << "Added " << species << " (age " << age << ") to " << habitat << ".\n";
}

void Menu::viewHabitat() {
    std::string habitat;
    std::cout << "Enter habitat: ";
    std::cin.ignore();
    std::getline(std::cin, habitat);

    // TODO: Fetch and display animals from the specified habitat
    std::cout << "Showing details for habitat: " << habitat << "\n";
}

void Menu::viewFeedingSchedule() {
    // TODO: Display feeding schedules
    std::cout << "Displaying feeding schedules...\n";
}