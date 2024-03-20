#include "User.hpp"
#include "header.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>


bool Users::isStudent(std::string username, std::string password)
{
    std::string account_file = "Data\\Account\\Student\\" + username;
    std::string account_pass;

    std::ifstream fin;
    fin.open(account_file.c_str());
    if(!fin.is_open())
    {
        std::cerr << "Wrong password or username!";
        return false;
    }

    fin >> account_pass;
    fin.close();

    if(account_pass != password)
    {
        std::cerr << "Wrong password or username!";
        return false;
    }

    Username = username;
    Password = password;

    return true;
}

bool Users::isAcademicStaff(std::string username, std::string password)
{
    std::string account_file = "Data\\Account\\AcademicStaff\\" + username;
    std::string account_pass;

    std::ifstream fin;
    fin.open(account_file.c_str());
    if(!fin.is_open())
    {
        std::cerr << "Wrong password or username!";
        return false;
    }

    fin >> account_pass;
    fin.close();

    if(account_pass != password)
    {
        std::cerr << "Wrong password or username!";
        return false;
    }

    Username = username;
    Password = password;

    return true;
}

bool Users::login()
{
    std::string username;
    std::string password;
    std::cout << "Please input username: ";
    std::cin >> username;

    std::cout << "Please input password: ";
    std::cin >> password;

    if(!isStaff)
    {
        if(isStudent(username, password))
        {
            std::cout << "Log in successfully. Welcome back " << Username << "!\n";
            
            return true;
        }
    }
    else
    {
        if(isAcademicStaff(username, password))
        {
            std::cout << "Log in successfully. Welcome back " << Username << "!\n";
            return true;
        }
    }
    return false;
}


void Users::viewProfileInfo()
{
    if(isStaff)
    {
        std::cerr << "Staff don't have information!";
        return;
    }




}
void Users::changePassword()
{
    if(Password == "")
    {
        std::cerr << "Don't have user's data.";
        return;
    }
    std::string password , new_password , re_new_password;

    std::cout << "Current password: ";
    std::cin >> password;

    std::cout << "New password: ";
    std::cin >> new_password;
    
    std::cout << "Re-type new password: ";
    std::cin >> re_new_password;

    if(password != Password) 
    {
        std::cerr << "Wrong password. Please try again!\n"; 
        return;
    }

    if(new_password.size() < 8)
    {
        std::cerr << "Error: Password must be longer than 8 characters. Please try again!\n";
        return;
    }
    
    if(new_password != re_new_password)
    {
        std::cerr << "Error: Password do not match. Please try again!\n";
        return;
    }


    std::ofstream fout;
    if(isStaff)
        fout.open("Data\\Account\\AcademicStaff\\" + Username);
    else  
        fout.open("Data\\Account\\Student\\" + Username);
    
    if(!fout.is_open()) 
    {
        std::cerr << "Don't have user's data.";
        return;
    }

    fout << new_password;
    fout.close();

    std::cout << "Change password successfully!\n";
}
void Users::logout()
{
    Username = "";
    Password = "";

    std::cout << "Log out successfully!";
}