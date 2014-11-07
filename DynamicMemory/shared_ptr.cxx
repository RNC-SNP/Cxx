#include <iostream>
#include <string>
#include <memory>

int main (int argc, char **argv) {
	//NOTE: 'shared_ptr's Automatically Destroy Their Objects

	//std::shared_ptr<std::string> sp(new std::string());
	//std::shared_ptr<std::string> sp = std::make_shared<std::string>();
	auto sp = std::make_shared<std::string>();

	if (sp && sp->empty()) {
		*sp = "Rinc";
	}

	std::string *sq = sp.get();//returns a built-in pointer to the object that the smart pointer is managing
	std::cout << *sq << std::endl;

	return 0;
}