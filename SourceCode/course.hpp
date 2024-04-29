#pragma once
#include "student.hpp"
#include "linkedList.hpp"
#include <fstream>
#include <iomanip>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif
using namespace std;

struct Course {
    struct Point {
        string stu_id;
        string full_name;
        string overall;
        string final;
        string midterm;
        string others;

    };
    string ID;
    string course_name;
    string class_name;
    string teacher_name;
    int num_of_credit;
    int max_student;
    string day_of_week;
    string session;
    LinkedList<Student> students;
    LinkedList<Point> points;

    Course() {
        num_of_credit = 0;
        max_student = 50;
    }

    Course(string ID, string course_name, string class_name, string teacher_name, int num_of_creadit, int max_student, string day_of_week, string session);
    void inputCSV(string path);
    void outputCSV(string path);
    void importScoreboard(string path);
    void exportScoreboard(string path);
    void loadScoreboard(string path);
    void viewScoreboard();
    void updateResult();
    void addStudent();
    void deleteStudent();
    void viewStudent();
    bool studentExistedInCourse(string stu_id);
    void loadData(string curYear, int curSemester);
    void saveData(string curYear, int curSemester);
    void matchStudentPoint();
};
bool operator<(const Course::Point a, const Course::Point b);
bool operator>(const Course::Point a, const Course::Point b);
bool operator==(const Course::Point a, const Course::Point b);
bool operator!=(const Course::Point a, const Course::Point b);
