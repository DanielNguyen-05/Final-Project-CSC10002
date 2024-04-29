#pragma once
#include "semester.hpp"

struct StudentControl {

    LinkedList<StudentCourses> stu_courses;

    void loadStudentCoursesData(Semester semester, string stu_id);
    void viewCourses();
    void viewScoreboard();
};
