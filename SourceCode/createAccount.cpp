#include "createAccount.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

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

std::string add1(std::string year)
{
    std::string new_year = year;
    if(year[1] == '9') {
        new_year[0] = year[0] + 1;
        new_year[1] = '0';
    }
    else new_year[1] = year[1] + 1;
    return new_year;
}

void createClassAccountFromfile(std::string classname)
{
    std::string path = "Data\\Account\\Student\\" ;

    std::string start_year_1 = classname.substr(0,2);
    std::string start_year_2 = add1(start_year_1);

    std::string path_in = "Data\\GeneralClasses\\20" + start_year_1 + "-" + "20" + start_year_2 + "\\" + classname + ".csv";

    std::ifstream fin, checker;
    std::ofstream fout;
    fin.open(path_in);
    std::cout << "In file name: " << path_in <<"\n";

    std::string line;
    std::string user_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id;
    std::string no;

    fin >> line;

    while(fin >> line)
    {
        std::stringstream split(line);

        std::getline(split, no, ',');
        std::getline(split, user_id, ',');
        std::getline(split, first_name, ',');
        std::getline(split, last_name, ',');
        std::getline(split, gender, ',');
        std::getline(split, date_of_birth, ',');
        std::getline(split, soci_id);

        checker.open(path + user_id + ".txt");
        if(checker.is_open()){
            checker.close();
            continue;
        } 

        fout.open(path + user_id + ".txt");
        std::cout << "Out file name: \n" << path + user_id + ".txt" << "\n";

        fout << "12345678,";
        fout << user_id << ",";
        fout << first_name << ",";
        fout << last_name << ",";
        fout << gender << ",";
        fout << date_of_birth << ",";
        fout << soci_id;

        fout.close();
    }
    fin.close();
}