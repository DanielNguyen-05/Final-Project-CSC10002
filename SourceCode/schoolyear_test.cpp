#include "schoolyear_test.hpp"
#include <sstream>
#include <fstream>

void SchoolYear::createSchoolYear(std::string path) {
    std::cout << "\t\t\t CREATING NEW SCHOOL YEAR" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the school year: ";
    std::ofstream fOut(path);
    if (!fOut.is_open()) {
        std::cout << "\t -File not found!" << "\n";
        return;
    }
    fOut << year;
}

void SchoolYear::createGeneralClass(std::string path) {
    std::cout << "\t\t\t CREATING A NEW GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the new General Class: ";
    std::cin >> class_name;

    std::ofstream fOut(path);
    if (!fOut.is_open()) {
        std::cout << "\t -Failed to open the file!" << "\n";
        return;
    }
    fOut << year << "\n";
    fOut << class_name << "\n";
    fOut.close();
}


void SchoolYear::importStudentsToGeneralClassFromCSV(std::string path) {
    std::cout << "\t\t\t ADDING STUDENT TO GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the General Class: ";
    std::cin >> class_name;

    std::ifstream fIn(path);
    if (!fIn.is_open()) {
        std::cout << "\t -File not found!" << "\n";
        return;
    }
    std::string ignore = "";
    std::getline(fIn, ignore);
    while (!fIn.eof()) {
        Student stu;
        std::getline(fIn, stu.stu_id, ',');
        std::getline(fIn, stu.first_name, ',');
        std::getline(fIn, stu.last_name, ',');
        std::getline(fIn, stu.gender, ',');
        std::getline(fIn, stu.date_of_birth, ',');
        std::getline(fIn, stu.soci_id);

		this->students.insertOrdered(stu);
    }
    fIn.close();
}

void Semester::createSemester() {
    std::cout << "\t\t\t CREATING A NEW SEMESTER" << "\n\n";

    std::string semester_num;
    std::cout << "\t - Enter a new file semester save in: ";
    std::cin >> semester_num;
    std::ofstream fOut("Data//SchoolYear-Course//Semester//semester" + semester_num + ".csv");
    if (!fOut.is_open()) {
        std::cout << "\t -Failed to open the file!" << "\n";
        return;
    }
    label:
        std::cout << "\t\t\t CREATING A NEW SEMESTER" << "\n\n" ;
        std::cout << "\t - Enter a new semester number which you want to create (ex: 1): ";
        std::cin >> this->semester_num;
        fOut << this->semester_num << ", ";
        std::cout << "\t - Enter the start date (ex: 05/09/2023): ";
        std::cin >> this->start_day;
        fOut << this->start_day << ", ";
        std::cout << "\t - Enter the end date (ex: 20/01/2024): ";
        std::cin >> this->end_day;
        fOut << this->end_day << "\n";

    int choice;
    // chỗ này đưa cái table của Trâm Võ vô
    if (choice == 1) goto label;
    else if (choice == 2);  // đưa cái hàm để quay lại 6.2.a
    else if (choice == 0);  // đưa cái hàm để quay laị VI

    fOut.close();
}



// void SchoolYear::createSchoolYear() {
//     std::cout << "\t\t\t CREATING NEW SCHOOL YEAR" << "\n\n";
//     std::string year;
//     std::cout << "\t -Please input the year of the school year: ";
    
//     std::cout << "\n" << "\t -Please input path of file ypu want to save year in: ";
//     std::string output_path;
//     std::cin >> output_path;

//     std::ofstream fOut(output_path);
//     if (!fOut.is_open()) {
//         std::cout << "\t -File not found!" << "\n";
//         return;
//     }
//     fOut << year << ", ";
//     fOut.close();
// }

// void SchoolYear::createGeneralClass() {
//     std::cout << "\t\t\t CREATING A NEW GENERAL CLASS" << "\n\n";

//     std::cout << "\n" << "\t -Please input the path of the file you want to save General Class in: ";
//     std::string output_path;
//     std::cin >> output_path;

//     std::ofstream fOut(output_path);
//     if (!fOut.is_open()) {
//         std::cout << "\t -Failed to open the file!" << "\n";
//         return;
//     }
//     std::string year;
//     std::cout << "\t -Please input the year of the School Year: ";
//     fOut << year;
//     std::string class_name;
//     std::cout << "\t -Please input the name of the new General Class: ";
//     fOut << class_name;
//     fOut.close();
// }


// void SchoolYear::importStudentsToGeneralClassFromCSV() {
//     std::cout << "\t\t\t ADDING STUDENT TO GENERAL CLASS" << "\n\n";
//     std::string year;
//     std::cout << "\t -Please input the year of the School Year: ";
//     std::cin >> year;
//     std::string class_name;
//     std::cout << "\t -Please input the name of the General Class: ";
//     std::cin >> class_name;

//     std::string input_path;
//     std::cout << "\n" << "\t -Please input the path of the input file you want to get students: ";
//     std::cin >> input_path;

//     std::string output_path;
//     std::cout << "\n" << "\t -Please input the path of the output file you want to save students in: ";
//     std::cin >> output_path;

//     std::ifstream fIn(input_path);
//     if (!fIn.is_open()) {
//         std::cout << "\t -File not found!" << "\n";
//         return;
//     }
//     std::string ignore = "";
//     std::getline(fIn, ignore);
//     while (!fIn.eof()) {
//         Student stu;
//         std::getline(fIn, stu.stu_id, ',');
//         std::getline(fIn, stu.first_name, ',');
//         std::getline(fIn, stu.last_name, ',');
//         std::getline(fIn, stu.gender, ',');
//         std::getline(fIn, stu.date_of_birth, ',');
//         std::getline(fIn, stu.soci_id);

// 		this->students.insertOrdered(stu);
//     }
//     fIn.close();
// }