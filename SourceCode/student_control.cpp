#include "student.hpp"
#include <fstream>
#include <cstring>
#include <sstream>
#include "student_control.hpp"

void Student_Control::loadStudentCoursesData(Semester semester, string stu_id) {
    Node<Course>* cur_course = semester.courses.pHead;
    Node<Student>* cur_stu;
    Node<Course::Point>* cur_point;
    StudentCourses tmp;

    while(cur_course != nullptr) {
        cur_stu = (cur_course -> data).students.pHead;

        while(cur_stu != nullptr) {
            tmp.ID = "";
            if(cur_stu -> data.stu_id == stu_id) {
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
void Student_Control::viewCourses() {
    Node<StudentCourses> *cur = stu_courses.pHead;

    while(cur != nullptr) {
        std::cout   << "ID\tCourse name\tClass name\tTeacher name\tNumber of credit\tDay of week\tSession\n";
        std::cout   << (cur->data).ID << "\t"
                    << (cur->data).course_name << "\t"
                    << (cur->data).teacher_name << "\t"
                    << (cur->data).num_of_credit << "\t"
                    << (cur->data).day_of_week << "\t"
                    << (cur->data).session << "\n";
        cur = cur -> pNext;
    }
}

void Student_Control::viewScoreBoard() {
    Node<StudentCourses> *cur = stu_courses.pHead;

    while(cur != nullptr) {
        std::cout   << "ID\tCourse name\tMidterm\tFinal\tOthers\tOverall\n";
        std::cout   << (cur->data).ID << "\t"
                    << (cur->data).course_name << "\t"
                    << (cur->data).midterm << "\t"
                    << (cur->data).final << "\t"
                    << (cur->data).others << "\t"
                    << (cur->data).overall << "\n";
        cur = cur -> pNext;
    }
}