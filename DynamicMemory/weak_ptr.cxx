#include <iostream>
#include <memory>
#include <string>

int main (int argc, char **argv) {
	//'weak_ptr' doesn't change the reference count.
	//It's possible that the object to which 'weak_ptr' points might be deleted.

	//Init 'weak_ptr' with 'shared_ptr':
	auto sp = std::make_shared<std::string>("");
	std::weak_ptr<std::string> wp(sp);

	if (std::shared_ptr<std::string> lwp = wp.lock()) {
		*lwp = "Rinc";
		std::cout << *sp << std::endl;
	}

	return 0;
}