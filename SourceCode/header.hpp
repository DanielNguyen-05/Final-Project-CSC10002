#pragma once
#include <string>

struct ListNode;
struct List;
struct Account;
struct Semesters;
struct Courses;
struct Classes;
struct Sessions;
struct Students;
struct Points;
struct SchoolYear;

struct ListNode 
{
    SchoolYear* data;
    ListNode* pNext;
};

struct List 
{
    ListNode* pHead;
    List() : pHead(nullptr) {};
};

struct Account 
{
    std::string username;
    std::string password;
};

struct Points 
{
    double overall;
    double final;
    double midterm;
    double others;
};

struct Students 
{
    int no;
    int stu_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id;
    Points points;
    
    Students* pNext;
};

struct Sessions 
{
    std::string day_of_week; // MON TUE WED THU FRI SAT
    std::string time; // S1 (07:30), S2 (09:30), S3(13:30), S4 (15:30)
    Students* students;
    Sessions* pNext;
    Sessions() : students(nullptr), pNext(nullptr) {}
};

struct Classes
{
    std::string class_name;
    std::string teacher_name;
    int max_student; // default 50
    Sessions* sessions;
    Classes* pNext;
    Students * in_class_activity;
    Classes() : sessions(nullptr), pNext(nullptr) {}
};

struct Courses 
{
    int course_id;
    std::string course_name;
    int num_credits;
    Classes* classes;
    Courses* pNext;

    Courses() : classes(nullptr), pNext(nullptr) {}
};

struct Semesters 
{
    int num_semester;
    std::string start_day;
    std::string end_day;
    Courses* courses;
    Semesters* pNext;

    Semesters() : courses(nullptr), pNext(nullptr) {}
};

struct SchoolYear
{
    std::string year;
    Semesters* semesters;
    SchoolYear* pNext;
    Classes * activity_class;
    SchoolYear() : semesters(nullptr), pNext(nullptr) {}
};