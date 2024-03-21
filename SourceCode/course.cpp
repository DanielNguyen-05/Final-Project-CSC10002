#include"course.hpp"

Course::Course(string ID, string course_name, string class_name, string teacher_name, int num_of_creadit, int max_student, string session) {
	this->ID = ID;
	this->course_name = course_name;
	this->class_name = class_name;
	this->teacher_name = teacher_name;
	this->num_of_credit = num_of_creadit;
	this->max_student = max_student;
	this->session = session;
}

void Course::inputCSV(const char* path) {
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
void Course::importScoreboard(const char* path) {
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
void Course::outputCSV(const char* path) {
	ofstream fOut(path);
	Node<Student>* cur = this->students.pHead;
	int no = 0;
	fOut << "no,stu_id,first_name,last_name,gender,date_of_birth,soci_id" << endl;
	while (cur) {
		no++;
		fOut << no << ",";
		fOut << cur->data;
		cur = cur->pNext;
	}
	fOut.close();
}
void Course::viewScoreboard() {
	if (!this->points.pHead)
		return;
	cout << "no,stu_id,full_name,overall,final,mid_term,others" << endl;
	Node<Point>* cur = this->points.pHead;
	int no = 0;
	while (cur) {
		no++;
		cout << no << "," << cur->data;
		cur = cur->pNext;
	}
}
void Course::updateResult(string stu_id) {
	Point pt;
	pt.stu_id = stu_id;
	Node<Point>* stu = this->points.findNode(pt);
	if (stu == nullptr) {
		return;
	}
	cout << "Others Mark: ";
	cin >> stu->data.others;
	cout << "Midterm Mark: ";
	cin >> stu->data.midterm;
	cout << "Final Mark: ";
	cin >> stu->data.final;
	cout << "Overall: ";
	cin >> stu->data.overall;
}
void Course::addStudent(Student stu) {
	this->students.insertOrdered(stu);
}
void Course::deleteStudent(string stu_id) {
	Student stu;
	stu.stu_id = stu_id;
	if (this->students.deleteNode(stu)) {
		cout << "delete success" << endl;
		Point pt;
		pt.stu_id = stu_id;
		this->points.deleteNode(pt);
	}
	else
		cout << "Course doesn't have this student" << endl;
}
static ostream& operator<<(ostream& os, const Course::Point a) {
	os << a.stu_id << "," << a.full_name << "," << a.overall << "," << a.final << "," << a.midterm << "," << a.others << endl;
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
