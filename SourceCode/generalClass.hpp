#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "linkedList.hpp"
#include "semester.hpp"
#include <iomanip>
#include <sstream>
#include "consoleView.hpp"
#include "schoolyear.hpp"
#include "studentControl.hpp"
#include "createAccount.hpp"
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

bool classExisted(std::string  input_file_generalclass, std::string general_class);
void listOfStudent(std::string curYear, std::string curClass);
bool createGeneralClass(std::string curYear, std::string curClass);
bool studentExistedInGeneralClass(std::string curYear, std::string curClass, std::string Student_id);
bool addOneStudentToClass(std::string curYear, std::string curClass);
bool importStudent(std::string curYear, std::string curClass);
void viewScoreboard(std::string classYear, std::string curClass);