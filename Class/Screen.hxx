#ifndef SCREEN_HXX
#define SCREEN_HXX

#include <string>

using namespace std;

class Screen {
	friend class WindowManager;//WindowManager can visit all menmbers of this class
	/*
	 * Note:
	 * 1. Friend function is not a member function of the class, so you can not use 'this' pointer in its body.
	 * 2. Friend function can not be inherited.
	 */
	//friend void WindowManager::clear(ScreenIndex);

public:
	//typedef string::size_type pos;
	using pos = string::size_type;	

	Screen() = default;//use the synthesized default constructor(C++11)

	Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c){
		//constructor with Initializer-List
		//NOTE: All reference and const menbers should be initialized with Initializer-List !!
	}

	Screen(pos h, pos w) : Screen(h, w, ' '){
		//Delegating-Constructor(C++11)
	}

	//Screen(const Screen&) = delete;//use 'delete' to prevent copying construction(C++11)

	Screen& operator=(const Screen&) = delete; //Define '=' operator: use 'delete' to prevent assignment(C++11)

	~Screen() = default;//use the synthesized default decstructor(C++11)

	const char get(pos h, pos w);

	Screen *move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string content;
};

#endif