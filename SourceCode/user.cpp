#include "user.hpp"
#include <sstream>

bool Users::isStudent(std::string username, std::string password) {
    std::string account_file = "Data/Account/Student/" + username + ".txt";
    std::string account_pass;
    std::string line;

    std::ifstream fin;
    fin.open(account_file.c_str());
    if(!fin.is_open()) {
        // system("cls");
        // std::cerr << "Wrong password or username!" << std::endl;
        return false;
    }

    // fin >> account_pass;
   
    
    std::getline(fin, line);
    fin.close();
    std::stringstream split(line);

    std::getline(split, account_pass, ',');

    if(account_pass != password) {
        // system("cls");
        // std::cerr << "Wrong password or username!" << std::endl;
        return false;
    }

    std::getline(split, user_id, ',');
    std::getline(split, first_name, ',');
    std::getline(split, last_name, ',');
    std::getline(split, gender, ',');
    std::getline(split, date_of_birth, ',');
    std::getline(split, soci_id);

    Username = username;
    Password = password;

    return true;
}

bool Users::isAcademicStaff(std::string username, std::string password) {
    std::string account_file = "Data/Account/AcademicStaff/" + username + ".txt";
    std::string account_pass;
    std::string line;

    std::ifstream fin(account_file);
    if(!fin.is_open()) {
        // system("cls");
        // std::cerr << "Wrong password or username!" << std::endl;
        return false;
    }

    std::getline(fin, line);
    fin.close();
    std::stringstream split(line);

    std::getline(split,account_pass,',');

    if(account_pass != password) {
         //system("cls");
         //std::cerr << "Wrong password or username!" << std::endl;
        return false;
    }

    std::getline(split, user_id, ',');
    std::getline(split, first_name, ',');
    std::getline(split, last_name, ',');
    std::getline(split, gender, ',');
    std::getline(split, date_of_birth, ',');
    std::getline(split, soci_id);

    Username = username;
    Password = password;

    return true;
}

bool Users::login() {
    std::string username;
    std::string password;
    std::cout << "- Please input username: ";
    std::cin  >> username;

    std::cout << "- Please input password: ";
    std::cin  >> password;

    if (isStudent(username, password)) {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            std::cout << "\tLog in successfully! Welcome, student " << Username << "!\n";
            std::cout << "\nPress enter to continue...";
            std::cin.ignore();
            std::cin.get();
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            return true;
    } else {
        if(isAcademicStaff(username, password)) {
            isStaff = true;
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            std::cout << "\tLog in successfully! Welcome, staff " << Username << "!\n";
            std::cout << "\nPress enter to continue...";
            std::cin.ignore();
            std::cin.get();
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            return true;
        }
    }
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
    std::cout << "\t\tWrong password or username!\n";
    return false;
}

void Users::viewProfileInfo() {
    std::cout   << "\t\tUSER PROFILE INFORMATION:\n"
                << "- User ID: " << user_id << "\n"
                << "- Full name: " << last_name +" "+ first_name << "\n"
                << "- Gender: " << gender << "\n"
                << "- Date of birth: " << date_of_birth << "\n"
                << "- Social ID: " << soci_id << "\n";
}

bool Users::changePassword() {
    if(Password   == "") {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cout << "\tThe user's data is not existed! Please try again!\n";
        return false;
    }

    std::string password , new_password , re_new_password;

    std::cout << "- Current password: ";
    std::cin  >> password;

    std::cout << "- New password: ";
    std::cin  >> new_password;
    
    std::cout << "- Re-type new password: ";
    std::cin  >> re_new_password;

    if(password   != Password) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cerr << "\tYour old password is wrong. Please try again!\n"; 
        return false;
    } 

    if(new_password.size() < 8) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cerr   << "\tError: Password must be longer than 8 characters. Please try again!\n";
        return false;
    }
    
    if(new_password == Password) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cerr   << "\tNew password must be different from current password!\n";
        return false;
    }

    if(new_password != re_new_password) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        std::cerr   << "\tError: Password do not match. Please try again!\n";
        return false;
    }

    Password = new_password;
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "\tChange password successfully!\n";
    saveData();
    return true;
}

void Users::logout() {
    Username = "";
    Password = "";

    std::cout << "\tLog out successfully!";
}

void Users::saveData()
{
    std::ofstream fout;
    if(isStaff) fout.open("Data/Account/AcademicStaff/" + Username + ".txt");
    else fout.open("Data/Account/Student/" + Username + ".txt");
    
    if(!fout.is_open()) {
        std::cerr << "The user's data is not existed!";
        return;
    }
    fout << Password << "," << user_id << "," << first_name << "," << last_name << "," << gender << "," << date_of_birth << "," << soci_id;
    fout.close();
}