#include <iostream>

int main (int argc, char *argv[]) {
	// void* pointer can hold the address of any type object.
	double obj = 3.14, *p = &obj;
	void *vp = &obj;
	vp = p;

	//const object's pointer(Low-level const):
	const double pi = 3.14;
	const double *cp = &pi;//'const' keywords is necessary. cp can be modified.(But *cp cannot.)

	//const pointer of a const object(Top-level const):
	const double *const ccp = &pi;//ccp cannot be modified.

	//auto(c++11):
	auto a = 3.14, *pa = &a;
	auto a1 = a;
	auto a2 = pa;
	auto &a3 = a;
	auto &a4 = pa;
}