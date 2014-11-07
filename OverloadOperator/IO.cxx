#include <iostream>
#include <string>

struct People {
	std::string name;
	int age;
};

std::istream& operator>>(std::istream &is, People &p);
std::ostream& operator<<(std::ostream &os, const People &p);

int main (int argc, char **argv) {
	People people;
	std::cin >> people;
	std::cout << people;
	return 0;
}

std::istream& operator>>(std::istream &is, People &p) {
	is >> p.name >> p.age;
	if (!is) {//If input failed, give it the default value
		p = {"", 0};
	}
	return is;
} 

std::ostream& operator<<(std::ostream &os, const People &p) {
	os << "Name: " << p.name << std::endl << "Age: " << p.age << std::endl;
	return os;
}