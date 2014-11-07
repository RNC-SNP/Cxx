#ifndef PEOPLE_HXX
#define PEOPLE_HXX

#include <string>

using namespace std;

class People {
public:
	People() = default;
	People(const string &s, int i) : name(s), age(i) {}
	virtual void introduce() const;
	virtual ~People() = default;
protected:
	string name;
	int age;
};

#endif