#include "header.hpp"
#include <string>

SchoolYear* makeSchoolYear(std::string year) 
{
    SchoolYear* newSchoolYear = new SchoolYear;
    newSchoolYear->year = year;
    newSchoolYear->semesters = nullptr;
    newSchoolYear->pNext = nullptr;
    return newSchoolYear;
}

void addSchoolYearToList(List& l, std::string year) 
{
    SchoolYear* newSchoolYear = makeSchoolYear(year);
    ListNode* newNode = new ListNode;
    newNode->data = newSchoolYear;
    newNode->pNext = nullptr;

    if (l.pHead == nullptr) l.pHead = newNode;
    else 
    {
        ListNode* cur = l.pHead;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = newNode;
    }
}

Semesters* makeSemester(int num_semester, std::string start_day, std::string end_day) 
{
    Semesters* newSemester = new Semesters;
    newSemester->num_semester = num_semester;
    newSemester->start_day = start_day;
    newSemester->end_day = end_day;
    newSemester->courses = nullptr;
    newSemester->pNext = nullptr;
    return newSemester;
}

void addSemesterToSchoolYear(SchoolYear* schoolYear, Semesters* semester) 
{
    if (schoolYear->semesters == nullptr) schoolYear->semesters = semester;
    else 
    {
        Semesters* cur = schoolYear->semesters;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = semester;
    }
}

Courses* makeCourse(int course_id, std::string course_name, int num_credits) 
{
    Courses* newCourse = new Courses;
    newCourse->course_id = course_id;
    newCourse->course_name = course_name;
    newCourse->num_credits = num_credits;
    newCourse->classes = nullptr;
    newCourse->pNext = nullptr;
    return newCourse;
}

void addCourseToSemester(Semesters* semester, Courses* course) 
{
    if (semester->courses == nullptr) semester->courses = course;
    else 
    {
        Courses* cur = semester->courses;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = course;
    }
}

Classes* makeClass(std::string class_name, std::string teacher_name, int max_student, std::string day_of_week, std::string time) 
{
    Classes* newClass = new Classes;
    newClass->class_name = class_name;
    newClass->teacher_name = teacher_name;
    newClass->max_student = max_student;
    newClass->sessions = nullptr;
    newClass->pNext = nullptr;
    return newClass;
}

void addClassToCourse(Courses* course, Classes* newClass) 
{
    if (course->classes == nullptr) course->classes = newClass;
    else 
    {
        Classes* cur = course->classes;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = newClass;
    }
}

Sessions* makeSession(std::string day_of_week, std::string time) 
{
    Sessions* newSession = new Sessions;
    newSession->day_of_week = day_of_week;
    newSession->time = time;
    newSession->students = nullptr;
    newSession->pNext = nullptr;
    return newSession;
}

void addSessionToClass(Classes* newClass, Sessions* newSession) 
{
    if (newClass->sessions == nullptr) newClass->sessions = newSession;
    else 
    {
        Sessions* cur = newClass->sessions;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = newSession;
    }
}

Students* makeStudent(int no, int stu_id, std::string first_name, std::string last_name, std::string gender, std::string date_of_birth, int soci_id, Points points) 
{
    Students* newStudent = new Students;
    newStudent->no = no;
    newStudent->stu_id = stu_id;
    newStudent->first_name = first_name;
    newStudent->last_name = last_name;
    newStudent->gender = gender;
    newStudent->date_of_birth = date_of_birth;
    newStudent->soci_id = soci_id;
    newStudent->points = points;
    newStudent->pNext = nullptr;
    return newStudent;
}

void addStudentToSession(Sessions* session, Students* newStudent) 
{
    if (session->students == nullptr) session->students = newStudent;
    else 
    {
        Students* cur = session->students;
        while (cur->pNext != nullptr) cur = cur->pNext;
        cur->pNext = newStudent;
    }
}