#include "schoolyear.hpp"

bool yearExisted(std::string year) {
    std::ifstream fin;
    fin.open("Data/SchoolYear.txt");
    if (!fin.is_open()) {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        welcomePage();
        std::cerr << "School year is not existed !!!";
        return false;
    }
    std::string temp;
    while (!fin.eof()) {
        fin >> temp;
        if (temp == year) {
            fin.close();
            return false;
        }
    }
    fin.close();
    return true;
}

bool yearValid(std::string curyear)
{
    if (curyear.length() != 9) return false;
    std::string start_year = curyear.substr(0, 4);
    std::string end_year = curyear.substr(5, 4);
    int startyear = stoi(start_year);
    int endyear = stoi(end_year);
    if (startyear < 1996 || endyear < 1996 || startyear >= endyear) return false;
    return true;
}

bool createSchoolYear(std::string curYear) {
    if (!yearValid(curYear)) {
        welcomePage();
        std::cout << "\tInvalid year!!!\n";
        std::cout << "\nPress enter to continue...";
        std::cin.ignore();
        std::cin.get();
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
        return 0;
    }
    LinkedList<std::string> yearList;
    std::ifstream fin;
    fin.open("Data/SchoolYear.txt");
    if (!fin.is_open()) {
        welcomePage();
        std::cerr << "School year is not existed !!!";
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
    fout.open("Data/SchoolYear.txt");
    if (!fout.is_open()) {
        welcomePage();
        std::cerr << "School year is not existed !!!";
        return 0;
    }
    std::string path = "Data/" + curYear;
    createDirectory(path);
    createDirectory("Data/GeneralClasses/" + curYear);
    std::ofstream fOut("Data/GeneralClasses/" + curYear + "/GeneralClass.txt" );
    fOut.close();
    std::ofstream semester(path + "/semester.txt");

    if (semester.is_open()) {
        semester.close();
    }
    else
    {
        welcomePage();
        std::cerr << "Failed to create file!\n";
    }
        
    Node<std::string>* cur = yearList.pHead;
    while (cur) {
        fout << cur->data;
        cur = cur->pNext;
        if (cur)
            fout << std::endl;
    }
    yearList.deallocate();
    fout.close();
    welcomePage();
    std::cout << "\tThis school year is created successfully!\n";
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