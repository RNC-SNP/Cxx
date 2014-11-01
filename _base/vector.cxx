#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	//init vector:
	vector<char> v1 = {'1', '3', '5', '7', '9'};
	vector<char> v2{'0', '2', '4', '6', '8'};
	vector<char> v3(10);//init with count
	vector<char> v4(10, 'x');//init with count and element
	vector<char> v5(v1);//copy elements

	//add elements:
	vector<char> v6;
	for (int i = 0; i < 26; i++) {
		v6.push_back((char)('A' + i));
	}

	//visit elements:
	for (auto &e : v6) {
		e = (char)(e + 32);
	}
	for (auto e : v6) {
		cout << e << endl;
	}

	//Vector:
	for (auto it = v6.begin(); it != v6.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}