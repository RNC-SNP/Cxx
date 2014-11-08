#ifndef STUDENT_HXX
#define STUDENT_HXX

#include "People.hxx"
#include <string>

class Student : public People {
public:
	Student() = default;
	Student(const std::string &s1, int i, const std::string &s2) : People(s1, i), stu_no(s2) {};//call base class's constructor
	void print() const override;
	void introduce() const override; 
	//override the destructor
	~Student() override;
private:
	std::string stu_no;
};

#endif