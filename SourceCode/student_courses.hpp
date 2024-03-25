#pragma once
#include <string>
#include "course.hpp"

struct StudentCourses{

    Course::Point point; 

    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int num_of_credit;
    string day_of_week;
    string session;
};