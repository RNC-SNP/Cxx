#include <iostream>
#include <map>
#include <string>

using namespace std;

int main (int argc, char **argv) {

	multimap<string, int> mmp = {{"Andy", 23}, {"Bob", 31}, {"Chris", 35}, {"Dave", 45}};

	mmp.insert({"Rinc", 25});//Insert element

	//Travel multimap:
    for (const auto &x : mmp) {
        cout << x.first << ": " << x.second << endl;
    }

    //Find element:
    multimap<string, int>::iterator it = mmp.find("Rinc");
    if (it != mmp.end()) {
    	mmp.erase(it);
    	cout << "Found and erased..." << endl;
    }

	return 0;
}