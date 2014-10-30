#ifndef SCREEN_HXX
#define SCREEN_HXX

#include <string>

using std::string;

class Screen {
	friend class WindowManager;//WindowManager can visit all menmbers of this class
	//friend void WindowManager::clear(ScreenIndex);

public:
	//typedef string::size_type pos;
	using pos = string::size_type;	

	Screen() = default;//default constructor(C++11)

	Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c){
		//constructor with initializer-list
	}

	const char get(pos h, pos w);

	Screen *move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string content;
};

#endif