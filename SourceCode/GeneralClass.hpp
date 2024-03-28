#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"

struct Student_in_class
{
    int no;
    string stu_id;
    string first_name;
    string last_name;
    string gender;
    string Date_of_birth;
    string social_id;
};

bool class_existed(std::string  input_file_generalclass, std::string general_class);
void list_of_student(std::string curYear, std::string curClass);
bool create_General_class(std::string curYear, std::string curClass); bool add_1_student_to_class(std::string curYear, std::string curClass, Student_in_class Student);
bool student_exist(std::string curYear, std::string curClass, std::string Student_id);
bool add_1_student_to_class(std::string curYear, std::string curClass, Student_in_class Student);
bool import_student_by_csv(std::string curYear, std::string curClass, std::string input_file);