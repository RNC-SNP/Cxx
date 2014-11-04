#include <iostream>
#include <string>

using namespace std;

typedef struct People {
	string name;
	int age;
};

istream& operator>>(istream &is, People &p);
ostream& operator<<(ostream &os, const People &p);

int main (int argc, char **argv) {
	People people;
	cin >> people;
	cout << people;
	return 0;
}

istream& operator>>(istream &is, People &p) {
	is >> p.name >> p.age;
	if (!is) {//If input failed, give it the default value
		p = {"", 0};
	}
	return is;
} 

ostream& operator<<(ostream &os, const People &p) {
	os << "Name: " << p.name << endl << "Age: " << p.age << endl;
	return os;
}