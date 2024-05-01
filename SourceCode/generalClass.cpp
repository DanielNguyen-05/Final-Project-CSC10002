#include "generalClass.hpp"

bool classExisted (std::string schoolYear, std::string general_class) {
    std::string temp;
    std::ifstream fin;
    std::string path = "Data/GeneralClasses/" + schoolYear + "/" + general_class + ".csv";
    fin.open (path);
    if (!fin.is_open()) return false;
    else {
        fin.close();
        return true;
    }
}

void listOfStudent(std::string curYear, std::string curClass) {
    std::string ignore;
    std::string s;
    std::ifstream fin;
    std::string path = "Data/GeneralClasses/" + curYear + "/" + curClass + ".csv";
    fin.open(path);
    if (!fin.is_open()) {
        std::cout << "Can't open " << curClass << ".csv !!!";
        return;
    }
    #ifdef _WIN32
   		system("cls");
	#else
		system("clear");
	#endif
    std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
    std::cout << "| No | Student ID  |  First name  |  Last name  | Gender | Date of birth  |    Social ID    |\n";
    std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
    int count = 1;
    getline(fin,ignore);
    while (getline(fin, s, ',')) {
        std::cout << "| " << std::setw(2) << s << " | ";
        getline(fin, s, ',');
        std::cout << std::setw(11) << s << " | ";
        getline(fin, s, ',');
        std::cout << std::setw(12) << s << " | ";
        getline(fin, s, ',');
        std::cout << std::setw(11) << s << " | ";
        getline(fin, s, ',');
        std::cout << std::setw(6) << s << " | ";
        getline(fin, s, ',');
        std::cout << std::setw(14) << s << " | ";
        getline(fin, s);
        std::cout << std::setw(15) << s << " |\n";
        std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
    }
    // std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
    fin.close();
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
    system("cls");
    #else
        system("clear");
    #endif
}

bool createGeneralClass(std::string curYear, std::string curClass) {
    LinkedList<std::string> ClassList;
    std::ifstream fin;
    fin.open("Data/GeneralClasses/" + curYear + "/GeneralClass.txt");
    if (!fin.is_open()) {
        std::cout << "Can't open file.";
        return 0;
    }
    std::string ge_class;
    while (!fin.eof()) {
        std::getline(fin, ge_class);
        if (ge_class != "")
        ClassList.insertAtTail(ge_class);
    }
    fin.close();
    ClassList.insertAtTail(curClass);
    std::ofstream fout;
    fout.open("Data/GeneralClasses/" + curYear + "/GeneralClass.txt");
    if (!fout.is_open()) {
        std::cout << "Can't open file.";
        return 0;
    }
    Node<std::string>* cur = ClassList.pHead;
    while (cur) {
        fout << cur->data;
        cur = cur->pNext;
        if (cur)
            fout << std::endl;
    }
    ClassList.deallocate();
    fout.close();
    fin.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fin.is_open()) {
        fout.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
        fout.close();
    }
    else
        fin.close();
    std::cout << "Create class successfully!\n";
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 1;
}

bool studentExistedInGeneralClass(std::string curYear, std::string curClass, std::string Student_id) {
    ifstream fin;
    fin.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fin.is_open()) {
        return false;
    }
    string studentcheck;
    string skip_no;
    string skip_first_line;
    string skip_behind_studentid;
    getline(fin, skip_first_line);
    while (!fin.eof()) {
        getline(fin, skip_no, ',');
        getline(fin, studentcheck, ',');
        if (studentcheck == Student_id) {
            fin.close();
            return true;
        }
        getline(fin, skip_behind_studentid);
    }
    return false;
}

bool addOneStudentToClass(std::string curYear, std::string curClass) {
    Student students;
    do {
        std::cout << "- Enter Student ID: ";
        std::cin >> students.stu_id;
        if (studentExistedInGeneralClass(curYear, curClass, students.stu_id)) {
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
            std::cout << "Student_ID " << students.stu_id << " has been already existed\n";
            std::cout << "\nPress enter to continue...";
            std::cin.ignore();
            std::cin.get();
			#ifdef _WIN32
				system("cls");
			#else
				system("clear");
			#endif
        }
    } while (studentExistedInGeneralClass(curYear, curClass, students.stu_id));
    std::cout << "- Enter First name: ";
    std::cin  >> students.first_name;
    std::cout << "- Enter Last name: ";
    std::cin  >> students.last_name;
    std::cout << "- Enter Gender: ";
    std::cin  >> students.gender;
    std::cout << "- Enter Date of birth (DD/MM/YYYY): ";
    std::cin  >> students.date_of_birth;
    std::cout << "- Enter Social ID: ";
    std::cin  >> students.soci_id;
    LinkedList<Student> Studentlist;

    std::ifstream fin;
    fin.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fin.is_open()) {
        std::cout << "Can't open file!";
        return 0;
    }
    Student student_temp;
    string skip_no;
    string skip_first_line;
    getline(fin, skip_first_line);
    while (!fin.eof()) {
        getline(fin, skip_no, ',');
        getline(fin, student_temp.stu_id, ',');
        getline(fin, student_temp.first_name, ',');
        getline(fin, student_temp.last_name, ',');
        getline(fin, student_temp.gender, ',');
        getline(fin, student_temp.date_of_birth, ',');
        getline(fin, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin.close();
    
    Studentlist.insertOrdered(students);
    std::ofstream fout;
    fout.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fout.is_open()) {
        std::cout << "Can't open file!";
        return 0;
    }
    Node<Student>* cur = Studentlist.pHead;
    int no = 1;
    while (cur) {
        fout << no << ',' << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << ",";
        fout << cur->data.gender << "," << cur->data.date_of_birth << "," << cur->data.soci_id;
        fout << std::endl;
        cur = cur->pNext;
        no++;
    }
    Studentlist.deallocate();
    fout.close();
    std::cout << "Add student successfully!\n";
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 1;
}

