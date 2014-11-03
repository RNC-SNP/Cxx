#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main (int argc, char **argv) {
	//Unlike 'shared_ptr', only one 'unique_ptr' at a time can point to a given object. 
	//The object to which a 'unique_ptr' points is destroyed when the 'unique_ptr' is destroyed.

	unique_ptr<string> up1(new string("Rinc"));//Unlike 'shared_ptr', you cannot use 'make_shared'.

	//We can’t copy or assign a 'unique_ptr', we can only transfer its ownership with release() and reset():
	unique_ptr<string> up2(up1.release());
	cout << "up2: " << *up2 << endl;
	unique_ptr<string> up3(new string(""));
	up3.reset(up2.release());
	cout << "up3: " << *up3 << endl;

	return 0;
}