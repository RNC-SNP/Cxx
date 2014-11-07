#include <iostream>
#include <functional>

int main (int argc, char **argv) {
	std::function<double(double, double)> multiply;//Use 'function' to declare a function pointer(C++11)
	multiply = [](double x, double y){return x * y;};//Use lambda expression
	std::cout << multiply(1.234, 5.6789) << std::endl;
	return 0;
}