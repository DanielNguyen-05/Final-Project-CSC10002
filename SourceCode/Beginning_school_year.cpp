#include "Beginning_school_year.hpp"

bool year_exists ( std::string list_of_school_year, std::string year )
{
    std::ifstream fin;
    fin.open("Data\\School year\\" + list_of_school_year);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file.";
        return false;
    }
    std::string temp;
    while ( !fin.eof() )
    {
        fin >> temp;
        if ( temp == year)
        {
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;
}

void create_School_year ( std::string list_of_school_year, LinkedList <SchoolYear> &head )
{
    char choice = '1';
    std::ofstream fout;
    fout.open("Data\\School Year\\" + list_of_school_year, ios::app);
    if ( !fout.is_open() )
    {
        std::cout << "Can't open file!!!";
        return;
    }
    SchoolYear cur_year;
    while ( choice == '1')
    {
        std::cout << "Please enter school year: ";
        std::cin >> cur_year.year;
        if ( year_exists (list_of_school_year,cur_year.year) )
        {
            std::filesystem::create_directories("School year\\" + cur_year.year + "\\General Class");
            std::filesystem::create_directory ("School year\\" + cur_year.year + "\\Semester");
            fout << cur_year.year;
            fout << std::endl;
            head.insertAtTail(cur_year);
            break;
        }
        else 
        {
            std::cout << "The year " << cur_year.year << " already exists.\n";
        }
        std::cout << "Do you enter another year (Press 1) or press any key to cancle: ";
        std::cin >> choice;
    }
    fout.close();
}

bool class_exists ( std::string list_of_class , LinkedList<SchoolYear> &head, std::string cur_class)
{
    std::ifstream fin;
    fin.open("Data\\SchoolYear\\" + head.pHead->data.year + "\\General class\\" + list_of_class);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file.";
        return false;
    }
    std::string temp;
    while ( !fin.eof() )
    {
        fin >> temp;
        if ( temp == cur_class)
        {
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;;
}

void create_general_class ( std::string list_of_class , LinkedList<SchoolYear> &head)
{
    std::cout << "\t\t\tCREATING NEW GENERAL CLASS\n";
    std::ofstream fout;
    fout.open("Data\\School Year\\" + head.pHead->data.year + "\\General Class\\" + list_of_class, ios::app);
    if ( !fout.is_open() )
    {
        std::cout << "Can't open file !!!";
        return;
    }
    General_class cur_class;
    char choice = '1';
    while ( choice == '1')
    {
        std::cout << "Enter name of class :";
        std::cin >> cur_class.name_class;
        std::cout << "Name teacher: ";
        std::cin >> cur_class.name_teacher;
        while ( cur_class.number_of_student > 50)
        {
            std::cout << "Enter number of student ( max = 50 ):";
            std::cin >> cur_class.number_of_student;
            if ( cur_class.number_of_student > 50)
            {
                std::cout << "The number of students exceeds the allowable number\n";
            }
        }
        if ( class_exists (list_of_class,head, cur_class.name_class) )
        {
            fout << cur_class.name_class << "|" <<  cur_class.name_teacher << "|" << cur_class.number_of_student;
            fout << std::endl;
            head.pHead->data.Generalclass.insertAtTail(cur_class);
        }
        else
        {
            std::cout << "Class " << cur_class.name_class << " already exists \n";
        }
        std::cout << "Do you want add another class (Press 1) or any key to cancle:";
        std::cin >> choice;
    }
}

bool student_exist ( std::string cur_class, std::string year, std::string student_id)
{
    std::ifstream fin;
    fin.open("Data\\SchoolYear\\" + year + "\\General class\\" + cur_class);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file !!";
        return false;
    }
    std::string ignore;
    std::string temp;
    while ( !fin.eof() )
    {
        getline (fin, temp, ',');
        if ( temp == student_id)
        {
            return false;
        }
        getline (fin, ignore);
    }
    fin.close();
    return;
}

void add_student_to_class ( std::string list_of_class, LinkedList<SchoolYear> &head)
{
    std::cout << "\t\t\tADD STUDENT TO THE CLASS \n";
    char choice = '1';
    while ( choice == '1')
    {
        char choice1 = '1';
        std::string cur_class;
        while ( choice = '1')
        {
            std::cout << "Enter the class you want to add student: ";
            std::cin >> cur_class;
            if ( !class_exists ( list_of_class, head, cur_class) )
            {
                break;
            }
            else
            {
                std::cout << "Class " << cur_class << " dose not exist\n";
            }
            std::cout << "Do you want add another class (Press 1) or any key to cancle:";
            std::cin >> choice1;
            if ( choice1!= '1')
            {
                return;
            }
        }
        std::ofstream fout; 
        fout.open( "Data\\SchoolYear\\" + head.pHead->data.year + "\\General class\\" + cur_class + ".csv");
        Student cur_student;
        char choice2 = '1';
        int count = 1;
        while ( choice2 == '1')
        {
            cur_student.no = count;
            std::cout << "Enter Student ID: ";
            std::cin >> cur_student.stu_id;
            if ( student_exist( cur_class + ".csv" , head.pHead->data.year, cur_student.stu_id) )
            {
                std::cout << "Enter first name: ";
                std::cin >> cur_student.first_name;
                std::cout << "Enter last name: ";
                std::cin >> cur_student.last_name;
                std::cout << "Enter gender: ";
                std::cin >> cur_student.gender;
                std::cout << "Enter date of birth: ";
                std::cin >> cur_student.date_of_birth;
                std::cout << "Enter social ID: ";
                std::cin >> cur_student.soci_id;
                fout << cur_student.no << "," << cur_student.stu_id << "," << cur_student.first_name << "," << cur_student.last_name << ",";
                fout << cur_student.gender << "," << cur_student.date_of_birth << "," << cur_student.soci_id;
                fout << std::endl;
                count++;
                head.pHead->data.Generalclass.pHead->data.student.insertAtTail(cur_student);
            }
            else
            {
                std::cout << "Student ID " <<  cur_student.stu_id << " already exist.\n";
            }
            std::cout << "Do you want add another student ( press 1) or press any key to cancle: ";
            std::cin >> choice2;
        }
        std::cout << "Do you want add another class ( press 1) or press any key to cancle: ";
        std::cin >> choice;
    }   
}

void add_quick_student_to_class ( std::string list_of_class, LinkedList<SchoolYear> &head)
{
    char choice = '1';
    while ( choice == '1')
    {
        char choice1 = '1';
        std::string cur_class;
        while ( choice = '1')
        {
            std::cout << "Enter the class you want to add student: ";
            std::cin >> cur_class;
            if ( !class_exists ( list_of_class, head, cur_class) )
            {
                break;
            }
            else
            {
                std::cout << "Class " << cur_class << " dose not exist\n";
            }
            std::cout << "Do you want add another class (Press 1) or any key to cancle:";
            std::cin >> choice1;
            if ( choice1 != '1')
            {
                return;
            }
        }
        std::ifstream fin; 
        fin.open( "Data\\SchoolYear\\" + head.pHead->data.year + "\\General class\\" + cur_class + ".csv");
        Student cur_student;
        char choice2 = '1';
        int count = 1;
        char ignore;
        while ( !fin.eof() )
        {
            fin >> cur_student.no;
            fin >> ignore;
            getline (fin, cur_student.stu_id, ',');
            if ( student_exist( cur_class + ".csv" , head.pHead->data.year, cur_student.stu_id) )
            {
                getline (fin, cur_student.first_name, ',');
                getline (fin, cur_student.last_name, ',');
                getline (fin, cur_student.gender, ',');
                getline (fin, cur_student.date_of_birth, ',');
                getline (fin, cur_student.soci_id);
                head.pHead->data.Generalclass.pHead->data.student.insertAtTail(cur_student);
            }
            else
            {
                std::cout << "Student ID " <<  cur_student.stu_id << " already exist.\n";
                std::string temp;
                getline ( fin, temp);
            }
        }
        std::cout << "Do you want add another class ( press 1) or press any key to cancle: ";
        std::cin >> choice;
    }   
}

