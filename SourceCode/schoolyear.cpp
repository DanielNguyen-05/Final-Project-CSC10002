#include "schoolyear.hpp"

bool year_exits (  std::string curyear )
{
    std::ifstream fIn("Data\\SchoolYear.txt");
    if (!fIn.is_open()) {
        std::cerr << "error open SchoolYear.txt";
        return false;
    }
    string yearCheck;
    while (!fIn.eof()) {
        std::getline(fIn, yearCheck);
        if (yearCheck == curyear) {
            fIn.close();
            return true;
        }
    }
    fIn.close();
    return false;
}

bool create_School_year(std::string curYear)
{
    LinkedList<std::string> yearList;
    std::ifstream fin;
    fin.open("Data\\SchoolYear.txt");
    if (!fin.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    std::string year;
    while (!fin.eof()) {
        std::getline(fin, year);
        yearList.insertOrdered(year);
    }
    fin.close();
    yearList.insertOrdered(curYear);
    std::ofstream fout;
    fout.open("Data\\SchoolYear.txt");
    if (!fout.is_open())
    {
        std::cout << "Can't open file.";
        return 0;
    }
    std::string path = "Data\\" + curYear;
    std::wstring folder(path.begin(), path.end());
    if (!CreateDirectory(folder.c_str(), NULL)) {
        std::cout << "can't create folder schoolYear, please try again" << std::endl;
    }
    Node<std::string>* cur = yearList.pHead;
    while (cur) {
        fout << cur->data << std::endl;
        cur = cur->pNext;
    }
    yearList.deallocate();
    fout.close();
    std::cout << "Create schoolYear successfully!...Enter to continue \n";
    std::cin.get();
    std::cin.get();
}
