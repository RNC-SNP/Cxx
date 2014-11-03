#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main (int argc, char **argv) {
	//NOTE: shared_ptrs Automatically Destroy Their Objects

	//shared_ptr<string> sp(new string());
	//shared_ptr<string> sp = make_shared<string>();
	auto sp = make_shared<string>();

	if (sp && sp->empty()) {
		*sp = "Rinc";
	}

	string *sq = sp.get();//returns a built-in pointer to the object that the smart pointer is managing
	cout << *sq << endl;

	return 0;
}