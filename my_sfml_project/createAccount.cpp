#include "createAccount.hpp"
#include <iostream>
#include <string>
#include <fstream>

void createStaffAccount()
{
    std::string username;
    std::string password;
    std::string re_pass;

    std::cout << "Please input username: ";
    std::cin >> username;
    std::cout << "Please input password: ";
    std::cin >> password;
    std::cout << "Please re_type password: ";
    std::cin >> re_pass;
    if(re_pass.size() < 8)
    {
        std::cerr << "Error: Password must be longer than 8 characters. Please try again!\n";
        return;
    }
    
    if(re_pass != password)
    {
        std::cerr << "Error: Password do not match. Please try again!\n";
        return;
    }

    std::string path = "Data\\Account\\AcademicStaff\\" + username + ".txt";
    std::ifstream fin;
    fin.open(path);

    if(fin.is_open()){
        fin.close();
        std::cerr << "Username has existed";
        return;
    } 
    std::ofstream fout;

    fout.open(path);
    fout << password << ",";
    std::string tmp;
    std::cout   << "\t\t\tUSER PROFILE INFORMATION:\n";
    
    std::cout   << "User ID: ";
    std::cin    >> tmp;
    fout << tmp << ",";
    
    std::cout   << "First name: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Last name: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Gender: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Date of birth (d/m/y): ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Social ID: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    fout.close();

}

void createStudentAccount(std::string username)
{
    std::string path = "Data\\Account\\Student\\" + username + ".txt";
    std::ifstream fin;
    fin.open(path);

    if(fin.is_open()){
        fin.close();
        std::cerr << "Username has existed";
        return;
    } 
    std::ofstream fout;
    fout.open(path);
    fout << "12345678,";

    std::string tmp;
    std::cout   << "\t\t\tUSER PROFILE INFORMATION:\n";

    std::cout   << "User ID: ";
    std::cin    >> tmp;
    fout << tmp << ",";
    
    std::cout   << "First name: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Last name: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Gender: ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Date of birth (d/m/y): ";
    std::cin    >> tmp;
    fout << tmp << ",";

    std::cout   << "Social ID: ";
    std::cin    >> tmp;
    fout << tmp << ",";
    
    fout.close();
}