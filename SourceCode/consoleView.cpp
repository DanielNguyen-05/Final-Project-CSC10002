#include "consoleView.hpp"
#include "user.hpp"
#include <iostream>
#include <string>

void programInterface() {
	std::cout   << "\tWhat would you like to do?\n"
                << "1. Log in\n"
                << "0. Stop program\n\n"

                << "- Your choice: ";
}

void loginFail() {
    std::cout   << "1. Re-login\n"
                << "0. Back to previous page\n\n"
                
                << "- Your choice: ";
}

void staffMainMenu(std::string username) {
    std::cout   << "\t\tMAIN MENU\n"
                << "1. Create a new school year\n"
                << "2. Edit an existed school year\n"  
                << "3. Change password\n"  
                << "4. View your profile\n"  
                << "0. Log out\n\n"

                << "- Your choice: ";
}

void changePasswordFail() {
    std::cout   << "1. Re-enter it \n"
                << "0. Back to MAIN MENU \n\n"

                << "- Your choice: ";
}

void createNewSchoolYear() {
    std::cout   << "\t\t CREATING A NEW SCHOOL YEAR\n";
}

void isNOTcreated() {
    std::cout   << "\tThe new school year 202x-202x is created successfully!\n" 
                << "1. Continue creating a new school year\n"
                << "0. Back to MAIN MENU \n\n"

                << "- Your choice: ";
}

void editSchoolYearMenu() {
    std::cout   << "\tWhat would you like to do?\n"
                
                << "1. Work on General Classes\n"
                << "2. Work on Semester\n"
                << "3. Go back to the previous page to choose another year\n"
                << "4. Go back to the Main Menu\n"
                << "5. Create Staff Account\n"
                << "0. Log out\n\n"

                << "- Your choice: ";
}

void generalClassMenu() {
    std::cout   << "\tWhat would you like to do?\n"
                
                << "1. Create a new general class\n"
                << "2. Edit an existed general class\n"
                << "3. Go back to the previous page to choose another class\n"
                << "4. Go back to the Main Menu\n"
                << "0. Log out\n\n"

                << "- Your choice: ";
}

void inputSchoolYearFail() {
    std::cout   << "\tThis school year is not existed!\n"
                << "1. Re-enter it \n"
                << "0. Back to previous page \n\n"

                << "- Your choice: ";
}

void listSchoolYear() {
    std::ifstream fIn;
    fIn.open("Data//SchoolYear.txt");
    if (!fIn.is_open()) {
        std::cerr << "There are some errors in opening SchoolYear.txt!";
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

void viewListOfGeneralClass(std::string year) {
    std::ifstream fin;
    std::string s;
    std::string path = "Data\\GeneralClasses\\" + year + "\\GeneralClass.txt";
    fin.open(path);
    if (!fin.is_open()) {
        std::cout << "Can't open file!";
        return;
    }
    while (!fin.eof()) {
        fin >> s;
        std::cout << s << "\n";
    }
    fin.close();
}

void inputClassFail() {
    std::cout << "\tThis class is not existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void editGeneralClassMenu() {
    std::cout << "\tWhat would you like to do?\n"
        
        << "1. View list of students in the class\n"
        << "2. Import the list of students from .csv file into the general class\n"
        << "3. Add a student to class\n"
        << "4. View scoreboard of class\n"
        << "5. Go back to the previous page to choose another class\n"
        << "6. Go back to the Main Menu\n"
        << "0. Log out\n\n"

        << "- Your choice: ";
}

void createSchoolYearFail() {
    std::cout << "\tThis school year is existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void semesterMainMenu() {
    std::cout << "\tWhat would you like to do?\n"
        << "1. Create a new semesters\n"
        << "2. Edit an existed semesters\n"
        << "3. Go back to the previous page\n"
        << "4. Go back to the Main Menu\n"
        << "0. Log out\n\n"

        << "- Your choice: ";
}

void inputSemesterFail() {
    std::cout << "\tThis semester is not existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void createSemesterFail() {
    std::cout << "\tThis semester has been already existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void createClassFail() {
    std::cout << "\tThis general class has been already existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void editSemesterMenu() {
    std::cout << "\tWhat would you like to do?\n"
        
        << "1. Create new courses\n"
        << "2. View all courses in this semester \n"
        << "3. Modify a course\n"
        << "4. Go back to the previous page to work on Semesters\n"
        << "5. Go back to MAIN MENU\n"
        << "0. Log out\n\n"

        << "- Your choice: ";
}

void inputCourseFail() {
    std::cout << "\tThis course is not existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void createCourseFail() {
    std::cout << "\tThis course has been already existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void modifyCourseMenu() {
        std::cout << "\tWhat would you like to do?\n"
            
            << "1. View all students in this course\n"
            << "2. Import students into this course\n"
            << "3. Delete a student\n"
            << "4. Manage points of course\n"
            << "5. Delete this course\n"
            << "6. Update information for this course\n"
            << "7. Go back to the previous page\n"
            << "8. Go back to MAIN MENU\n"
            << "0. Log out\n\n"

            << "- Your choice: ";
}

void importStudent() {
    std::cout << "\tImport Student: \n"
        << "1.Import a list of student by CSV file\n"
        << "2.Import a student\n"
        << "0.Go back\n\n"

        << "- Your choice: ";
}

void inputStudentFail(){
    std::cout << "\tThis student has been already existed!\n"
        << "1. Re-enter it \n"
        << "0. Back to previous page \n\n"

        << "- Your choice: ";
}

void editCoursePointMenu() {
    std::cout << "\tWhat would you like to do?\n"
        
        << "1. Import a point .csv file for a course\n"
        << "2. View scoreboard of a course\n"
        << "3. Update a student's result\n"
        << "4. Go back to the previous page\n"
        << "5. Go back to MAIN MENU\n"

        << "0. Log out\n\n"

        << "- Your choice: ";
}

void studentChooseYear(std::string username) {
    std::cout << "\tWhat school year which you want to check:\n" ;
}

void studentMenu() {
    std::cout << "\tWhat would you like to do?\n"
        
        << "1. View your profile\n"
        << "2. View courses and scoreboard\n"
        << "3. Change password\n"
        << "0. Log out\n\n"

        << "- Your choice: ";
}

void studentView() {
    std::cout << "\tWhat would you like to do?\n"
        
        << "1. View your scoreboard\n"
        << "2. View list of your courses\n"
        << "3. Back to Main Menu\n"
        << "0. Log out\n\n"

        << "- Your choice: ";
}