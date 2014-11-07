#ifndef STUDENT_HXX
#define STUDENT_HXX

#include "People.hxx"
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

#endif