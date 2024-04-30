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
    std::string path = "Data/" + curYear + "/Semester.txt";
    fin.open(path);
    if (!fin.is_open())
        return false;
    while (!fin.eof())
    {
        fin >> s;
        if (s == 0)
            break;
        getline(fin, ignore);
        if (s == curSemester) return true;
    }
    fin.close();
    return false;
}

void Semester::loadSemesterData(std::string schoolyear, int semester) /* School Year -> Semester -> Course */ {
    char* intStr = new char[1];
    sprintf(intStr, "%d", semester);
    std::string courses_path = "Data/" + schoolyear + "/Semester" + std::string(intStr) + "/CourseList.txt";
    std::string courses_id;
    std::string line;
    std::ifstream f_courses_list;
    std::ifstream fin;

    Course tmp;
    std::string tmpNum;

    f_courses_list.open(courses_path);
    if (!f_courses_list.is_open()) return;

    while (f_courses_list >> courses_id) //course_data , course student
    {
        std::string courses_path = "Data/" + schoolyear + "/Semester" + std::string(intStr) + "/" + courses_id + "/" + courses_id + ".csv";
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
        this->courses.insertAtTail(tmp);
    }
    f_courses_list.close();
}

void Semester::loadCourseData(std::string curYear) {
    char* intStr = new char[1];
    sprintf(intStr, "%d", this->semester_num);
    Node<Course>* cur = this->courses.pHead;
    while (cur) {
        std::string path = "Data/" + curYear + "/Semester" + std::string(intStr) + "/" + (cur->data).ID + "/";
        (cur->data).inputCSV(path + "StudentList.csv");
        (cur->data).loadScoreboard(path + "Point.csv");
        cur = cur->pNext;
    }
}

void Semester::createCourse(std::string curYear, Course& course) {
    std::cout << "\t\t\t CREATING A NEW COURSE - " << course.ID << "\n\n";

    std::cout << "\t - Enter the name of this course (Ex: Programming Techniques): ";
    std::cin.ignore();
    std::getline(std::cin, course.course_name);
    
    std::cout << "\t - Enter the class to which this course belongs (Ex: 23CLC03): ";
    std::getline(std::cin, course.class_name);
    
    std::cout << "\t - Enter the teacher of this course: ";
    std::getline(std::cin, course.teacher_name);
    
    std::cout << "\t - Enter the number of credits for this course (Ex: 4): ";
    std::cin >> course.num_of_credit;
    
    std::cout << "\t - Enter the maximum number of students for this course: ";
    std::cin >> course.max_student;
    
    std::cout << "\t - Enter the day of the week when this course will be held (Ex: MON/TUE/WED/THU/FRI/SAT): ";
    std::cin.ignore();
    std::getline(std::cin, course.day_of_week);
    
    std::cout << "\t- Here is a list of sessions:\n"
              << "\t\t 1. S1 (7:30 -> 9:15)\n"
              << "\t\t 2. S2 (9:30 -> 11:15)\n"
              << "\t\t 3. S3 (13:30 -> 15:15)\n"
              << "\t\t 4. S4 (15:30 -> 17:15)\n\n"
              << "\t - Enter the session for this course (Ex: S1): ";
    std::string sessionInput;
    std::getline(std::cin, sessionInput);
    
    if (sessionInput == "S1") course.session = "7:30 -> 9:15";
    else if (sessionInput == "S2") course.session = "9:30 -> 11:15";
    else if (sessionInput == "S3") course.session = "13:30 -> 15:15";
    else if (sessionInput == "S4") course.session = "15:30 -> 17:15";
    else {
        std::cerr << "Invalid session input!\n";
        cout << "Enter 0 to go back previous page";
        char select;
        cin >> select;
        if (select == '0') return;

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        return this->createCourse(curYear, course);
    }
    this->courses.insertAtTail(course);
    std::string path = "Data/" + curYear + "/Semester" + std::to_string(this->semester_num) + "/" + course.ID;
    createDirectory(path);
    std::ofstream fout(path + "/StudentList.csv");
    if (fout.is_open()) fout.close();
    fout.open(path + "/Point.csv");
    if (fout.is_open()) fout.close();
}

