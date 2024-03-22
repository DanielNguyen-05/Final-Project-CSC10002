#include "semester.hpp"

Semester::Semester(int semester_num, std::string start_day, std::string end_day) {
    this->semester_num = semester_num;
    this->start_day = start_day;
    this->end_day = end_day;
}

void Semester::createSemester() {
    std::cout << "\t\t\t CREATING A NEW SEMESTER" << "\n\n" ;
    std::cout << "\t - Enter a new semester number which you want to create (ex: 1): ";
    std::cin >> this->semester_num;
    std::cout << "\t - Enter the start date (ex: 05/09/2023): ";
    std::cin >> this->start_day;
    std::cout << "\t - Enter the end date (ex: 20/01/2024): ";
    std::cin >> this->end_day;
}

void Semester::createCourse() {
    Course course;
    std::cout << "\t - Enter the name of this course (ex: KTLT): ";
    std::cin >> course.course_name;
    std::cout << "\t - Enter the ID of this course (ex: CSC10002-23CLC03): ";
    std::cin >> course.ID;
    std::cout << "\t - Enter the class which this course belongs to (ex: 23CLC03): ";
    std::cin >> course.class_name;
    std::cout << "\t - Enter the teacher of this course: ";
    std::cin >> course.teacher_name;
    std::cout << "\t - Enter the number of credits in this course (ex: 4): ";
    std::cin >> course.num_of_credit;
    std::cout << "\t - Enter the maximum number of students in this course: ";
    std::cin >> course.max_student;
    std::cout << "\t - Enter the day of week when this course will be held (ex: MON/TUE/WED/THU/FRI/SAT): ";
    std::cin >> course.day_of_week;
    std::cout << "\t- Here is the a list of sessions: " << "\n"
              <<     "\t\t 1. S1 (7:30 -> 9:15)" << "\n"
              <<     "\t\t 2. S2 (9:30 -> 11:15)" << "\n"
              <<     "\t\t 3. S3 (13:30 -> 15:15)" << "\n"
              <<     "\t\t 4. S4 (15:30 -> 17:15)" << "\n"
              << "\t - Which sessions, this course will be held (ex: S1): ";
    std::cin >> course.session;
    this->courses.insertAtTail(course);
}

void Semester::viewCourseList() {
    Node<Course>* cur = this->courses.pHead;
    std::cout << "No,ID,Course Name,Class Name,Teacher Name,Num of Credit,Max Student,Session" << endl;
    while (cur != nullptr) {
        std::cout << cur->data.ID << ",";
        std::cout << cur->data.course_name << ",";
        std::cout << cur->data.class_name << ",";
        std::cout << cur->data.teacher_name << ",";
        std::cout << cur->data.num_of_credit << ",";
        std::cout << cur->data.max_student << ",";
        std::cout << cur->data.session << endl;
        cur = cur->pNext;
    }
}

void Semester::updateCourse()
{
    std::string course_id;
    std::cout << "\t - Enter the ID of the course you want to update: ";
    std::cin >> course_id;

    Node<Course>* cur = this->courses.pHead;
    while (cur != nullptr) {
        if (cur->data.ID == course_id) {
            std::cout << "\t - Enter the new name of this course (ex: KTLT): ";
            std::cin >> cur->data.course_name;
            std::cout << "\t - Enter the new ID of this course (ex: CSC10002-23CLC03): ";
            std::cin >> cur->data.ID;
            std::cout << "\t - Enter the new class which this course belongs to (ex: 23CLC03): ";
            std::cin >> cur->data.class_name;
            std::cout << "\t - Enter the new teacher of this course: ";
            std::cin >> cur->data.teacher_name;
            std::cout << "\t - Enter the new number of credits in this course (ex: 4): ";
            std::cin >> cur->data.num_of_credit;
            std::cout << "\t - Enter the new maximum number of students in this course: ";
            std::cin >> cur->data.max_student;
            std::cout << "\t - Enter the new day of week when this course will be held (ex: MON/TUE/WED/THU/FRI/SAT): ";
            std::cin >> cur->data.day_of_week;
            std::cout << "\t- Here is the a list of sessions: " << "\n"
                      <<     "\t\t 1. S1 (7:30 -> 9:15)" << "\n"
                      <<     "\t\t 2. S2 (9:30 -> 11:15)" << "\n"
                      <<     "\t\t 3. S3 (13:30 -> 15:15)" << "\n"
                      <<     "\t\t 4. S4 (15:30 -> 17:15)" << "\n"
                      << "\t - Which sessions, this course will be held (ex: S1): ";
            std::cin >> cur->data.session;
            return;
        }
        cur = cur->pNext;
    }
    std::cout << "\t - Course not found!" << "\n";
}

void Semester::deleteCourse()
{
    std::string course_id;
    std::cout << "\t - Enter the ID of the course you want to delete: ";
    std::cin >> course_id;

    Node<Course>* cur = this->courses.pHead;
    Node<Course>* prev = nullptr;
    while (cur != nullptr) {
        if (cur->data.ID == course_id) {
            if (prev == nullptr) this->courses.pHead = cur->pNext;
            else prev->pNext = cur->pNext;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->pNext;
    }
    std::cout << "\t - Course not found!" << "\n";
}
