#include "schoolyear_test.hpp"
#include <sstream>
#include <fstream>

void SchoolYear::createSchoolYear() {
    std::cout << "\t\t\t CREATING NEW SCHOOL YEAR" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the school year: ";
    std::cin >> year;
}

void SchoolYear::createGeneralClass() {
    std::cout << "\t\t\t REATING A NEW GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the new General Class: ";
    std::cin >> class_name;
}


void SchoolYear::importStudentsToGeneralClassFromCSV(std::string path) {
    std::cout << "\t\t\t ADDING STUDENT TO GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the General Class: ";
    std::cin >> class_name;

    std::ifstream fIn(path);
    std::string ignore = "";
    std::getline(fIn, ignore);
    while (!fIn.eof()) {
        Student stu;
        std::string tmp_no = "";
        std::getline(fIn, tmp_no, ',');
        if (tmp_no == "") return;
        std::getline(fIn, stu.stu_id, ',');
        std::getline(fIn, stu.first_name, ',');
        std::getline(fIn, stu.last_name, ',');
        std::getline(fIn, stu.gender, ',');
        std::getline(fIn, stu.date_of_birth, ',');
        std::getline(fIn, stu.soci_id);

		this->students.insertOrdered(stu);
    }
    fIn.close();
}