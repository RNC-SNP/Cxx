#include <iostream>
#include <functional>

using namespace std;

int main (int argc, char **argv) {
	function<double(double, double)> multiply;//Use 'function' to declare a function pointer(C++11)
	multiply = [](double x, double y){return x * y;};//Use lambda expression
	cout << multiply(1.234, 5.6789) <<endl;
	return 0;
}