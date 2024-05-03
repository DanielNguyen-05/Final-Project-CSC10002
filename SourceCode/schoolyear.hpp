#pragma once
#include"subFunction.hpp"
#include "linkedList.hpp"
#include <string>
#include <fstream>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

bool yearExisted(std::string year);
bool createSchoolYear(std::string curYear);
bool yearValid(std::string curyear);