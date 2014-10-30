#include "WindowManager.hxx"

void WindowManager::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.content = string(s.height * s.width, ' ');//Visit private members of Screen
}