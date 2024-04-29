#include "course.hpp"
#include <sstream>

Course::Course(string ID, string course_name, string class_name, string teacher_name, int num_of_creadit, int max_student, string day_of_week, string session) {
	this->ID = ID;
	this->course_name = course_name;
	this->class_name = class_name;
	this->teacher_name = teacher_name;
	this->num_of_credit = num_of_creadit;
	this->max_student = max_student;
	this->day_of_week = day_of_week;
	this->session = session;
}

bool Course::studentExistedInCourse(string stu_id) {
	Node<Student>* cur = this->students.pHead;
	while (cur && cur->data.stu_id != stu_id)
		cur = cur->pNext;
	if (!cur)
		return false;
	return true;

}

void Course::inputCSV(string path) {
	ifstream fIn;
	fIn.open(path);
	if (!fIn.is_open()) return;
	string ignore = "";
	getline(fIn, ignore);
	while (!fIn.eof()) {
		Student stu;
		string tmp_no = "";
		getline(fIn, tmp_no, ',');
		getline(fIn, stu.stu_id, ',');
		if (!this->studentExistedInCourse(stu.stu_id)) {
			getline(fIn, stu.first_name, ',');
			getline(fIn, stu.last_name, ',');
			getline(fIn, stu.gender, ',');
			getline(fIn, stu.date_of_birth, ',');
			getline(fIn, stu.soci_id);
			if (tmp_no != "") this->students.insertOrdered(stu);
		}
		else getline(fIn, ignore);
	}
	fIn.close();
}

void Course::importScoreboard(string path) {
	ifstream fIn;
	fIn.open(path);
	if (!fIn.is_open()) return;
	string ignore;
	string tmp_no = "";
	Point pt;
	getline(fIn, ignore);
	while (!fIn.eof()) {
		getline(fIn, tmp_no, ',');
		if (tmp_no == "\n" || tmp_no == "") {
			fIn.close();
			return;
		}
		getline(fIn, pt.stu_id, ',');
		Node<Point>* cur = this->points.findNode(pt);
		if (cur != nullptr) {
			getline(fIn, (cur->data).full_name, ',');
			getline(fIn, (cur->data).overall, ',');
			getline(fIn, (cur->data).final, ',');
			getline(fIn, (cur->data).midterm, ',');
			getline(fIn, (cur->data).others);
		}
		else getline(fIn, ignore);
	}
	std::cout << "import succesfully\n";
    std::cout << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
	fIn.close();
}
void Course::loadScoreboard(string path) {
	ifstream fIn;
	fIn.open(path);
	if (!fIn.is_open()) return;
	string ignore;
	string tmp_no = "";
	Point pt;
	getline(fIn, ignore);
	while (!fIn.eof()) {
		getline(fIn, tmp_no, ',');
		if (tmp_no == "\n" || tmp_no == "") {
			fIn.close();
			return;
		}
		getline(fIn, pt.stu_id, ',');
		getline(fIn, pt.full_name, ',');
		getline(fIn, pt.overall, ',');
		getline(fIn, pt.final, ',');
		getline(fIn, pt.midterm, ',');
		getline(fIn, pt.others);
		this->points.insertOrdered(pt);
	}
	fIn.close();
}

