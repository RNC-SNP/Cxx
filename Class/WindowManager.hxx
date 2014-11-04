#ifndef WINDOW_MANAGER_HXX
#define WINDOW_MANAGER_HXX

#include <vector>
#include "Screen.hxx"

using namespace std;

class WindowManager{
public:
	WindowManager() = default;//use the synthesized default constructor(C++11)

	WindowManager(const WindowManager &wm) {//Copy-Constructor
		++*refCount;
	}

	WindowManager& operator=(const WindowManager&); //Define '=' assignment operaton

	~WindowManager();//Destructor

	using ScreenIndex = vector<Screen>::size_type;

	void clear(ScreenIndex);

private:
	vector<Screen> screens{Screen(100, 100, ' ')};
	vector<Screen> *p = &screens;
	size_t *refCount;//Reference-Counting
};

#endif