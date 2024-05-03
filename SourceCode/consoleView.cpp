#include "consoleView.hpp"
#include "user.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void homePage()
{
      // Set text color to green
    std::cout << ANSI_COLOR_GREEN;

    // Calculate the length of the strings
    std::string course_management = "COURSE MANAGEMENT";
    std::string system_str = "SYSTEM";
    int total_width = 69; // Total width of the decorative line

    // Output the header with decorative lines
    for(int i = 0; i < total_width + 2; i++) std::cout << "*"; 
    std::cout << "\n";
    // Print "COURSE MANAGEMENT" centered within the decorative lines
    std::cout << "*";
    std::cout << std::setw((total_width - course_management.length()) / 2) << "" << ANSI_COLOR_RESET << ANSI_COLOR_BLUE << course_management;
    std::cout << std::setw((total_width - course_management.length()) / 2 + (total_width - course_management.length()) % 2) <<""<< ANSI_COLOR_RESET << ANSI_COLOR_GREEN << "*" << std::endl;
    // Print "SYSTEM" centered within the decorative lines
    std::cout << "*";
    std::cout << std::setw((total_width - system_str.length()) / 2) << "" << ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA << system_str;
    std::cout << std::setw((total_width - system_str.length()) / 2 + (total_width - system_str.length()) % 2) << "" << ANSI_COLOR_RESET << ANSI_COLOR_GREEN << "*" << std::endl;
    for(int i = 0; i < total_width + 2; i++) std::cout << "*"; 
    std::cout << "\n\n\n\n";

    // Reset text color
    std::cout << ANSI_COLOR_RESET;

    std::cout << "                      "<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "/^--^\\"<< ANSI_COLOR_RESET << ANSI_COLOR_YELLOW<<"     /^--^\\" <<ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA <<"     /^--^\\ \n";
    std::cout << "                      "<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "\\____/"<< ANSI_COLOR_RESET << ANSI_COLOR_YELLOW<<"     \\____/" <<ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA <<"     \\____/   \n";
    std::cout << "                     "<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "/      \\"<< ANSI_COLOR_RESET << ANSI_COLOR_YELLOW<<"   /      \\" <<ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA <<"   /      \\  \n";
    std::cout << "                    "<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "|        |"<< ANSI_COLOR_RESET << ANSI_COLOR_YELLOW<<" |        |" <<ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA <<" |        |  \n";
    std::cout << "                     "<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "\\__  __/"<< ANSI_COLOR_RESET << ANSI_COLOR_YELLOW<<"   \\__  __/" <<ANSI_COLOR_RESET << ANSI_COLOR_MAGENTA <<"   \\__  __/   \n"<<ANSI_COLOR_RESET;
    std::cout << "|^|^|^|^|^|^|^|^|^|^|^|^"<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "\\ \\"<< ANSI_COLOR_RESET<<"^|^|^|^"<<ANSI_COLOR_YELLOW<<"/ /"<<ANSI_COLOR_RESET<< "^|^|^|^|^"<<ANSI_COLOR_MAGENTA<<"\\ \\"<<ANSI_COLOR_RESET<<"^|^|^|^|^|^|^|^|^|^|^|\n";
    std::cout << "| | | | | | | | | | | | |"<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "\\ \\"<< ANSI_COLOR_RESET<<"| | |"<<ANSI_COLOR_YELLOW<<"/ /"<<ANSI_COLOR_RESET<< "| | | | | |"<<ANSI_COLOR_MAGENTA<<"\\ \\"<<ANSI_COLOR_RESET<<"| | | | | | | | | | |\n";
    std::cout << "#########################"<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "/ /"<< ANSI_COLOR_RESET<<"#####"<<ANSI_COLOR_YELLOW<<"\\ \\"<<ANSI_COLOR_RESET<< "###########"<<ANSI_COLOR_MAGENTA<<"/ /"<<ANSI_COLOR_RESET<<"#####################\n";
    std::cout << "| | | | | | | | | | | | |"<< ANSI_COLOR_RESET << ANSI_COLOR_BLUE << "\\/"<< ANSI_COLOR_RESET<<"| | | |"<<ANSI_COLOR_YELLOW<<"\\/"<<ANSI_COLOR_RESET<< "| | | | | |"<<ANSI_COLOR_MAGENTA<<"\\/"<<ANSI_COLOR_RESET<<" | | | | | | | | | | |\n";
    std::cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|\n";
}
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
            << "3. Export list of students in class\n"
            << "4. Delete a student\n"
            << "5. Manage points of course\n"
            << "6. Delete this course\n"
            << "7. Update information for this course\n"
            << "8. Go back to the previous page\n"
            << "9. Go back to MAIN MENU\n"
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