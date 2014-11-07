#include <iostream>
#include <map>
#include <string>

int main (int argc, char **argv) {
	std::multimap<std::string, int> mmp = {{"Andy", 23}, {"Bob", 31}, {"Chris", 35}, {"Dave", 45}};

	mmp.insert({"Rinc", 25});//Insert element

	//Travel multimap:
	for (const auto &x : mmp) {
		std::cout << x.first << ": " << x.second << std::endl;
	}

	//Find element:
	std::multimap<std::string, int>::iterator it = mmp.find("Rinc");
	if (it != mmp.end()) {
		mmp.erase(it);
		std::cout << "Found and erased..." << std::endl;
	}

	return 0;	
}