#include <iostream>
#include <string>

using namespace std;

template<typename T, typename F = less<T>>//Give template-parameter a default value: the 'less' function in library.
int compare (const T &v1, const T &v2, F f) {//The 3rd parameter is a callable object(function object).
	if (f(v1, v2)) {
		return 1;
	} 
	return 0;
}

bool isGreaterD(double d1, double d2) {return d1 >= d2;};
bool isGreaterS(string s1, string s2) {return s1.compare(s2);};

int main (int argc, char **argv) {
	double d1 = 1.2345, d2 = 6.7890;
	cout << compare(d1, d2, isGreaterD) << endl;
	string s1 = "Rinc", s2 = "Liu";
	cout << compare(s1, s2, isGreaterS) << endl;
	return 0;
}