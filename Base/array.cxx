#include <iostream>

int main(int argc, char **argv) {
	char array1[4][3] = {
		{'c', 'o', 'm'},
		{'o', 'r', 'g'},
		{'n', 'e', 't'},
		{'b', 'i', 'z'}
	};

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << array1[i][j];
		}
		std::cout << std::endl;
	}

	char (*array2)[3] = array1;
	for (auto p = array2; p < array2 + 4; p++) {
		for (auto q = *p; q < *p + 3; q++) {//q is a pointer storing the first element's address of the sub-array; 
			std::cout << *q;
		}
		std::cout << std::endl;
	}

	char *ap = new char[5]{'a', 'b', 'c', 'd', 'e'};
	delete [] ap;

	return 0;
}
