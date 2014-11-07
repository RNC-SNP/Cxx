#include "Student.hxx"
#include <iostream>

using namespace std;

void Student::introduce() const {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "No.: " << stu_no << endl;
}