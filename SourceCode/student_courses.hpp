#pragma once 
#include <string>
using namespace std;

struct StudentCourses {

    //student info
    string stu_id;
    string full_name;

    //point
    string overall;
    string final;
    string midterm;
    string others;
    
    //course data
    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int num_of_credit;
    string day_of_week;
    string session;
};