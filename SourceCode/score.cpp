#include "score.hpp"
#include <sstream>

std::string calOverall(std::string final, std::string midterm, std::string others) {
    double final_f = atof(final.c_str());
    double midterm_f = atof(midterm.c_str());
    double others_f = atof(others.c_str());

    double overall_f = final_f * 0.5 + midterm_f * 0.3 + others_f * 0.2;

    stringstream stream;
    stream << overall_f;

    std::string overall;
    stream >> overall;
    return overall; 
}

std::string calOverallGPA(LinkedList <StudentCourses> stu_courses) {
    Node <StudentCourses> *cur;
    cur = stu_courses.pHead;

    double GPA_f = 0;
    double total_credit = 0;
    while(cur != nullptr) {
        GPA_f += atof((cur->data).overall.c_str());
        total_credit += (cur->data).num_of_credit;
        cur = cur -> pNext;
    }

    GPA_f = GPA_f / total_credit;

    stringstream stream;
    stream << GPA_f;

    std::string GPA;
    stream >> GPA;
    return GPA; 
}