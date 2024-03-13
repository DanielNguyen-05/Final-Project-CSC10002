#include "User.hpp"
#include "header.hpp"
#include <iostream>
#include <string>
#include "LinkedList.h"


bool Users::isUser(std::string username, std::string pass)
{

    std::cerr << "Wrong username or password. Please try again!\n";
    return false;
}

void Users::login()
{
    std::string username = "", password = "";

    do{
        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;
    } while (!isUser(username, password));
    
    acc -> username = username;
    acc -> password = password;
    std::cout << "Login successfully! Welcome back " << acc.username << "\n";
}

void Users::viewProfileInfo()
{
    if(isStaff)
}

void Users::changePassword()
{
    std::string password = "", new_password = "", re_new_password;

    do{
        std::cout << "Current password: ";
        std::cin >> password;

        std::cout << "New password: ";
        std::cin >> new_password;
        
        std::cout << "Re-type new password: ";
        std::cin >> re_new_password;

        if(password != acc -> password) 
        {
            std::cerr << "Wrong password. Please try again!\n"; 
            continue;
        }
        
        if(new_password != re_new_password)
        {
            std::cerr << "Error: Passwords do not match. Please try again!\n";
            continue;
        }
    } while (new_password != re_new_password);
    
    std::cout << "Change password successfully!\n";
}

void Users::logout()
{
    acc = nullptr;

    std::cout << "Log out successfully!";
}