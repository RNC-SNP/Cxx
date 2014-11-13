#include <vector>
#include <tuple>
#include <iostream>
#include <string>

//use tuple(C++11):
typedef std::tuple<std::string, int, char> people;

int main (int argc, char **argv) {
	std::vector<people> v;
	v.push_back(people("Andy", 12, 'M'));
	v.push_back(people("Bob", 17, 'M'));
	v.push_back(people("Christina", 34, 'F'));
	v.push_back(people("Denny", 29, 'M'));
	v.push_back(people("Emma", 23, 'F'));
	v.push_back(people("Rinc", 25, 'M'));
	for (people p : v) {//read elements of the tuple:
		std::cout << std::get<0>(p) << " " << std::get<1>(p) << " " << std::get<2>(p) << std::endl;
	}
	return 0;
}