void Course::exportScoreboard(string path) {
	ofstream fOut;
	fOut.open(path);
	if (!fOut.is_open()) {
		cerr << "Error: Unable to open file for writing!" << path << endl;
		std::cout << "Press enter to continue...";
		std::cin.ignore();
		std::cin.get();
		#ifdef _WIN32
			system("cls");
		#else
			system("clear");
		#endif
		return;
	}

	fOut << "No,StudentID,FullName,Overall,Final,Midterm,Others" << endl;
	int counter = 1;
	Node<Point>* cur = this->points.pHead;
	while (cur) {
		Point pt = cur->data;
		fOut	<< counter << "," 
				<< pt.stu_id << "," 
				<< pt.full_name << "," 
				<< pt.overall << ","
				<< pt.final << "," 
				<< pt.midterm << "," 
				<< pt.others;
		++counter;
		if (cur->pNext) fOut << endl;
		cur = cur->pNext;
	}
	fOut.close();
}
void Course::viewScoreboard() {
	if (!this->points.pHead) return;
	system("cls");
	std::cout << "+----+-------------+-----------------+---------------+--------------+---------------+-------------+\n";
	std::cout << "| No | Student ID  |    Full Name    | Overall Point | Final Point  | Midterm Point |    Others   |\n";
	std::cout << "+----+-------------+-----------------+---------------+--------------+---------------+-------------+\n";

	int no = 0;
	Node<Point>* cur = this->points.pHead;
	while (cur) {
		no++;
		std::cout << "| " << std::setw(2) << no << " | ";
		std::cout << std::setw(11) << cur->data.stu_id << " | ";
		std::cout << std::setw(15) << cur->data.full_name << " | ";
		std::cout << std::setw(13) << cur->data.overall << " | ";
		std::cout << std::setw(12) << cur->data.final << " | ";
		std::cout << std::setw(13) << cur->data.midterm << " | ";
		std::cout << std::setw(11) << cur->data.others << " |\n";
		cur = cur->pNext;
	}

	std::cout << "+----+-------------+-----------------+---------------+--------------+---------------+-------------+\n";
}
void Course::outputCSV(string path) {
	ofstream fOut;
	fOut.open(path);
	if (!fOut.is_open()) return;

	Node<Student>* cur = this->students.pHead;
	int no = 0;
	fOut << "no,stu_id,first_name,last_name,gender,date_of_birth,soci_id" << "\n";
	while (cur) {
		no++;
		fOut << no << ",";
		fOut << cur->data.stu_id << "," << cur->data.first_name << "," << cur->data.last_name << "," << cur->data.gender << "," << cur->data.date_of_birth << "," << cur->data.soci_id << "\n";
		cur = cur->pNext;
	}
	fOut.close();
}
void Course::viewStudent() {
	if (!this->students.pHead) return;
	system("cls");
	std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
	std::cout << "| No | Student ID  |  First name  |  Last name  | Gender | Date of birth  |    Social ID    |\n";
	std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";

	Node<Student>* cur = this->students.pHead;
	int no = 0;
	while (cur) {
		no++;
		std::cout << "| " << std::setw(2) << no << " | ";
		std::cout << std::setw(11) << cur->data.stu_id			<< " | ";
		std::cout << std::setw(12) << cur->data.first_name 		<< " | ";
		std::cout << std::setw(11) << cur->data.last_name 		<< " | ";
		std::cout << std::setw(6)  << cur->data.gender 			<< " | ";
		std::cout << std::setw(14) << cur->data.date_of_birth 	<< " | ";
		std::cout << std::setw(15) << cur->data.soci_id 		<< " |\n";
		cur = cur->pNext;
	}
	std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
}

void Course::updateResult() {
	string stu_id;
	std::cout << "\t- Enter student ID you want to update: ";
	std::cin >> stu_id;
	Point pt;
	pt.stu_id = stu_id;
	Node<Point>* stu = this->points.findNode(pt);
	if (stu == nullptr) {
		std::cout << "Student is not existed!";
	}
	else {
		cout << "\tWhich type of point do you want to update?\n";
		cout << "1. Others Point\n";
		cout << "2. Midterm Point\n";
		cout << "3. Final Point\n";
		cout << "4. Overall Point\n";
		cout << "5. All\n";
		cout << "P/s: You can select multiple options separated by commas!\n";
		cout << "\n\tYour choice: ";
		string choice;
		std::cin.ignore();
		std::getline(cin, choice);
		std::stringstream ss(choice);
		std::string token;
		while (std::getline(ss, token, ',')) {
			if (token == "1") {
				cout << "Others Point: ";
				cin  >> stu->data.others;
			}
			else if (token == "2") {
				cout << "Midterm Point: ";
				cin  >> stu->data.midterm;
			}
			else if (token == "3") {
				cout << "Final Point: ";
				cin  >> stu->data.final;
			}
			else if (token == "4") {
				cout << "Overall Point: ";
				cin  >> stu->data.overall;
			}
			else if (token == "5") {
				cout << "Others Point: ";
				cin  >> stu->data.others;
				cout << "Midterm Point: ";
				cin  >> stu->data.midterm;
				cout << "Final Point: ";
				cin  >> stu->data.final;
				cout << "Overall Point: ";
				cin  >> stu->data.overall;
			}
			else {
				cout << "Invalid choice!\n";
				cout << "Enter 0 to go back previous page";
				char select;
				cin  >> select;
				if (select == '0') return;

				system("cls");
				return updateResult();
			}
		}
		std::cout << "\t - Point updated successfully!\n";
		return;
	}
}

