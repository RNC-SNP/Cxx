#include <iostream>

using namespace std;

template<typename T, typename F = less<T>>//Give template-parameter default value.
int compare(const T &v1, const T &v2, F f = F()) {//The 3rd parameter is a callable object(function object).
	if (f(v1, v2)) {
		return -1;
	} 
	if (f(v2, v1)) {
		return 1;
	}
	return 0;
}

bool funcLess(int v1, int v2) {return v1 < v2;};

int main (int argc, char **argv) {
	int v1 = 12345, v2 = 67890;
	cout << compare(v1, v2, funcLess) << endl;
	return 0;
}