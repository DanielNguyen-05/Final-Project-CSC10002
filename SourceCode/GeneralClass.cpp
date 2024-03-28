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

