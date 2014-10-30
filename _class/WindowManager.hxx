#ifndef WINDOW_MANAGER_HXX
#define WINDOW_MANAGER_HXX

#include <vector>
#include "Screen.hxx"

using std::vector;

class WindowManager{
public:

	using ScreenIndex = vector<Screen>::size_type;

	void clear(ScreenIndex);

private:

	vector<Screen> screens{Screen(100, 100, ' ')};
};

#endif