void Semester::viewCourseList() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    Node<Course>* cur = this->courses.pHead;
    int no = 1;

    std::cout << "+-----+---------------+--------------------+---------------+--------------------+----------+---------------+---------------+----------+\n";

    std::cout << "| " << std::left << std::setw(4) << "No";
    std::cout << "| " << std::left << std::setw(14) << "ID of Course";
    std::cout << "| " << std::left << std::setw(19) << "Course Name";
    std::cout << "| " << std::left << std::setw(14) << "Class Name";
    std::cout << "| " << std::left << std::setw(19) << "Teacher Name";
    std::cout << "| " << std::left << std::setw(9) << "Credits";
    std::cout << "| " << std::left << std::setw(14) << "Max Student";
    std::cout << "| " << std::left << std::setw(14) << "Day Of Week";
    std::cout << "| " << std::left << std::setw(9) << "Session" << "|\n";

    std::cout << "+-----+---------------+--------------------+---------------+--------------------+----------+---------------+---------------+----------+\n";

    while (cur != nullptr) {
        std::cout << "| " << std::left << std::setw(4) << no;
        std::cout << "| " << std::left << std::setw(14) << cur->data.ID;
        std::cout << "| " << std::left << std::setw(19) << cur->data.course_name;
        std::cout << "| " << std::left << std::setw(14) << cur->data.class_name;
        std::cout << "| " << std::left << std::setw(19) << cur->data.teacher_name;
        std::cout << "| " << std::left << std::setw(9) << cur->data.num_of_credit;
        std::cout << "| " << std::left << std::setw(14) << cur->data.max_student;
        std::cout << "| " << std::left << std::setw(14) << cur->data.day_of_week;
        std::cout << "| " << std::left << std::setw(9) << cur->data.session << "|\n";

        std::cout << "+-----+---------------+--------------------+---------------+--------------------+----------+---------------+---------------+----------+\n";

        no++;
        cur = cur->pNext;
    }
}

