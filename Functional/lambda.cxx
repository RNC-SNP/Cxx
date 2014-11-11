#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

int main (int argc, char **argv) {
	//Use 'std::function' to declare a function pointer(C++11):
	std::function<double(double, double)> multiply;
	//Define lambda(C++11):
	multiply = [] (double x, double y) -> double { return x * y; };//So, a lambda's type is 'std::function'
	std::cout << multiply(1.234, 5.6789) << std::endl;

	double pi = 3.14;
	/*
	Capture variables outside of the lambda:
	'[]':        Capture nothing;
	'[=]':       Capture any referenced variable by making a copy, the variable cannot be modified;
	'[&]':       Capture any referenced variable by reference, the variable can be modified if not 'const';
	'[=, &var]': Capture any referenced variable by making a copy, but capture variable 'var' by reference;
	'[this]':    Capture the 'this' pointer;
	*/
	auto circleSpace = [=, &pi] (double radius) -> double { pi = 3.1415926535; return pi * radius * radius; };
	std::cout << circleSpace(1.23456789) << std::endl;

	std::vector<char> v;
	for (int i = 0; i < 26; i++) {
		v.push_back((char)('A' + i));
	}
	//Use lambda with 'for_each' template:
	for_each(v.begin(), v.end(), [] (char c) -> void { std::cout << c << std::endl; });

	return 0;
}