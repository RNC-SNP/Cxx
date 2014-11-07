#include <iostream>
#include <string>

int main(int argc, char **argv) {
	//Init with count and char:
	std::string s1(9, 'Z');
	std::string s2 = std::string(8, 'z');

	//Iterator:
	if (s2.begin() != s2.end()) {//compare two iterators(pointers) to check if the string is empty
		for (auto it = s2.begin(); it != s2.end() && !isspace(*it); it++) {
			*it = toupper(*it);
			std::cout << *it << std::endl;
		}
	}	

	//getline():
	std::string line;
	while(getline(std::cin, line)) {
		if (!line.empty() && line.size() <= 10) {
			line[0] = std::toupper(line[0]);//Access string as char array
			for (auto &c : line) {
				c = std::toupper(c);//'c' is a reference, so it can be modified
			}
			std::cout << line << std::endl;
		} else {
			std::cout << "Too long!!" << std::endl;
		}
	}

	return 0;
}