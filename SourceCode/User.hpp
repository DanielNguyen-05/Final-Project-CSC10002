#pragma once
#include "student.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include<stdlib.h>

struct Users{

    /*??data*/
    std::string Username = "";
    std::string Password = "";

    std::string user_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id;


    bool isStaff = false;

    inline bool isStudent(std::string username, std::string password);
    inline bool isAcademicStaff(std::string username, std::string password);


    inline bool login();
    inline void viewProfileInfo();
    inline bool changePassword();
    inline void logout();
};
