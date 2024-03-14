#pragma once
#include<iostream>
#include<string>

using namespace std;
struct Student
{
    int no;
    int stu_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    int soci_id;
};
ostream& operator << (ostream& os, const Student a){
    os << a.no << "\t" << a.stu_id << "\t" << a.first_name << " " << a.last_name << "\t" << a.gender << "\t" << a.date_of_birth << "\t" << a.soci_id << std::endl;
    return os;
}
bool operator < (const Student a, const Student b) {
    return a.stu_id < b.stu_id;
}
bool operator > (const Student a, const Student b) {
    return a.stu_id > b.stu_id;
}
bool operator == (const Student a, const Student b) {
    return a.stu_id == b.stu_id;
}
bool operator != (const Student a, const Student b) {
    return !(a == b);
}