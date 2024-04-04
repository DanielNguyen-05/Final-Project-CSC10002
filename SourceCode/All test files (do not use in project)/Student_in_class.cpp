#include "student.hpp"
#include <fstream>

bool student_exist (std::string curYear, std::string curClass, std::string Student_id)
{
    ifstream fin;
    fin.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv" );
    if ( !fin.is_open() )
    {
        std::cerr << "error open " << curClass << ".csv";
        return false;
    }
    string studentcheck;
    string skip_no;
    string skip_first_line;
    string skip_behind_studentid;
    getline(fin, skip_first_line);
    while ( !fin.eof() )
    {
        getline ( fin, skip_no, ',');
        getline (fin, studentcheck, ',');
        if ( studentcheck == Student_id)
        {
            fin.close();
            return true;
        }
        getline ( fin, skip_behind_studentid);
    }
    return false;
}

bool add_1_student_to_class ( std::string curYear, std::string curClass)
{
    Student students;
    do
    {
        std::cout << "Enter Student ID: ";
        std::cin >> students.stu_id;
        if ( student_exist(curYear, curClass, students.stu_id))
        {
            std::cout << "Student_ID " << students.stu_id << " already exist\n";
        }
    } while (student_exist(curYear,curClass,students.stu_id));
    std::cout << "Enter First name: ";
    std::cin >> students.first_name;
    std::cout << "Enter Last name: ";
    std::cin >> students.last_name;
    std::cout << "Enter Gender: ";
    std::cin >> students.gender;
    std::cout << "Enter Date of birth: ";
    std::cin >> students.date_of_birth;
    std::cout << "Enter Social ID: ";
    std::cin >> students.soci_id;
    LinkedList<Student> Studentlist;
    std::ifstream fin;
    fin.open ( "Data\\" + curYear + "\\" + curClass + "\\Student.csv" );
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file.";
        return 0;
    }
    Student student_temp;
    string skip_no;
    string skip_first_line;
    getline ( fin, skip_first_line);
    while ( !fin.eof() )
    {
        getline(fin,skip_no, ',');
        getline( fin, student_temp.stu_id, ',');
        getline( fin, student_temp.first_name, ',');
        getline( fin, student_temp.last_name, ',');
        getline( fin, student_temp.gender, ',');
        getline( fin, student_temp.date_of_birth, ',');
        getline (fin, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin.close();
    Studentlist.insertOrdered(students);
    std::ofstream fout;
    fout.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv" );
    if (!fout.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    Node<Student>* cur = Studentlist.pHead;
    int no = 1;
    while (cur) 
    {
        fout << no << ',' << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << ",";
        fout << cur->data.gender << "," << cur->data.date_of_birth << "," << cur->data.soci_id;
        fout << std::endl;
        cur = cur->pNext;
        no++;
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
    std::ifstream fin;
    fin.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv");
    if (!fin.is_open())
    {
        std::cout << "Can't open file Student.csv.";
        return 0;
    }
    LinkedList<Student> Studentlist;
    Student student_temp;
    string skip_no;
    string skip_first_line;
    getline ( fin, skip_first_line);
    while ( !fin.eof() )
    {
        getline(fin,skip_no, ',');
        getline( fin, student_temp.stu_id, ',');
        getline( fin, student_temp.first_name, ',');
        getline( fin, student_temp.last_name, ',');
        getline( fin, student_temp.gender, ',');
        getline( fin, student_temp.date_of_birth, ',');
        getline (fin, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin.close();
    std::ifstream fin2;
    fin2.open(input_file);
    if (!fin.is_open())
    {
        std::cout << "Can't open file " << input_file;
        return 0;
    }
    string skip_behind_studentID;
    getline(fin2,skip_first_line);
    while ( !fin2.eof() )
    {
        getline(fin2,skip_no, ',');
        getline( fin2, student_temp.stu_id, ',');
        if ( student_exist(curYear,curClass, student_temp.stu_id))
        {
            getline (fin, skip_behind_studentID);
            continue;
        }
        getline( fin2, student_temp.first_name, ',');
        getline( fin2, student_temp.last_name, ',');
        getline( fin2, student_temp.gender, ',');
        getline( fin2, student_temp.date_of_birth, ',');
        getline (fin2, student_temp.soci_id);
        Studentlist.insertOrdered(student_temp);
    }
    fin2.close();
    std::ofstream fout;
    fout.open("Data\\" + curYear + "\\" + curClass + "\\Student.csv");
    if (!fout.is_open())
    {
        std::cout << "Can't open file Student.csv";
        return 0;
    }
    Node <Student> * cur = Studentlist.pHead;
    int no = 1;
    while ( cur!= NULL )
    {
        fout << no << ',' << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << ",";
        fout << cur->data.gender << "," << cur->data.date_of_birth << "," << cur->data.soci_id;
        fout << std::endl;
        cur = cur->pNext;
        no++;
    }
    fout.close();
    std::cout << "Add student successfully!...Enter to continue \n";
}