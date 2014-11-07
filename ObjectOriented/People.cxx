#include "People.hxx"
#include <iostream>

using namespace std;

void People::introduce() const {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}