void Course::addStudent() {
	Student students;
	std::cout << "Enter student ID: ";
	std::cin >> students.stu_id;
	if (this->studentExistedInCourse(students.stu_id)) {
		std::cout << "This student is existed!";
		return;
	}
	std::cout << "Enter First name: ";
	std::cin  >> students.first_name;
	std::cout << "Enter Last name: ";
	std::cin  >> students.last_name;
	std::cout << "Enter Gender: ";
	std::cin  >> students.gender;
	std::cout << "Enter Date of birth: ";
	std::cin  >> students.date_of_birth;
	std::cout << "Enter Social ID: ";
	std::cin  >> students.soci_id;
	this->students.insertOrdered(students);
	Point pt;
	pt.stu_id 		= students.stu_id;
	pt.full_name 	= students.first_name + " " + students.last_name;
	pt.final 		= "?";
	pt.midterm 		= "?";
	pt.others 		= "?";
	pt.overall 		= "?";
	this->points.insertOrdered(pt);
}

void Course::deleteStudent() {
	Student stu;
	std::cout << "Enter student ID: ";
	std::cin  >> stu.stu_id;
	if (this->students.deleteNode(stu)) {
		std::cout << "Delete successfully!\n";
		Point pt;
		pt.stu_id = stu.stu_id;
		this->points.deleteNode(pt);
	}
	else std::cout << "Course does not have this student!\n";
}
void Course::matchStudentPoint() {
	Node<Student>* stu = this->students.pHead;
	while (stu) {
		Point pt;
		pt.stu_id = stu->data.stu_id;
		if (this->points.findNode(pt) == nullptr) {
			pt.full_name = stu->data.first_name + " " + stu->data.last_name;
			pt.final   = "?";
			pt.midterm = "?";
			pt.others  = "?";
			pt.overall = "?";
			this->points.insertOrdered(pt);
		}
		stu = stu->pNext;
	}
}
void Course::loadData(string curYear, int curSemester) {
	char* intStr = new char[1];
	sprintf(intStr, "%d", curSemester);
	this->inputCSV("Data/" + curYear + "/Semester" + std::string(intStr) + "/" + this->ID + "/StudentList.csv");
	this->loadScoreboard("Data/" + curYear + "/Semester" + std::string(intStr) + "/" + this->ID + "/Point.csv");
}
void Course::saveData(string curYear, int curSemester) {
	char* intStr = new char[1];
	sprintf(intStr, "%d", curSemester);
	this->outputCSV("Data/" + curYear + "/Semester" + std::string(intStr) + "/" + this->ID + "/StudentList.csv");
	this->exportScoreboard("Data/" + curYear + "/Semester" + std::string(intStr) + "/" + this->ID + "/Point.csv");
}
bool operator<(const Course::Point a, const Course::Point b) {
	return a.stu_id < b.stu_id;
}

bool operator>(const Course::Point a, const Course::Point b) {
	return a.stu_id > b.stu_id;
}

bool operator==(const Course::Point a, const Course::Point b) {
	return a.stu_id == b.stu_id;
}

bool operator!=(const Course::Point a, const Course::Point b) {
	return !(a == b);
}
