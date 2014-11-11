#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main (int argc, char **argv) {
	//Use 'function' to declare a function pointer(C++11):
	std::function<double(double, double)> multiply;
	//Use lambda expression:
	multiply = [] (double x, double y) -> double { return x * y; };
	std::cout << multiply(1.234, 5.6789) << std::endl;

	double pi = 3.1415926535;
	//Use '[&]' to capture a variable outside of the lambda:
	auto circleSpace = [&] (double radius) -> double { return pi * radius * radius; };
	std::cout << circleSpace(1.23456789) << std::endl;

	std::vector<char> v;
	for (int i = 0; i < 26; i++) {
		v.push_back((char)('A' + i));
	}
	//Use lambda with 'for_each' template:
	for_each(v.begin(), v.end(), [] (char c) -> void { std::cout << c << std::endl; });

	return 0;
}