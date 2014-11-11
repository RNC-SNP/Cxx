#include <iostream>
#include <functional>

int main (int argc, char **argv) {
	//Use 'function' to declare a function pointer(C++11):
	std::function<double(double, double)> multiply;
	//Use lambda expression:
	multiply = [](double x, double y){return x * y;};
	std::cout << multiply(1.234, 5.6789) << std::endl;

	double pi = 3.1415926535;
	//Use '[&]' to capture a variable out of the lambda:
	auto circleSpace = [&](double radius){return pi * radius * radius;};
	std::cout << circleSpace(1.23456789) << std::endl;

	return 0;
}