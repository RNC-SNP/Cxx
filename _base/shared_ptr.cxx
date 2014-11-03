#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main (int argc, char **argv) {
	//NOTE: shared_ptrs Automatically Destroy Their Objects

	//shared_ptr<string> sps = make_shared<string>();
	auto sp = make_shared<string>();

	if (sp && sp->empty()) {
		*sp = "Rinc";
	}

	cout << *sp << endl;

	return 0;
}