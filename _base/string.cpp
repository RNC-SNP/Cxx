#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
	//Init with count and char:
	string s1(9, 'Z');
	string s2 = string(8, 'z');

	//Iterator:
	if (s2.begin() != s2.end()) {//compare two iterators(pointers) to check if the string is empty
		for (auto it = s2.begin(); it != s2.end() && !isspace(*it); it++) {
			*it = toupper(*it);
			cout << *it << endl;
		}
	}	

	//getline():
	string line;
	while(getline(cin, line)) {
		if (!line.empty() && line.size() <= 10) {
			line[0] = toupper(line[0]);//Access string as char array
			for (auto &c : line) {
				c = toupper(c);//'c' is a reference, so it can be modified
			}
			cout << line << endl;
		} else {
			cout << "Too long!!" << endl;
		}
	}

	return 0;
}