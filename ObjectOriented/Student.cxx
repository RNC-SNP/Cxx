#include "Student.hxx"
#include <iostream>

void Student::print() const {
	std::cout << name << "," << age << "," << stu_no << std::endl;
}

void Student::introduce() const {
	this->People::introduce();//use scope(::) to call base class's function
	std::cout << "No.: " << stu_no << std::endl;
}