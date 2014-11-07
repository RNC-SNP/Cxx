#include "WindowManager.hxx"

void WindowManager::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.content = std::string(s.height * s.width, ' ');//Visit private members of Screen
}

WindowManager& WindowManager::operator=(const WindowManager &wm) {
	++*wm.refCount;
	if (--*refCount == 0) {//If no other users, free the allocated members
		delete p;
		delete refCount;
	}
	p = wm.p;//copy data
	refCount = wm.refCount;
	return *this;
}

WindowManager::~WindowManager() {
	if (--*refCount == 0) {//Check Reference-Count to destruct
		delete p;
		delete refCount;
	}
}