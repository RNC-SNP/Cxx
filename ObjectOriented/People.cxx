#include "People.hxx"
#include <iostream>

//implementing abstract class's function:
void People::print() const {
	std::cout << name << "," << age << std::endl;
}

void People::introduce() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
}

People::~People() {
	std::cout << "destructing in 'People'..." << std::endl;
}