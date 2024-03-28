#include "GeneralClass.hpp"


bool class_existed (std::string schoolYear, std::string general_class)
{
    std::string temp;
    std::ifstream fin;
    std::string path = "Data\\" + schoolYear + "\\GeneralClass.txt";
    fin.open ( path );
    if (!fin.is_open())
        return false;
    while ( !fin.eof() )
    {
        fin >> temp;
        if ( temp == general_class)
        {
            return true;
        }
    }
    fin.close();
    return false;
}

void list_of_student ( std::string curYear, std::string curClass)
{
    std::string ignore;
    std::string s;
    std::ifstream fin;
    std::string path = "Data\\GeneralClasses\\" + curYear + "\\" + curClass + ".csv";
    fin.open(path);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file ";
        return;
    }
    std::cout << "No \tStudent ID \tFirst name \tLast name \tGender \t\tDate of birth \t\tSocial ID \n";
    std::cout << "---------------------------------------------------------------------------------------------------------------\n";
    fin >> ignore;
    while ( !fin.eof() )
    {
        getline ( fin, s, ',');
        std::cout << s << " \t";
        getline ( fin, s, ',');
        std::cout << s << " \t";
        getline ( fin, s, ',');
        std::cout << s << " \t\t";
        getline ( fin, s, ',');
        std::cout << s << " \t\t";
        getline ( fin, s, ',');
        std::cout << s << " \t\t";
        getline ( fin, s, ',');
        std::cout << s << " \t\t";
        getline ( fin, s);
        std::cout << s << "\n";
    }
    fin.close();
    std::cout << "Enter to continue..." << std::endl;
    std::cin.get();
    std::cin.get();
}
bool create_General_class(std::string curYear, std::string curClass)
{
    LinkedList<std::string> ClassList;
    std::ifstream fin;
    fin.open("Data\\" + curYear + "\\GeneralClass.txt");
    if (!fin.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    std::string ge_class;
    while (!fin.eof()) {
        std::getline(fin, ge_class);
        ClassList.insertAtTail(ge_class);
    }
    fin.close();
    ClassList.insertAtTail(curClass);
    std::ofstream fout;
    fout.open("Data\\" + curYear + "\\GeneralClass.txt");
    if (!fout.is_open())
    {
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
    std::cout << "Create class successfully!...Enter to continue \n";
    std::cin.get();
    std::cin.get();
    return 1;
}
bool student_exist(std::string curYear, std::string curClass, std::string Student_id)
{
    ifstream fin;
    fin.open("Data\\GeneralClass" + curYear + "\\" + curClass + ".csv");
    if (!fin.is_open())
    {
        std::cerr << "error open " << curClass << ".csv";
        return false;
    }
    string studentcheck;
    string temp;
    string ignore;
    while (!fin.eof())
    {
        getline(fin, temp, ',');
        getline(fin, studentcheck, ',');
        if (studentcheck == Student_id)
        {
            fin.close();
            return true;
        }
        getline(fin, ignore);
    }
    return false;
}
bool add_1_student_to_class(std::string curYear, std::string curClass, Student_in_class Student)
{
    LinkedList<Student_in_class> Studentlist;
    std::ifstream fin;
    fin.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv");
    if (!fin.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    Student_in_class student_temp;
    char temp;
    while (!fin.eof())
    {
        fin >> student_temp.no;
        fin >> temp;
        getline(fin, student_temp.stu_id, ',');
        getline(fin, student_temp.first_name, ',');
        getline(fin, student_temp.last_name, ',');
        getline(fin, student_temp.gender, ',');
        getline(fin, student_temp.Date_of_birth, ',');
        getline(fin, student_temp.social_id);
        Studentlist.insertAtTail(student_temp);
    }
    fin.close();
    Studentlist.insertAtTail(Student);
    std::ofstream fout;
    fout.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv");
    if (!fout.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    Node<Student_in_class>* cur = Studentlist.pHead;
    while (cur)
    {
        fout << cur->data.no << ',' << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << ",";
        fout << cur->data.gender << "," << cur->data.Date_of_birth << "," << cur->data.social_id;
        fout << std::endl;
        cur = cur->pNext;
    }
    Studentlist.deallocate();
    fout.close();
    std::cout << "Add student successfully!...Enter to continue \n";
    std::cin.get();
    std::cin.get();
    return 1;
}
bool import_student_by_csv ( std::string curYear, std::string curClass, std::string input_file)
{
    std::ofstream fout;
    fout.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv", ios::app);
    if (!fout.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    std::ifstream fin;
    fin.open(input_file);
    if (!fin.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    std::string student;
    while ( !fin.eof() )
    {
        getline(fin,student,','); // no
        fout << student << ",";
        getline(fin,student,','); //stu_id
        fout << student << ",";
        getline(fin,student,','); // first_name
        fout << student << ",";
        getline(fin,student,','); // Last_name
        fout << student << ",";
        getline(fin,student,','); // gender
        fout << student << ",";
        getline(fin,student,','); // Birthday
        fout << student << ",";
        getline(fin,student); // social_id
        fout << student;
        fout << std::endl;
    }
    fin.close();
    fout.close();
    std::cout << "Add student successfully!...Enter to continue \n";
    return true;
}

