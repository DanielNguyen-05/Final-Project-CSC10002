#pragma once
#include<iostream>
#include<string>

using namespace std;
struct Students
{
    int no;
    int stu_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    int soci_id;
};
ostream& operator << (ostream& cout, const Students a)
{
    cout << a.no << "\t" << a.stu_id << "\t" << a.first_name << " " << a.last_name << "\t" << a.gender << "\t" << a.date_of_birth << "\t" << a.soci_id << std::endl;
    return cout;
}