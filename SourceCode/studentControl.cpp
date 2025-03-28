#include "student.hpp"
#include "studentControl.hpp"
#include <fstream>
#include <cstring>
#include <sstream>

double StudentControl::calcGPA() {
    Node <StudentCourses> *cur;
    cur = stu_courses.pHead;

    double GPA_f = 0;
    double total_credit = 0;
    while(cur != nullptr) {
        if (cur->data.overall != "?") {
            GPA_f += atof((cur->data).overall.c_str()) * (cur->data).num_of_credit;
            total_credit += (cur->data).num_of_credit;
            }
            cur = cur->pNext;
    }

    GPA_f = GPA_f / total_credit;

    if(total_credit == 0) return -1;
    
    return GPA_f; 
}
void StudentControl::loadStudentCoursesData(Semester semester, string stu_id) {
    Node<Course>* cur_course = semester.courses.pHead;
    Node<Student>* cur_stu;
    Node<Course::Point>* cur_point;
    StudentCourses tmp;

    while(cur_course != nullptr) {
        cur_stu = (cur_course -> data).students.pHead;
        tmp.ID = "";
        while(cur_stu != nullptr) {
            if(cur_stu -> data.stu_id == stu_id) {
                tmp.ID              = (cur_course->data).ID;
                tmp.class_name      = (cur_course->data).class_name;
                tmp.course_name     = (cur_course->data).course_name;
                tmp.teacher_name    = (cur_course->data).teacher_name;
                tmp.num_of_credit   = (cur_course->data).num_of_credit;
                tmp.day_of_week     = (cur_course->data).day_of_week;
                tmp.session         = (cur_course->data).session;
                break;
            }
            cur_stu = cur_stu -> pNext;
        }

        cur_point = (cur_course->data).points.pHead;

        while(cur_point != nullptr) {
            if(cur_point -> data.stu_id == stu_id)
            {
                tmp.stu_id      = (cur_point -> data).stu_id;
                tmp.full_name   = (cur_point -> data).full_name;
                tmp.overall     = (cur_point -> data).overall;
                tmp.final       = (cur_point -> data).final;
                tmp.midterm     = (cur_point -> data).midterm;
                tmp.others      = (cur_point -> data).others;

                break;
            }
            cur_point = cur_point -> pNext;
        }
        if(tmp.ID != "") stu_courses.insertAtTail(tmp);
        cur_course = cur_course -> pNext;
    }
}
void StudentControl::viewCourses() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    Node<StudentCourses>* cur = stu_courses.pHead;

    std::cout << "+----+----------------------+----------------------+----------------------+----------------------+-------------------+-------------+-------------------+\n";
    std::cout << "| No |      Course ID       |     Course name      |      Class name      |     Teacher name     | Number of credits | Day of week |      Session      |\n";
    std::cout << "+----+----------------------+----------------------+----------------------+----------------------+-------------------+-------------+-------------------+\n";

    int no = 0;
    while (cur != nullptr) {
        no++;
        std::cout << "| " << std::setw(2) << no << " | ";
        std::cout << std::left << std::setw(20) << (cur->data).ID << " | ";
        std::cout << std::left << std::setw(20) << (cur->data).course_name << " | ";
        std::cout << std::setw(20) << std::right << (cur->data).class_name << " | ";
        std::cout << std::setw(20) << std::right << (cur->data).teacher_name << " | ";
        std::cout << std::setw(17) << std::right << (cur->data).num_of_credit << " | ";
        std::cout << std::setw(11) << std::right << (cur->data).day_of_week << " | ";
        std::cout << std::setw(17) << std::right << (cur->data).session <<" |\n";

        cur = cur->pNext;
        std::cout << "+----+----------------------+----------------------+----------------------+----------------------+-------------------+-------------+-------------------+\n";
    }
}

void StudentControl::viewScoreboard() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    Node<StudentCourses>* cur = stu_courses.pHead;

    std::cout << "+----+--------------------+-----------+-----------+-----------+-----------+\n";
    std::cout << "| No |    Course name     |  Midterm  |   Final   |  Others   |  Overall  |\n";
    std::cout << "+----+--------------------+-----------+-----------+-----------+-----------+\n";

    int no = 0;
    while (cur != nullptr) {
        no++;
        std::cout << "| " << std::setw(2) << no << " | ";
        std::cout << std::left << std::setw(18) << (cur->data).course_name << " | ";
        std::cout << std::right << std::setw(9) << (cur->data).midterm << " | ";
        std::cout << std::right << std::setw(9) << (cur->data).final << " | ";
        std::cout << std::right << std::setw(9) << (cur->data).others << " | ";
        std::cout << std::right << std::setw(9) << (cur->data).overall << " |\n";

        cur = cur->pNext;
        std::cout << "+----+--------------------+-----------+-----------+-----------+-----------+\n";
    }
}
