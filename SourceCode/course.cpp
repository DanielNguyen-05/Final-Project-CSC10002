#include "course.hpp"

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

bool Course::stu_exists(string stu_id) {
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
		if (!this->stu_exists(stu.stu_id)) {
			getline(fIn, stu.first_name, ',');
			getline(fIn, stu.last_name, ',');
			getline(fIn, stu.gender, ',');
			getline(fIn, stu.date_of_birth, ',');
			getline(fIn, stu.soci_id);
			if (tmp_no != "")
				this->students.insertOrdered(stu);
		}
		else
			getline(fIn, ignore);
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
		cerr << "Error: Unable to open file for writing! -- " << path << endl;
		system("pause");
		return;
	}

	fOut << "No,StudentID,FullName,Overall,Final,Midterm,Others" << endl;
	int counter = 1;
	Node<Point>* cur = this->points.pHead;
	while (cur) {
		Point pt = cur->data;
		fOut << counter << "," << pt.stu_id << "," << pt.full_name << "," << pt.overall << ","
			<< pt.final << "," << pt.midterm << "," << pt.others;
		++counter;
		if (cur->pNext)
			std::cout << endl;
		cur = cur->pNext;
	}
	fOut.close();
}
void Course::viewScoreboard() {
	if (!this->points.pHead) return;
	system("cls");
	std::cout << "+----+-------------+-----------------+---------------+--------------+---------------+-------------+\n";
	std::cout << "| No | Student ID  | Full Name       | Overall Point | Final Point  | Midterm Point | Others      |\n";
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
	std::cout << "| No | Student ID  | First name   | Last name   | Gender | Date of birth  | Social ID       |\n";
	std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";

	Node<Student>* cur = this->students.pHead;
	int no = 0;
	while (cur) {
		no++;
		std::cout << "| " << std::setw(2) << no << " | ";
		std::cout << std::setw(11) << cur->data.stu_id << " | ";
		std::cout << std::setw(12) << cur->data.first_name << " | ";
		std::cout << std::setw(11) << cur->data.last_name << " | ";
		std::cout << std::setw(6) << cur->data.gender << " | ";
		std::cout << std::setw(14) << cur->data.date_of_birth << " | ";
		std::cout << std::setw(15) << cur->data.soci_id << " |\n";
		cur = cur->pNext;
	}

	std::cout << "+----+-------------+--------------+-------------+--------+----------------+-----------------+\n";
}

void Course::updateResult() {
	string stu_id;
	std::cout << "Enter student ID you want to update:";
	std::cin >> stu_id;
	Point pt;
	pt.stu_id = stu_id;
	if (!this->stu_exists(stu_id)) {
		std::cout << "Student is not existed\n";
		system("pause");
		return;
	}
	Node<Point>* stu = this->points.findNode(pt);
	if (stu == nullptr) {
		Student tmp;
		tmp.stu_id = stu_id;
		Node<Student>* cur = this->students.findNode(tmp);
		stu = new Node<Point>;
		stu->data.stu_id = stu_id;
		stu->data.full_name = (cur->data).first_name + " " + (cur->data).last_name;
		std::cout << "Others Point: ";
		cin >> stu->data.others;
		std::cout << "Midterm Point: ";
		cin >> stu->data.midterm;
		std::cout << "Final Point: ";
		cin >> stu->data.final;
		std::cout << "Overall: ";
		cin >> stu->data.overall;
		this->points.insertOrdered(stu->data);
		delete stu;
	}
	else {
		std::cout << "Others Point: ";
		cin >> stu->data.others;
		std::cout << "Midterm Point: ";
		cin >> stu->data.midterm;
		std::cout << "Final Point: ";
		cin >> stu->data.final;
		std::cout << "Overall: ";
		cin >> stu->data.overall;
	}
}

void Course::addStudent() {
	Student students;
	std::cout << "Enter student ID:";
	std::cin >> students.stu_id;
	if (this->stu_exists(students.stu_id)) {
		std::cout << "This student is existed";
		return;
	}
	std::cout << "Enter First name: ";
	std::cin >> students.first_name;
	std::cout << "Enter Last name: ";
	std::cin >> students.last_name;
	std::cout << "Enter Gender: ";
	std::cin >> students.gender;
	std::cout << "Enter Date of birth: ";
	std::cin >> students.date_of_birth;
	std::cout << "Enter Social ID: ";
	std::cin >> students.soci_id;
	this->students.insertOrdered(students);
}

void Course::deleteStudent() {
	Student stu;
	std::cout << "Enter student ID:";
	std::cin >> stu.stu_id;
	if (this->students.deleteNode(stu)) {
		std::cout << "delete success" << "\n";
		Point pt;
		pt.stu_id = stu.stu_id;
		this->points.deleteNode(pt);
	}
	else std::cout << "Course doesn't have this student" << "\n";
}
void Course::loadData(string curYear, int curSemester) {
	char* intStr = new char[1];
	sprintf(intStr, "%d", curSemester);
	this->inputCSV("Data\\" + curYear + "\\Semester " + std::string(intStr) + "\\" + this->ID + "\\StudentList.csv");
	this->importScoreboard("Data\\" + curYear + "\\Semester " + std::string(intStr) + "\\" + this->ID + "\\Point.csv");
}
void Course::saveData(string curYear, int curSemester) {
	char* intStr = new char[1];
	sprintf(intStr, "%d", curSemester);
	this->outputCSV("Data\\" + curYear + "\\Semester " + std::string(intStr) + "\\" + this->ID + "\\StudentList.csv");
	this->exportScoreboard("Data\\" + curYear + "\\Semester " + std::string(intStr) + "\\" + this->ID + "\\Point.csv");
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
