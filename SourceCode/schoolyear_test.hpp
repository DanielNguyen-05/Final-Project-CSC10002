#pragma once
#include "semester.hpp"
#include "LinkedList.hpp"
#include <fstream>
#include <string>

struct SchoolYear {
    std::string year;
    LinkedList<Semester> semesters;
    LinkedList<Student> students;
    SchoolYear() {
        year = "";
    }
    SchoolYear(std::string year) {
        this->year = year;
    }
    void createSchoolYear();
    void createGeneralClass();
    void importStudentsToGeneralClassFromCSV(std::string filename);
};