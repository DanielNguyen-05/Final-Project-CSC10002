#include <iostream>
#include <string>
#include "consoleView.h"
#include "User.hpp"

void programInterface()
{
	std::cout   << "\tWhat would you like to do?\n"
                << "1. Log in\n"
                << "0. Stop program\n\n"

                << "Your choice: ";
}

void chooseRole()
{
    std::cout   << "\tAre you a Staff or a Student?\n"
                << "1. Academic Staff\n"
                << "2. Student\n"
                << "0. Stop program\n\n"

                <<"Your choice: ";
}

void loginFail()
{
    std::cout   << "\tWhat would you like to do?\n"
                << "1. Re-login\n"
                << "0. Back to previous page\n\n"
                
                << "Your choice: ";
}

void staffMainMenu(std::string username)
{
    std::cout   << "\t\t\tMAIN MENU\n"
                << "Hello " << username << "\n"
                << "1. Create a new school year\n"
                << "2. Edit an existed school year\n"  
                << "3. Change password\n"  
                << "4. View your profile\n"  
                << "0. Log out\n\n"

                << "Your choice: ";
}
void changePasswordFail() {
    std::cout   << "1. Re-enter it \n"
                << "0. Back to MAIN MENU \n\n"

                << "Your choice: ";
}
void createNewSchoolYear()
{
    std::cout   << "\t\t\tCREATING A NEW SCHOOL YEAR\n";
}

void isNOTcreated()
{
    std::cout    << "The new school year 202x-202x is created successfully!\n"
                << "1. Continue creating a new school year\n"
                << "0. Back to MAIN MENU \n\n"

                << "Your choice: ";
}
void editSchoolYearMenu() {
    std::cout   << "What would you like to do ?\n"
                << "0. Log out\n"
                << "1. Work on General Classes\n"
                << "2. Work on Course Classes\n"
                << "3. Go back to the previous page to choose another year\n"
                << "4. Go back to the Main Menu\n"

                << "Your choice: ";
}
void generalClassMenu() {
    std::cout   << "What would you like to do ?\n"
                << "0. Log out\n"
                << "1. Create a new general class\n"
                << "2. Edit an existed general class\n"
                << "3. Go back to the previous page to choose another class\n"
                << "4. Go back to the Main Menu\n"

                << "Your choice: ";
}
void inputSchoolYearFail() {
    std::cout   << "This school year is not existed\n"
                << "1. Re-enter it \n"
                << "0. Back to previous page \n\n"

                << "Your choice: ";
}
void listSchoolYear(){
    std::ifstream fIn;
    fIn.open("Data//SchoolYear.txt");
    if (!fIn.is_open()) {
        std::cerr << "error open SchoolYear.txt";
    }
    std::string year;
    int no = 0;
    while (!fIn.eof()) {
        fIn >> year;
        no++;
        std::cout << no << ". " << year << std::endl;
    }
    fIn.close();
    
}
void view_list_of_general_class(std::string year)
{
    std::ifstream fin;
    std::string s;
    std::string path = "Data\\" + year + "\\GeneralClass.txt";
    fin.open(path);
    if (!fin.is_open())
    {
        std::cout << "Can't open file. ";
        return;
    }
    while (!fin.eof())
    {
        fin >> s;
        std::cout << s << "\n";
    }
    fin.close();
}
void inputClassFail() {
    std::cout << "This class is not existed\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "Your choice: ";
}
void editGeneralClassMenu() {
    std::cout << "What would you like to do ?\n"
        << "0. Log out\n"
        << "1. Update the information of the general class\n"
        << "2. View list of students in the class\n"
        << "3. Import the list of students from .csv file into the general class\n"
        << "4. Add a student to class\n"
        << "5. Go back to the previous page to choose another class\n"
        << "6. Go back to the Main Menu\n"

        << "Your choice: ";
}
void createSchoolYearFail() {
    std::cout << "This school year is existed\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "Your choice: ";
}
void semesterMainMenu() {
    std::cout << "What would you like to do ?\n"
        << "0. Log out\n"
        << "1. Create a new semesters\n"
        << "2. Edit an existed semesters\n"
        << "3. Go back to the previous page\n"
        << "4. Go back to the Main Menu\n"

        << "Your choice: ";
}
void inputSemesterFail() {
    std::cout << "This semester is not existed\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "Your choice: ";
}
void createSemesterFail() {
    std::cout << "This semester is existed\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "Your choice: ";
}
void createClassFail() {
    std::cout << "This general class is existed\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "Your choice: ";
}