#pragma once
#include "header.hpp"
#include "AccountList.hpp"
#include <string>

struct Users{


    AccountList *acc = nullptr;
    bool isStaff = false;

    bool isUser(std::string username, std::string pass);
    void login();
    void viewProfileInfo();
    void changePassword();
    void logout();
    
};
