#pragma once
#include "course.hpp"
#include <string>

struct Semester {
    int semester_num;
    std::string start_day;
    std::string end_day;
    LinkedList<Course> courses;
    Semester() {
        semester_num = 0;
    }
    Semester(int semester_num, std::string start_day, std::string end_day) {
        this->semester_num = semester_num;
        this->start_day = start_day;
        this->end_day = end_day;
    }
    void loadSemesterData(std::string schoolyear, int semester);
    void createSemester();
    void createCourse();
    void viewCourseList();
    void updateCourse();
    void deleteCourse();
};