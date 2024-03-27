#include <filesystem>
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"

struct Student
{
    int no;
    std::string stu_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id; 
};

struct  General_class
{
    std::string name_class;
    std::string name_teacher;
    int number_of_student = 51;
    LinkedList<Student> student;
};

struct SchoolYear
{
    std::string year;
    LinkedList<General_class> Generalclass;
};

bool year_exits ( std::string list_of_school_year, std::string year );

void create_School_year ( std::string list_of_school_year, LinkedList <SchoolYear> &head );

bool class_exists ( std::string list_of_class , LinkedList<SchoolYear> &head, std::string cur_class);

void create_general_class ( std::string list_of_class , LinkedList<SchoolYear> &head);

bool student_exist ( std::string cur_class, std::string year, std::string student_id);

void add_student_to_class ( std::string list_of_class, LinkedList<SchoolYear> &head);

void add_quick_student_to_class ( std::string list_of_class, LinkedList<SchoolYear> &head);

