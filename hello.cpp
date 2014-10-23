#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main (int argc, char *argv[]) {
	string firstName, familyName;
	cin >> firstName >> familyName;
	cout << "Hello, " << firstName << " " << familyName << "." << endl;
	return 0;
}
