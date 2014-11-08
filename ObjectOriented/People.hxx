#ifndef PEOPLE_HXX
#define PEOPLE_HXX

#include "Object.hxx"
#include <string>

class People : public Object {
public:
	People() = default;
	People(const std::string &s, int i) : name(s), age(i) {}
	//virtual void print() const;
	//In C++ 11, there's no need to put a 'virtual' keyword at the front
	//	while overriding/implementing a virtual function.
	//Instead, you can put a 'override' keyword at the end.
	void print() const override;
	//declare a non-pure virtual function
	virtual void introduce() const;
protected:
	std::string name;
	int age;
};

#endif