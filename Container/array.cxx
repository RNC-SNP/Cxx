#include <array>
#include <iostream>

int main(int argc, char **argv) {
	const int size = 26;
	std::array<char, size> a;//declare a 'std::array'(C+=11)
	for (int i = 0; i < size; i++) {
		a[i] = (char)('A' + i);//use 'std::array' as traditional array
	}
	for(char c : a) {
		std::cout << c << std::endl;
	}
	return 0;
}