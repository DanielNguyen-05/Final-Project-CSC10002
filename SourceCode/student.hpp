#pragma once
#include "LinkedList.hpp"
#include"student_courses.hpp"
#include<iostream>
#include<string>

using namespace std;

struct Student{
    string stu_id;
    string first_name;
    string last_name;
    string gender;
    string date_of_birth;
    string soci_id;

    LinkedList<StudentCourses> stu_courses;

    Student() {
        stu_id = -1;
    }
    Student(string stu_id, string first_name, string last_name, string gender, string date_of_birth, string soci_id);

};
ostream& operator<<(ostream& os, const Student a);
bool operator<(const Student a, const Student b);
bool operator>(const Student a, const Student b);
bool operator==(const Student a, const Student b);
bool operator!=(const Student a, const Student b);