#ifndef WINDOW_MANAGER_HXX
#define WINDOW_MANAGER_HXX

#include <vector>
#include "Screen.hxx"

using namespace std;

class WindowManager{
public:
	WindowManager() = default;//use the synthesized default constructor(C++11)

	//WindowManager(const WindowManager&) = delete;//use 'delete' to prevent from copying construction(C++11)

	WindowManager &operator = (const WindowManager&) = delete; //use 'delete' to prevent assignment(C++11)

	~WindowManager() = default;//use the synthesized default deconstructor(C++11)

	using ScreenIndex = vector<Screen>::size_type;

	void clear(ScreenIndex);

private:

	vector<Screen> screens{Screen(100, 100, ' ')};
};

#endif