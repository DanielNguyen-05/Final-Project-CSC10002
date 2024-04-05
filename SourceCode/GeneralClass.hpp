#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"
#include "student.hpp"
#include <iomanip>
#include <sstream>

bool class_existed(std::string  input_file_generalclass, std::string general_class);
void list_of_student(std::string curYear, std::string curClass);
bool create_General_class(std::string curYear, std::string curClass);
bool student_exist(std::string curYear, std::string curClass, std::string Student_id);
bool add_1_student_to_class(std::string curYear, std::string curClass);
bool import_student_by_csv(std::string curYear, std::string curClass);