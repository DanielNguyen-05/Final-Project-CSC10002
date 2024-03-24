#pragma once
#include<iostream>
#include<string>

using namespace std;

struct Student {
    string stu_id;
    string first_name;
    string last_name;
    string gender;
    string date_of_birth;
    string soci_id;

    Student() {
        stu_id = -1;
    }
    Student(string stu_id, string first_name, string last_name, string gender, string date_of_birth, string soci_id);

    void viewCourses();
    void viewScoreBoard();
};

ostream& operator<<(ostream& os, const Student a);
bool operator<(const Student a, const Student b);
bool operator>(const Student a, const Student b);
bool operator==(const Student a, const Student b);
bool operator!=(const Student a, const Student b);