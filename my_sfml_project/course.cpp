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
	Student stu;
	stu.stu_id = stu_id;
	if (!this->students.findNode(stu))
		return false;
	return true;

}
void Course::inputCSV(string path) {
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
		if (!this->stu_exists(stu.stu_id)) {
			getline(fIn, stu.first_name, ',');
			getline(fIn, stu.last_name, ',');
			getline(fIn, stu.gender, ',');
			getline(fIn, stu.date_of_birth, ',');
			getline(fIn, stu.soci_id);

			this->students.insertOrdered(stu);
		}
	}
	fIn.close();
}

void Course::importScoreboard(string path) {
	ifstream fIn(path);
	string ignore = "";
	getline(fIn, ignore);
	while (!fIn.eof()) {
		Point pt;
		string tmp_no = "";
		getline(fIn, tmp_no, ',');
		if (tmp_no == "")
			return;
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
	ofstream fOut(path);
	if (!fOut.is_open()) {
		cerr << "Error: Unable to open file for writing!" << endl;
		return;
	}

	fOut << "No,StudentID,FullName,Overall,Final,Midterm,Others" << endl;
	int counter = 1;
	Node<Point>* cur = this->points.pHead;
	while(cur) {
		Point pt = cur->data;
		fOut << counter << "," << pt.stu_id << "," << pt.full_name << "," << pt.overall << ","
			<< pt.final << "," << pt.midterm << "," << pt.others << endl;
		++counter;
		cur = cur->pNext;
	}

	fOut.close();
}

void Course::outputCSV(string path) {
	ofstream fOut(path);
	Node<Student>* cur = this->students.pHead;
	int no = 0;
	fOut << "no,stu_id,first_name,last_name,gender,date_of_birth,soci_id" << "\n";
	while (cur) {
		no++;
		fOut << no << ", ";
		fOut << cur->data;
		cur = cur->pNext;
	}
	fOut.close();
}

void Course::viewScoreboard() {
	if (!this->points.pHead)
		return;
	std::cout << "NO \t Student ID \t Full Name \t Overall Point \t Final Point \t Midterm Point \t Others" << "\n";
	Node<Point>* cur = this->points.pHead;
	int no = 0;
	while (cur) {
		no++;
		std::cout << no << "," << cur->data;
		cur = cur->pNext;
	}
}
void Course::viewStudent() {
	if (!this->students.pHead)
		return;
	std::cout << "no,stu_id,first_name,last_name,gender,date_of_birth,soci_id" << "\n";
	Node<Student>* cur = this->students.pHead;
	int no = 0;
	while (cur) {
		no++;
		std::cout << no << "," << cur->data;
		cur = cur->pNext;
	}
}
void Course::updateResult() {
	string stu_id;
	std::cout << "Enter student ID you want to delete:";
	std::cin >> stu_id;
	Point pt;
	pt.stu_id = stu_id;
	Node<Point>* stu = this->points.findNode(pt);
	if (stu == nullptr) {
		std::cout << "Student is not existed....Enter to continue";
		std::cin.get();
		std::cin.get();
		return;
	}
	std::cout << "Others Point: ";
	cin >> stu->data.others;
	std::cout << "Midterm Point: ";
	cin >> stu->data.midterm;
	std::cout << "Final Point: ";
	cin >> stu->data.final;
	std::cout << "Overall: ";
	cin >> stu->data.overall;
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
	else
		std::cout << "Course doesn't have this student" << "\n";
}

ostream& operator<<(ostream& os, const Course::Point a) {
	os << a.stu_id << "," << a.full_name << "," << a.overall << "," << a.final << "," << a.midterm << "," << a.others << "\n";
	return os;
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
