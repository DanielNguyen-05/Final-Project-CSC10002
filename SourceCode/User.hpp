#pragma once
#include "header.hpp"
#include <string>

struct Users{

    std::string Username = "";
    std::string Password = "";

    bool isStaff = false;

    bool isStudent(std::string username, std::string password);
    bool isAcademicStaff(std::string username, std::string password);

    bool login();
    void viewProfileInfo();
    void changePassword();
    void logout();
    
};
