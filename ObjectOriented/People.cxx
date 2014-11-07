#include "People.hxx"
#include <iostream>

void People::introduce() const {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Age: " << age << std::endl;
}