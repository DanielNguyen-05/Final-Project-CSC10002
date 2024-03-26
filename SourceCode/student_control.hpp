#pragma once
#include "semester.hpp"

struct Student_Control{

    LinkedList<StudentCourses> stu_courses;

    void loadStudentCoursesData(Semester semester, string stu_id);
    void viewCourses();
    void viewScoreBoard();
};
