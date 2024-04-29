#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "linkedList.hpp"
#include "student.hpp"
#include <iomanip>
#include <sstream>

bool classExisted(std::string  input_file_generalclass, std::string general_class);
void listOfStudent(std::string curYear, std::string curClass);
bool createGeneralClass(std::string curYear, std::string curClass);
bool studentExistedInGeneralClass(std::string curYear, std::string curClass, std::string Student_id);
bool addOneStudentToClass(std::string curYear, std::string curClass);
bool importStudent(std::string curYear, std::string curClass);