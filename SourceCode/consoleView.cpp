#include <iostream>
#include <string>
#include "consoleView.h"
#include "User.hpp"

void programInterface()
{
	std::cout   << "\tWhat would you like to do?\n"
                << "1. Log in\n"
                << "0. Stop program\n\n"

                << "Your choice: ";
}

void chooseRole()
{
    std::cout   << "\tAre you a Staff or a Student?\n"
                << "1. Academic Staff\n"
                << "2. Student\n"
                << "0. Stop program\n\n"

                <<"Your choice: ";
}

void loginFail()
{
    std::cout   << "\tWhat would you like to do?\n"
                << "1. Re-login\n"
                << "0. Back to previous page\n\n"
                
                << "Your choice: ";
}

void staffMainMenu(std::string username)
{
    std::cout   << "\t\t\tMAIN MENU\n"
                << "Hello " << username << "\n"
                << "1. Create a new school year\n"
                << "2. Edit an existed school year\n"  
                << "3. Change password\n"  
                << "4. View your profile\n"  
                << "0. Log out\n\n"

                << "Your choice: ";
}
void changePasswordFail() {
    std::cout   << "1. Re-enter it \n"
                << "0. Back to MAIN MENU \n\n"

                << "Your choice: ";
}
void createNewSchoolYear()
{
    std::cout   << "\t\t\tCREATING A NEW SCHOOL YEAR\n";
}

void isNOTcreated()
{
    std::cout    << "The new school year 202x-202x is created successfully!\n"
                << "1. Continue creating a new school year\n"
                << "0. Back to the Main Menu\n\n"

                << "Your choice: ";
}



