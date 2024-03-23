#include "schoolyear_test.hpp"
#include <sstream>
#include <fstream>

void SchoolYear::createSchoolYear() {
    std::cout << "\t\t\t CREATING NEW SCHOOL YEAR" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the school year: ";
    std::cin >> year;
}

void SchoolYear::createGeneralClass() {
    std::cout << "\t\t\t REATING A NEW GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the new General Class: ";
    std::cin >> class_name;
}

void SchoolYear::importStudentsToGeneralClassFromCSV(std::string path) {
    std::cout << "\t\t\t ADDING STUDENT TO GENERAL CLASS" << "\n\n";
    std::string year;
    std::cout << "\t -Please input the year of the School Year: ";
    std::cin >> year;
    std::string class_name;
    std::cout << "\t -Please input the name of the General Class: ";
    std::cin >> class_name;

	ifstream fIn(path);
	string ignore = "";
	getline(fIn, ignore);
	while (!fIn.eof()) {
		Student stu;
		string tmp_no = "";
		getline(fIn, tmp_no, ',');
		if (tmp_no == "")
			return;
		getline(fIn, stu.stu_id, ',');
		getline(fIn, stu.first_name, ',');
		getline(fIn, stu.last_name, ',');
		getline(fIn, stu.gender, ',');
		getline(fIn, stu.date_of_birth, ',');
		getline(fIn, stu.soci_id);

		this->students.insertOrdered(stu);
	}
	fIn.close();
}
