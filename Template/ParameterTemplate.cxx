#include <iostream>
#include <string>

template<typename T, typename F = std::less<T>>//Give template-parameter a default value: the 'less' function in library.
int compare (const T &v1, const T &v2, F f) {//The 3rd parameter is a callable object(function object).
	if (f(v1, v2)) {
		return 1;
	} 
	return 0;
}

bool isGreaterD(const double d1, const double d2) {return d1 >= d2;};
bool isGreaterS(const std::string &s1, const std::string &s2) {return s1.compare(s2);};

int main (int argc, char **argv) {
	double d1 = 1.2345, d2 = 6.7890;
	std::cout << compare(d1, d2, isGreaterD) << std::endl;
	std::string s1 = "Rinc", s2 = "Liu";
	std::cout << compare(s1, s2, isGreaterS) << std::endl;
	return 0;
}