#ifndef STUDENT_HXX
#define STUDENT_HXX

#include "People.hxx"
#include <string>

using namespace std;

class Student : public People {
public:
	Student() = default;
	Student(const string &s1, int i, const string &s2) : People(s1, i), stu_no(s2) {};//call base class's constructor
	//virtual void introduce() const;
	//In C++ 11, there's no need to put a 'virtual' keyword at the front while overriding a virtual function.
	//Instead, you can put a 'override' keyword at the end.
	void introduce() const override; 
private:
	string stu_no;
};

#endif