#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LinkedList.hpp"


bool class_existed(std::string  input_file_generalclass, std::string general_class);
void list_of_student(std::string curYear, std::string curClass);
bool create_General_class(std::string curYear, std::string curClass);