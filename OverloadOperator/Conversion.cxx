#include <iostream>

class Double {
public:
	Double(double d = 0):x(d){}
	operator double () const {return x;} 
private:
	double x;
};

int main (int argc, char **argv) {
	Double d(1.234);
	d = 5.678;//implicitly converts 5.678 to Double
	std::cout << (d + 0.0009) << std::endl;//implicitly converts d to double
	return 0;
}