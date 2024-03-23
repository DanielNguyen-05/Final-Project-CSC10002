#pragma once
#include "header.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include<stdlib.h>

struct Users{

    /*??data*/
    std::string Username = "";
    std::string Password = "";

    bool isStaff = false;

    inline bool isStudent(std::string username, std::string password);
    inline bool isAcademicStaff(std::string username, std::string password);

    inline bool login();
    inline void viewProfileInfo();
    inline bool changePassword();
    inline void logout();
};
