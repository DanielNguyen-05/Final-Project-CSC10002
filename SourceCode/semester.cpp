#include "semester.hpp"
#include <sstream>

Semester::Semester(int semester_num, std::string start_day, std::string end_day) {
    this->semester_num = semester_num;
    this->start_day = start_day;
    this->end_day = end_day;
}

bool checkSemester(std::string curYear, int curSemester) {
    std::string ignore;
    int s;
    std::ifstream fin;
    std::string path = "Data\\" + curYear + "\\Semester.txt";
    fin.open(path);
    while (!fin.eof())
    {
        fin >> s;
        getline(fin, ignore);
        if (s == curSemester)
        {
            return true;
        }
    }
    fin.close();
    return false;
}
void Semester::loadSemesterData(std::string schoolyear, int semester) // School Year -> Semester -> Course
{
    char* intStr = new char[1];
    sprintf(intStr,"%d",semester);
    std::string courses_path = "Data\\" + schoolyear + "\\Semester " + intStr + "\\CourseList.txt";
    std::string courses_id;
    std::string line;
    std::ifstream f_courses_list;
    std::ifstream fin;

    Course tmp;
    std::string tmpNum;

    f_courses_list.open(courses_path);
    if(!f_courses_list.is_open()) return;

    while(f_courses_list >> courses_id) //course_data , course student
    {
        //load
        std::string courses_path = "Data\\" + schoolyear + "\\Semester " + std::string(intStr) + "\\" + courses_id + "\\" + courses_id + ".csv";
        fin.open(courses_path);
        std::getline(fin, line);
        stringstream split(line); 
        getline(fin, tmp.ID, ',');
        getline(fin, tmp.course_name, ',');
        getline(fin, tmp.class_name, ',');
        getline(fin, tmp.teacher_name, ',');
        getline(fin, tmpNum, ',');
        tmp.num_of_credit = atoi(tmpNum.c_str());
        getline(fin, tmpNum, ',');
        tmp.max_student = atoi(tmpNum.c_str());
        getline(fin, tmp.day_of_week, ',');
        getline(fin, tmp.session);

        fin.close();
        std::string path = "Data\\" + schoolyear + "\\Semester " + std::string(intStr) + "\\" + courses_id + "\\";
        tmp.inputCSV(path + "StudentList.csv");
        tmp.importScoreboard(path + "Point.csv");
        this->courses.insertAtTail(tmp);
    }

    f_courses_list.close();
}

void Semester::createCourse(std::string curYear, Course &course) {
        std::cout << "\t\t\t CREATING A NEW COURSE - " << course.ID << "\n\n" ;
        std::cout << "\t - Enter the name of this course (ex: Ki thuat lap trinh): ";
        std::cin >> course.course_name;
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
        std::string path = "Data\\" + curYear + "\\Semester " + std::to_string(this->semester_num) + "\\" + course.ID;
        std::wstring folder(path.begin(), path.end());
        if (!CreateDirectory(folder.c_str(), NULL)) {
            std::cout << "can't create folder Semester, please try again" << "\n";
            return;
        }
}

void Semester::viewCourseList() {
        Node<Course>* cur = this->courses.pHead;
        std::cout << "No \t ID of Course \t Course Name \t Class Name \t Teacher Name \t Credits \t Max Student \t Day Of Week \t Session" << "\n";
        while (cur != nullptr) {
            std::cout << cur->data.ID << "\t";
            std::cout << cur->data.course_name << "\t";
            std::cout << cur->data.class_name << "\t";
            std::cout << cur->data.teacher_name << "\t";
            std::cout << cur->data.num_of_credit << "\t";
            std::cout << cur->data.max_student << "\t";
            std::cout << cur->data.day_of_week << "\t";
            std::cout << cur->data.session << "\n";
            cur = cur->pNext;
        }
}

void Semester::updateCourse() {
        std::string course_id;
        std::cout << "\t - Enter the ID of the course you want to update: ";
        std::cin >> course_id;

        Node<Course>* cur = this->courses.pHead;
        std::cout << "\t\t\t UPDATING THE COURSE "  << course_id  << ": " << "\n\n" ;
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

void Semester::deleteCourse(std::string curYear) {
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

    // delete whole folder of this course
    std::string folderPath = "Data\\" + curYear + "\\Semester " + std::to_string(this->semester_num) + "\\" + course_id;
    std::wstring folder(folderPath.begin(), folderPath.end());
    if (!RemoveDirectory(folder.c_str())) std::cout << "Failed to delete the folder!" << "\n";
}

void Semester::createSemester(std::string year,int semester) {
    std::string path = "Data\\" + year + "\\Semester " + std::to_string(semester);
    std::wstring folder(path.begin(), path.end());
    if (!CreateDirectory(folder.c_str(), NULL)) {
        std::cout << "can't create folder Semester, please try again" << "\n";
        return;
    }
    LinkedList<Semester> s;
    Semester tmp;
    std::ifstream fIn("Data\\" + year + "\\Semester.txt");
    if (!fIn.is_open()) {
        std::cout << "\t -Failed to open the file!" << "\n";
        return;
    }
    fIn.ignore();
    while (fIn >> tmp.semester_num) {
        char comma;
        fIn >> comma; 


        fIn >> tmp.start_day >> comma >> tmp.end_day;

        std::string ignore;
        std::getline(fIn, ignore, '\n');


        s.insertAtTail(tmp);
    }
    fIn.close();


    std::cout << "\t\t\t CREATING A NEW SEMESTER" << year << "  S" << semester << "\n\n";
    this->semester_num = semester;
    std::cout << "\t - Enter the start date (ex: 05/09/2023): ";
    std::cin >> this->start_day;
    std::cout << "\t - Enter the end date (ex: 20/01/2024): ";
    std::cin >> this->end_day;
    s.insertAtHead(*this);
    std::ofstream fOut("Data\\" + year + "\\Semester.txt");
    if (!fOut.is_open()) {
        std::cout << "\t -Failed to open the file!" << "\n";
        return;
    }
    Node<Semester>* cur = s.pHead;
    while (cur) {
        fOut << cur->data.semester_num << "," << cur->data.start_day << "," << cur->data.end_day;
        cur = cur->pNext;
        if (cur)
            fOut << "\n";
    }
    fOut.close();
    std::cout << "Create semester successfully...Enter to continue\n";
    std::cin.get();
    std::cin.get();
    s.deallocate();
}
bool Semester::findCourse(Course& course) {
    Node<Course>* cur = this->courses.pHead;
    while (cur) {
        if (cur->data.ID == course.ID) {
            course = cur->data;
            return true;
        }
        cur = cur->pNext;
    }
    return false;
}
void Semester::saveData() {

}
void Semester::deallocate() {

}