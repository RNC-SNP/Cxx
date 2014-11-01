#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	char array1[4][3] = {
		{'c', 'o', 'm'},
		{'o', 'r', 'g'},
		{'n', 'e', 't'},
		{'b', 'i', 'z'}
	};
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			cout << array1[i][j];
		}
		cout << endl;
	}

	char (*array2)[3] = array1;
	for (auto p = array2; p < array2 + 4; p++) {
		for (auto q = *p; q < *p + 3; q++) {//q is a pointer storing the first element's address of the sub-array; 
			cout << *q;
		}
		cout << endl;
	}

	return 0;
}
