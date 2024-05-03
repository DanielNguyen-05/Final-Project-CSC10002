#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "consoleView.hpp"
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

struct Users {
    std::string Username = "";
    std::string Password = "";

    std::string user_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id;

    bool isStaff = false;

    bool isStudent(std::string username, std::string password);
    bool isAcademicStaff(std::string username, std::string password);

    bool login();
    void viewProfileInfo();
    bool changePassword();
    void logout();

    void saveData();
};
