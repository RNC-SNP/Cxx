#include <iostream>
#include <memory>
#include <string>

int main (int argc, char **argv) {
	//Unlike 'shared_ptr', only one 'unique_ptr' at a time can point to a given object. 
	//The object to which a 'unique_ptr' points is destroyed when the 'unique_ptr' is destroyed.

	std::unique_ptr<std::string> up1(new std::string("Rinc"));//Unlike 'shared_ptr', you cannot use 'make_shared'.

	//We can’t copy or assign a 'unique_ptr', we can only transfer its ownership with release() and reset():
	std::unique_ptr<std::string> up2(up1.release());
	std::cout << "up2: " << *up2 << std::endl;
	std::unique_ptr<std::string> up3(new std::string(""));
	up3.reset(up2.release());
	std::cout << "up3: " << *up3 << std::endl;

	return 0;
}