bool importStudent(std::string curYear, std::string curClass) {
    std::ifstream fin;
    fin.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fin.is_open())
        return 0;
    LinkedList<Student> Studentlist;
    Student student_temp;
    string skip_no;
    string skip_first_line;
    getline(fin, skip_first_line);
    while (!fin.eof()) {
        getline(fin, skip_no, ',');
        getline(fin, student_temp.stu_id, ',');
        getline(fin, student_temp.first_name, ',');
        getline(fin, student_temp.last_name, ',');
        getline(fin, student_temp.gender, ',');
        getline(fin, student_temp.date_of_birth, ',');
        getline(fin, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin.close();
    std::string input_file;
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "- Input the importing file path: ";
    std::cin.ignore();
    std::getline(std::cin, input_file);
    std::ifstream fin2;
    fin2.open(input_file);
    if (!fin2.is_open()) return 0;
    string skip_behind_studentID;
    getline(fin2, skip_first_line);
    while (!fin2.eof()) {
        getline(fin2, skip_no, ',');
        getline(fin2, student_temp.stu_id, ',');
        if (studentExistedInGeneralClass(curYear, curClass, student_temp.stu_id)) {
            getline(fin, skip_behind_studentID);
            continue;
        }
        getline(fin2, student_temp.first_name, ',');
        getline(fin2, student_temp.last_name, ',');
        getline(fin2, student_temp.gender, ',');
        getline(fin2, student_temp.date_of_birth, ',');
        getline(fin2, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin2.close();
    std::ofstream fout;
    fout.open("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fout.is_open()) return 0;
    Node <Student>* cur = Studentlist.pHead;
    int no = 1;
    while (cur != NULL) {
        fout << no << ',' << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << ",";
        fout << cur->data.gender << "," << cur->data.date_of_birth << "," << cur->data.soci_id;
        fout << std::endl;
        cur = cur->pNext;
        no++;
    }
    fout.close();
    Studentlist.deallocate();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    std::cout << "\tAdd student successfully!\n";
    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    return 1;
}

void viewScoreboard(std::string curYear, std::string curClass) {

    Semester curSemester;
    std::cout << "What semester do you want to view scoreboard: ";
    std::cin >> curSemester.semester_num;
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
        
    curSemester.loadSemesterData(curYear, curSemester.semester_num);
    curSemester.loadCourseData(curYear);
    std::ifstream fin("Data/GeneralClasses/" + curYear + "/" + curClass + ".csv");
    if (!fin.is_open()) return;
    StudentControl cur_stu;
    std::string ignore;
    Student stu;
    double GPA;
    std::string no;
    getline(fin, ignore);
    cout << "+----+------------+-----------+-----------+-------+" << endl;
    cout << "| No | Student ID |First Name | Last Name |  GPA  |" << endl;
    cout << "+----+------------+-----------+-----------+-------+" << endl;
    while (!fin.eof()) {
        getline(fin, no, ',');
        if (no == "") break;
        getline(fin, stu.stu_id, ',');
        getline(fin, stu.first_name, ',');
        getline(fin, stu.last_name, ',');
        getline(fin, ignore);
        cur_stu.loadStudentCoursesData(curSemester, stu.stu_id);
        GPA = cur_stu.calcGPA();
        cout << "| " << setw(2) << no << " | "
            << setw(10) << stu.stu_id << " | "
            << setw(9) << stu.first_name << " | "
            << setw(9) << stu.last_name << " | ";
        if(GPA != -1)
            cout << setw(5) << fixed << setprecision(2) << GPA << " |" << endl;
        else
            cout << setw(5) << "?" << " |" << endl;
        cout << "+----+------------+-----------+-----------+-------+" << endl;
    }
    fin.close();
    curSemester.deallocate();

    std::cout << "\nPress enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}