#include "Student.hxx"
#include <iostream>

void Student::introduce() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
	std::cout << "No.: " << stu_no << std::endl;
}