#include "Screen.h"
#include <iostream>

using std::cout;
using std::endl;

inline const char Screen::get(pos r, pos c){
	pos row = r * width;
	return content[r + c];
}

Screen &Screen::move(pos r, pos c){
	pos row = r * width;
	cursor = row + c;
	return *this;
}

int main(int argc, char **argv) {
	Screen *screen = new Screen(10, 10, 'x');
	cout << screen->get() << endl;
	cout << screen->get(8, 9) << endl;
	return 0;
}
