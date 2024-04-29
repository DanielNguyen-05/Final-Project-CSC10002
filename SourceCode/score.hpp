#pragma once
#include "studentCourses.hpp"
#include "course.hpp"

std::string calOverall(std::string final, std::string midterm, std::string others);
std::string calOverallGPA(LinkedList <StudentCourses> stu_courses);