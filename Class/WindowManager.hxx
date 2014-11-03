#ifndef WINDOW_MANAGER_HXX
#define WINDOW_MANAGER_HXX

#include <vector>
#include "Screen.hxx"

using namespace std;

class WindowManager{
public:
	WindowManager() = default;//Default-Constructor(C++11)

	~WindowManager() = default;//Default-Deconstructor(C++11)

	using ScreenIndex = vector<Screen>::size_type;

	void clear(ScreenIndex);

private:

	vector<Screen> screens{Screen(100, 100, ' ')};
};

#endif