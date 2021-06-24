#include "student.h"
Student::Student(int id, string name, double gpa){
	this->id = id; this->name = name; this->gpa = gpa;
}
Student::Student(){ // default constructor
 	id =0; name = ""; gpa = 0.0;
}
int Student::getID() { return id; }
string Student::getName() { return name; }
double Student::getGPA() { return gpa; }

void Student::setID(int id){ this->id = id; }
void Student::setName(string name) { this->name = name; }
void Student::setGPA(double gpa) { this->gpa = gpa; }
bool Student::operator<(Student s){ return (id < s.id); }
bool Student::operator>(Student s){ return (id > s.id); }
bool Student::operator==( Student s){ return (id == s.id);}
ostream& operator<<(ostream &write, Student s){
	write << s.id << " " << s.name << " " << s.gpa;
	return write;
}
istream& operator>>(istream &read, Student& s){
	read >> s.id >> s.name >> s.gpa;
	return read;
}
int Student::compare_students(Student s){
	if(this->id == s.id){
		return 0;
	}
	else{
		return 1;
	}
}