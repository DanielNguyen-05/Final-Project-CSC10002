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
    void createSchoolYear(std::string path);
    void createGeneralClass(std::stirng path);
    void importStudentsToGeneralClassFromCSV(std::string path);
};