#include <fstream>
#include <iostream>
#include <header.hpp>

SchoolYear * create_school_year ( std::string s)
{
    SchoolYear * new_node = new SchoolYear;
    new_node->year = s;
    new_node->semesters = NULL;
    new_node->activity_class = NULL;
    return new_node;
}

void add_school_year_to_list ( List &p, std::string s)
{
    //SchoolYear * new_node = create_school_year(s);
    ListNode * new_list = new ListNode;
    new_list->data = create_school_year(s);
    new_list->pNext = NULL;
    if ( p.pHead ==  NULL)
    {
        p.pHead = new_list;
        return;
    }
    ListNode * cur = p.pHead;
    while ( cur->pNext != NULL )
    {
        cur = cur->pNext;
    }
    cur->pNext = new_list;
}
// Lớp sinh hoạt
void add_class_to_school_year (std::string classname, std::string teachername, int number_student, SchoolYear * &phead )  
{
    Classes * new_class = new Classes;
    new_class->class_name = classname;
    new_class->teacher_name = teachername;
    new_class->max_student = number_student;
    new_class->in_class_activity = NULL;
    new_class->pNext = NULL;
    if ( phead->activity_class == NULL )
    {
        phead->activity_class = new_class;
        return;
    }
    Classes * cur  = phead->activity_class;
    while ( cur->pNext != NULL)
    {
        cur = cur->pNext;
    }
    cur->pNext = new_class;
}
// Nhập bằng tay
void add_student_to_class ( int no, int student_id, std::string lastname, std::string firstname, std::string gender, std::string date_of_birth, std::string social_id, Classes *&phead)
{
    Students * new_student = new Students;
    new_student->no = no;
    new_student->stu_id = student_id;
    new_student->first_name = firstname;
    new_student->last_name = lastname;
    new_student->gender = gender;
    new_student->date_of_birth = date_of_birth;
    new_student->soci_id = social_id;
    new_student->pNext = NULL;
    if ( phead->in_class_activity == NULL)
    {
        phead->in_class_activity = new_student;
        return;
    }
    Students * cur = phead->in_class_activity;
    while ( cur->pNext != NULL )
    {
        cur = cur->pNext;
    }
    cur->pNext = new_student;
}

// Nhập bằng CSV file 
bool read_file_CSV ( std::string input_file, Classes * &phead)
{
    std::string no;
    std::string stu_id;
    std::string first_name;
    std::string last_name;
    std::string gender;
    std::string date_of_birth;
    std::string soci_id;
    std::ifstream fin;
    fin.open(input_file);
    if ( !fin.is_open() )
    {
        std::cout << "Error";
        return false;
    }
    while ( !fin.eof() )
    { 
        getline ( fin, no, ',');
        int no_1 = stoi(no);
        getline ( fin, stu_id, ',');
        int stu_id_2 = stoi (stu_id);
        getline(fin, first_name, ',');
        getline (fin, last_name, ',');
        getline(fin, gender, ',');
        getline (fin, date_of_birth, ',');
        getline ( fin , soci_id );
        add_student_to_class(no_1,stu_id_2,last_name,first_name,gender,date_of_birth,soci_id, phead);
    }
    fin.close();
    return true;
}

