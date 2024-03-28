#pragma once
#include "course.hpp"
#include <string>
#include <windows.h>
#include <sys/stat.h>
#include <limits>

struct Semester {
    int semester_num;
    std::string start_day;
    std::string end_day;
    LinkedList<Course> courses;
    Semester() {
        semester_num = 0;
    }
    Semester(int semester_num, std::string start_day, std::string end_day);
    void loadSemesterData(std::string schoolyear, int semester);
    void createSemester(std::string year, int semester);
    void createCourse();
    void viewCourseList();
    void updateCourse();
    void deleteCourse();
};
bool checkSemester(std::string curYear, int curSemester);