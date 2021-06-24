#include <string>
#include <iostream>
using namespace std;
class Student{
 	private:
 		int id;
 		string name;
 		double gpa;
 	public:
		Student();
		Student(int id, string name, double gpa);
	//getters
		int getID();
		string getName();
		double getGPA();
		//setters
		void setID(int id);
		void setName(string name);
		void setGPA(double gpa);
		// overloading operators
		bool operator<(Student s);
		bool operator==(Student s);
		bool operator>(Student s);
		int compare_students(Student s);
		friend ostream& operator<<(ostream &write, Student s);
 		friend istream& operator>>(istream &read, Student& s);
};