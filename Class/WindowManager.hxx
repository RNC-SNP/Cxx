#ifndef WINDOW_MANAGER_HXX
#define WINDOW_MANAGER_HXX

#include <vector>
#include "Screen.hxx"

class WindowManager{
public:
	WindowManager() = default;//use the synthesized default constructor(C++11)

	WindowManager(const WindowManager &wm) {//Copy-Constructor
		++*refCount;
	}

	//Define '=' assignment operaton
	WindowManager& operator=(const WindowManager&);

	//Defining swap is particularly important for classes that we plan to use with algorithms that reorder elements.
	//Such algorithms call swap whenever they need to exchange two elements.
	friend void swap(WindowManager &lwm, WindowManager &rwm);

	~WindowManager();//Destructor

	using ScreenIndex = std::vector<Screen>::size_type;

	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{Screen(100, 100, ' ')};
	std::vector<Screen> *p = &screens;
	size_t *refCount;//Reference-Counting
};

inline void swap(WindowManager &lwm, WindowManager &rwm) {
	swap(lwm.p, rwm.p);//swap the pointers
}

#endif