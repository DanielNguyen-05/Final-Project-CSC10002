#pragma once
#include "semester.hpp"
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

struct StudentControl {

    LinkedList<StudentCourses> stu_courses;

    void loadStudentCoursesData(Semester semester, string stu_id);
    void viewCourses();
    void viewScoreboard();
};
