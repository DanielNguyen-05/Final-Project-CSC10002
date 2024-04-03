#pragma once
#include "student_courses.hpp"
#include "course.hpp"

std::string calOverall(std::string final, std::string midterm, std::string others);
std::string calOverallGPA(LinkedList <StudentCourses> stu_courses);