void Semester::updateCourse() {
    std::string course_id;
    std::cout << "- Enter the ID of the course you want to update: ";
    std::cin >> course_id;

    Node<Course>* cur = this->courses.pHead;
    std::cout << "\t\t UPDATING THE COURSE " << course_id << ": " << "\n\n";
    while (cur != nullptr) {
        if (cur->data.ID == course_id) {
            cout << "\tWhich information do you want to update?" << "\n";
            cout << "1. Course name" << "\n";
            cout << "2. Course ID" << "\n";
            cout << "3. Class name" << "\n";
            cout << "4. Teacher name" << "\n";
            cout << "5. Number of credits" << "\n";
            cout << "6. Maximum number of students" << "\n";
            cout << "7. Day of week" << "\n";
            cout << "8. Session" << "\n";
            cout << "9. All" << "\n";
            cout << "P/s: You can select multiple options separated by commas!" << "\n\n";
            cout << "- Your choice: ";
            std::string choice;
            std::cin.ignore();
            std::getline(std::cin, choice);
            std::stringstream ss(choice);
            std::string token;
            while (std::getline(ss, token, ',')) {
                if (token == "1") {
                    std::cout << "- Enter the new name of this course (Ex: Ky thuat lap trinh): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.course_name);
                }
                else if (token == "2") {
                    std::cout << "- Enter the new ID of this course (Ex: CSC10002-23CLC03): ";
                    std::cin >> cur->data.ID;
                }
                else if (token == "3") {
                    std::cout << "- Enter the new class which this course belongs to (Ex: 23CLC03): ";
                    std::getline(std::cin, cur->data.class_name);
                }
                else if (token == "4") {
                    std::cout << "- Enter the new teacher of this course: ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.teacher_name);
                }
                else if (token == "5") {
                    std::cout << "- Enter the new number of credits in this course (Ex: 4): ";
                    std::cin >> cur->data.num_of_credit;
                }
                else if (token == "6") {
                    std::cout << "- Enter the new maximum number of students in this course: ";
                    std::cin >> cur->data.max_student;
                }
                else if (token == "7") {
                    std::cout << "- Enter the new day of week when this course will be held (ex: MON/TUE/WED/THU/FRI/SAT): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.day_of_week);
                }
                else if (token == "8") {
                    std::cout << "- Here is the a list of sessions: " << "\n"
                        << "\t 1. S1 (7:30 -> 9:15)" << "\n"
                        << "\t 2. S2 (9:30 -> 11:15)" << "\n"
                        << "\t 3. S3 (13:30 -> 15:15)" << "\n"
                        << "\t 4. S4 (15:30 -> 17:15)" << "\n"
                        << "- Which sessions, this course will be held (Ex: S1): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.session);
                    if (cur->data.session == "S1") cur->data.session = "7:30 -> 9:15";
                    else if (cur->data.session == "S2") cur->data.session = "9:30 -> 11:15";
                    else if (cur->data.session == "S3") cur->data.session = "13:30 -> 15:15";
                    else cur->data.session = "15:30 -> 17:15";
                }
                else if (token == "9") {
                    std::cout << "- Enter the new name of this course (Ex: Ky thuat lap trinh): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.course_name);
                    std::cout << "- Enter the new ID of this course (Ex: CSC10002-23CLC03): ";
                    std::cin  >> cur->data.ID;
                    std::cout << "- Enter the new class which this course belongs to (Ex: 23CLC03): ";
                    std::getline(std::cin, cur->data.class_name);
                    std::cout << "- Enter the new teacher of this course: ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.teacher_name);
                    std::cout << "- Enter the new number of credits in this course (Ex: 4): ";
                    std::cin  >> cur->data.num_of_credit;
                    std::cout << "- Enter the new maximum number of students in this course: ";
                    std::cin  >> cur->data.max_student;
                    std::cout << "- Enter the new day of week when this course will be held (ex: MON/TUE/WED/THU/FRI/SAT): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.day_of_week);
                    std::cout << "- Here is the a list of sessions: " << "\n"
                              << "\t 1. S1 (7:30 -> 9:15)" << "\n"
                              << "\t 2. S2 (9:30 -> 11:15)" << "\n"
                              << "\t 3. S3 (13:30 -> 15:15)" << "\n"
                              << "\t 4. S4 (15:30 -> 17:15)" << "\n"
                              << "- Which sessions, this course will be held (Ex: S1): ";
                    std::cin.ignore();
                    std::getline(std::cin, cur->data.session);
                    if      (cur->data.session == "S1") cur->data.session = "7:30 -> 9:15";
                    else if (cur->data.session == "S2") cur->data.session = "9:30 -> 11:15";
                    else if (cur->data.session == "S3") cur->data.session = "13:30 -> 15:15";
                    else                                cur->data.session = "15:30 -> 17:15";
                }
                else {
                    cout << "Invalid choice!" << endl;
                    cout << "Enter 0 to go back previous page";
                    char select;
                    cin  >> select;
                    if (select == '0') return;
                    #ifdef _WIN32
                        system("cls");
                    #else
                        system("clear");
                    #endif
                    return updateCourse();
                }
            }    
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            std::cout << "\t - Course updated successfully!" << "\n";
            std::cout << "\nPress enter to continue...";
            std::cin.ignore();
            std::cin.get();
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
            return;
        }
        cur = cur->pNext;
    }
    std::cout << "\t - Course not found!" << "\n";
}

