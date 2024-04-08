#pragma once
#include "course.hpp"
#include <string>
#include "subFunction.hpp"
#include "limits"

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
    void createCourse(std::string curYear, Course& course);
    void viewCourseList();
    void updateCourse();
    void deleteCourse();
    bool findCourse(Course& course);
    void saveData(std::string schoolyear, int semester);
    void deallocate();
    void loadCourseData(std::string curYear);
};

bool checkSemester(std::string curYear, int curSemester);