#pragma once
#include <string>
#include "course.hpp"
#pragma once 
#include<string>

struct StudentCourses{
using namespace std;
struct StudentCourses {
    struct Point {
        string stu_id;
        string full_name;
        string overall;
        string final;
        string midterm;
        string others;

    Course::Point point; 
    }point;

    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int num_of_credit;
    string day_of_week;
    string session;
};