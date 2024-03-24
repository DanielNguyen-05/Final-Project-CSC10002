#include "student.hpp"
#include <fstream>
#include <cstring>
#include <sstream>
#include "course.hpp"
#include "semester.hpp"

void findCoursesData(Student stu, std::string schoolyear, int semester) // School Year -> Semester -> Course
{
//     char* intStr;
//     sprintf(intStr,"%d\n",semester);
//     std::string courses_path = "Data\\SchoolYear\\" + schoolyear + "\\Semester" + std::string(intStr) + "\\";
//     std::string courses_name;
//     std::string line;

//     std::ifstream f_courses_list;
//     std::ifstream fin;


//     f_courses_list.open(courses_path + "CoursesList");
//     if(!f_courses_list.is_open()) return;

//     while(f_courses_list >> courses_name)
//     {
//         fin.open(courses_path + courses_name);

//         std::getline(fin, line);
//         stringstream split(line);



//         fin.close();
//     }


//     f_courses_list.close();
}

void Student::viewCourses(Semester semester)
{
    Node<Course>* cur_course = semester.courses.pHead;
    Node<Student>* cur_stu;

    while(cur_course != nullptr)
    {
        cur_stu = (cur_course -> data).students.pHead;

        while(cur_stu != nullptr)
        {
            if(cur_stu -> data.stu_id == this -> stu_id)
            {
                
                break;
            }
            cur_stu = cur_stu -> pNext;
        }

        cur_course = cur_course -> pNext;
    }
}

void Student::viewScoreBoard()
{

}