#ifndef STUDENT_HXX
#define STUDENT_HXX

#include "People.hxx"
#include <string>

class Student : public People {
public:
	Student() = default;
	Student(const std::string &s1, int i, const std::string &s2) : People(s1, i), stu_no(s2) {};//call base class's constructor
	//virtual void introduce() const;
	//In C++ 11, there's no need to put a 'virtual' keyword at the front while overriding a virtual function.
	//Instead, you can put a 'override' keyword at the end.
	void introduce() const override; 
private:
	std::string stu_no;
};

#endif