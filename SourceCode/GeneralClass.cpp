#include "GeneralClass.hpp"

bool class_existed ( std::string cur_year, std::string cur_class)
{
    std::ifstream fin;
    fin.open("Data\\" + cur_year + "\\GeneralClass.txt");
    if ( !fin.is_open() )
    {
        std::cerr << "error open GeneralClass.txt";
        return false;
    }
    string classcheck;
    while ( !fin.eof() )
    {
        std::getline(fin, classcheck);
        if (classcheck == cur_class) {
            fin.close();
            return true;
        }
    }
    return false;
}

bool create_General_class(std::string curYear, std::string curClass)
{
    LinkedList<std::string> ClassList;
    std::ifstream fin;
    fin.open("Data\\" + curYear + "\\GeneralClass.txt" );
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
    std::string path = "Data\\" + curYear + "\\" + curClass + "\\Student.csv" ;
    std::wstring folder(path.begin(), path.end());
    if (!CreateDirectory(folder.c_str(), NULL)) {
        std::cout << "can't create folder class, please try again" << std::endl;
    }
    Node<std::string>* cur = ClassList.pHead;
    while (cur) {
        fout << cur->data << std::endl;
        cur = cur->pNext;
    }
    ClassList.deallocate();
    fout.close();
    std::cout << "Create class successfully!...Enter to continue \n";
    std::cin.get();
    std::cin.get();
    return 1;
}