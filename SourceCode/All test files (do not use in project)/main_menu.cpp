#include "user.hpp"
#include <iostream>

void mainMenuOfStaff(std::string username) {
    std::cout << "\t\t\t MAIN MENU OF STAFF" << "\n\n";
    std::cout << "\t Welcome Mr(s). " << username << " to the main menu for Staff" << "\n";
    std::cout << "\t\t What would you like to do?" << "\n";
    std::cout << "\t 0. Log out" << "\n";
    std::cout << "\t 1. Create a new school year" << "\n";
    std::cout << "\t 2. Edit an existed school year" << "\n";
    std::cout << "\t 3. Change password" << "\n";
    std::cout << "\t 4. View your profile information" << "\n";
    std::cout << "\t 5. Log out" << "\n\n";
    std::cout << "\t Please input your choice: ";
}

void mainMenuOfStudent(std::string username) {
    std::cout << "\t\t\t MAIN MENU OF STUDENT" << "\n\n";
    std::cout << "\t Welcome Mr(s). " << username << " to the main menu for Student" << "\n";
    std::cout << "\t\t What would you like to do?" << "\n";
    std::cout << "\t 0. Log out" << "\n";
    std::cout << "\t 1. View your profile information" << "\n";
    std::cout << "\t 2. View your points" << "\n";
    std::cout << "\t 3. Change password" << "\n\n";
    std::cout << "\t Please input your choice: ";
}