void Semester::deleteCourse(std::string year, std::string course_id) {
    Node<Course>* cur = this->courses.pHead;
    Node<Course>* prev = nullptr;
    while (cur != nullptr) {
        if (cur->data.ID == course_id) {
            if (prev == nullptr) this->courses.pHead = cur->pNext;
            else prev->pNext = cur->pNext;
            delete cur;
            break;
        }
        prev = cur;
        cur = cur->pNext;
    }
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "- Course not found!" << "\n";
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    // Delete all files in the folder of this course
    std::string folder_path = "Data/" + year + "/Semester" + std::to_string(this->semester_num) + "/" + course_id;
    std::string file_path_1 = folder_path + "/" + course_id + ".csv";
    std::string file_path_2 = folder_path + "/StudentList.csv";
    std::string file_path_3 = folder_path + "/Point.csv";
    system(("del " + file_path_1).c_str());
    system(("del " + file_path_2).c_str());
    system(("del " + file_path_3).c_str());
    system(("rmdir " + folder_path).c_str());
}

void Semester::createSemester(std::string year, int semester) {
    std::string path = "Data/" + year + "/Semester" + std::to_string(semester);
    createDirectory(path);
    LinkedList<Semester> s;
    Semester tmp;
    std::ifstream fIn("Data/" + year + "/Semester.txt");
    if (!fIn.is_open()) {
        return;
    }
    while (fIn >> tmp.semester_num) {
        char comma;
        fIn >> comma;
        getline(fIn, tmp.start_day, ',');
        getline(fIn, tmp.end_day);
        s.insertAtTail(tmp);
    }
    fIn.close();

    std::cout << "\t\t CREATING A NEW SEMESTER S" << semester << " IN " << year << "\n\n";
    this->semester_num = semester;
    std::cout << "- Enter the start date (Ex: 05/09/2023): ";
    std::cin  >> this->start_day;
    std::cout << "- Enter the end date (Ex: 20/01/2024): ";
    std::cin  >> this->end_day;
    s.insertAtTail(*this);
    std::ofstream fOut("Data/" + year + "/Semester.txt");
    if (!fOut.is_open()) {
        std::cout << "- Failed to open the file!" << "\n";
        return;
    }
    Node<Semester>* cur = s.pHead;
    while (cur) {
        fOut << cur->data.semester_num << "," << cur->data.start_day << "," << cur->data.end_day;
        cur = cur->pNext;
        if (cur)
            fOut << std::endl;
    }
    fOut.close();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "Create semester successfully!\n";
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
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

void Semester::saveData(std::string schoolyear, int semester) {
    char intStr[10];
    sprintf(intStr, "%d", semester);

    std::string courses_path = "Data/" + schoolyear + "/Semester" + std::string(intStr) + "/CourseList.txt";

    std::ofstream f_courses_list(courses_path);
    if (!f_courses_list.is_open()) {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return;
    }
    Node<Course>* cur = this->courses.pHead;
    while (cur) {
        Course currentCourse = cur->data;
        std::string course_data_path = "Data/" + schoolyear + "/Semester" + std::string(intStr) + "/" + currentCourse.ID + "/" + currentCourse.ID + ".csv";

        std::ofstream fout(course_data_path);
        if (!fout.is_open()) {
            std::cerr << "Error: Unable to open course data file for writing!" << std::endl;
            continue;
        }
        fout << "ID,Course name,Class name,Teacher name,num_of_credit,max student, day of week, session \n";
        fout << currentCourse.ID << "," << currentCourse.course_name << "," << currentCourse.class_name << "," << currentCourse.teacher_name << ","
            << currentCourse.num_of_credit << "," << currentCourse.max_student << "," << currentCourse.day_of_week << "," << currentCourse.session << std::endl;

        fout.close();
        f_courses_list << currentCourse.ID << std::endl;
        cur = cur->pNext;
    }

    f_courses_list.close();
}

void Semester::deallocate() {
    Node<Course>* cur = this->courses.pHead;
    while (cur) {
        cur->data.students.deallocate();
        cur->data.points.deallocate();
        cur = cur->pNext;
    }
    this->courses.deallocate();
}