#include <iostream>
#include <string>

int main (int argc, char **argv) {
	std::string firstName, familyName;
	std::cin >> firstName >> familyName;
	std::cout << "Hello, " << firstName << " " << familyName << "." << std::endl;
	return 0;
}
