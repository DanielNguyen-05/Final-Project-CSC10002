#include <iostream>
#include <string>
#include <fstream>

void view_list_of_general_class ( std::string input_file_generalclass )
{
    std::ifstream fin;
    std::string s;
    fin.open(input_file_generalclass);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file. ";
        return;
    }
    while ( !fin.eof() )
    {
        fin >> s;
        std::cout << s << "\n";
    }
    fin.close();
}

bool class_existed ( std::string  input_file_generalclass, std::string general_class)
{
    std::string temp;
    std::ifstream fin;
    fin.open ( input_file_generalclass );
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

void list_of_student ( std::string list_stu_of_generalclass)
{
    std::string ignore;
    std::string s;
    std::ifstream fin;
    fin.open(list_stu_of_generalclass);
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
}


void view_list_of_stu_in_class ( std::string input_file_generalclass)
{
    char c = '1';
    std::string general_class;
    std::ifstream fin;
    fin.open(input_file_generalclass);
    if ( !fin.is_open() )
    {
        std::cout << "Can't open file: ";
        return;
    }
    while ( c == '1' )
    {
        std::cout << "Enter the name of General Class (ex: 23CLC03): ";
        std::cin >> general_class;
        if ( class_existed(input_file_generalclass,general_class) )
        {
            std::cout << "\t\t\tHere is the list of students in the class " << general_class;
            list_of_student( "Data\\SchoolYear\\GeneralClass\\" + general_class + ".csv");
        }
        else 
        {
            std::cout <<"The class "<< general_class << " is not existed! \n";
            std::cout << "Please check the information again! \n";
        }
        std::cout << "Do you want to see another class list (Press 1) Or press any key to cancel: ";
        std::cin >> c;
    }
}