#ifndef STUDENT_HXX
#define STUDENT_HXX

#include <iostream>
#include <string>

using namespace std;

class Student : public People {
public:
	Student() = default;
	Student(const string &s1, int i, const string &s2) : People(s1, i), stu_no(s2) {};
	void introduce() const override;
private:
	string stu_no;
};

void Student::introduce() const {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "No.: " << stu_no << endl;
}

#endif