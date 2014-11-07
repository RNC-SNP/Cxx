#ifndef PEOPLE_HXX
#define PEOPLE_HXX

#include <string>

class People {
public:
	People() = default;
	People(const std::string &s, int i) : name(s), age(i) {}
	virtual void introduce() const;
	virtual ~People() = default;//Base class usually has a virtual destructor.
protected:
	std::string name;
	int age;
};

#endif