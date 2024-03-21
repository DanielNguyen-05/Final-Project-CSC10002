#include <iostream>
#include <string>

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
    std::cout   << "\t\t\t\tMAIN MENU\n"
                << "Hello " << username << "\n"
                << "1. Create a new school year\n"// go to 4.1
                << "2. Edit an existed school year\n"  // go to 4.2
                << "3. Change password\n"  // go to 4.3
                << "4. View your profile\n"  // go to 4.4
                << "0. Log out\n\n"

                << "Your choice: ";
}

