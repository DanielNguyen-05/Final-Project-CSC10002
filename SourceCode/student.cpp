#include "student.hpp"

Student::Student(string stu_id, string first_name, string last_name, string gender, string date_of_birth, string soci_id) {
    this->stu_id        = stu_id;
    this->first_name    = first_name;
    this->last_name     = last_name;
    this->gender        = gender;
    this->date_of_birth = date_of_birth;
    this->soci_id       = soci_id;
}

ostream& operator<<(ostream& os, const Student a) {
    os  << a.stu_id << "," 
        << a.first_name 
        << "," << a.last_name 
        << "," << a.gender << "," 
        << a.date_of_birth << "," 
        << a.soci_id << "\n";
    return os;
}
bool operator<(const Student a, const Student b) {
    return a.stu_id < b.stu_id;
}

bool operator>(const Student a, const Student b) {
    return a.stu_id > b.stu_id;
}

bool operator==(const Student a, const Student b) {
    return a.stu_id == b.stu_id;
}

bool operator!=(const Student a, const Student b) {
    return !(a == b);
}