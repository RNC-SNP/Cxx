#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main (int argc, char **argv) {
	//'weak_ptr' doesn't change the reference count.
	//It's possible that the object to which 'weak_ptr' points might be deleted.

	//Init 'weak_ptr' with 'shared_ptr':
	auto sp = make_shared<string>("");
	weak_ptr<string> wp(sp);

	if (shared_ptr<string> lwp = wp.lock()) {
		*lwp = "Rinc";
		cout << *sp << endl;
	}

	return 0;
}