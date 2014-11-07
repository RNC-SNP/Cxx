#include <iostream>
#include "Screen.hxx"
#include "WindowManager.hxx"

int main(int argc, char **argv) {
	Screen *screen = new Screen(10, 10, 'x');
	std::cout << screen->move(4, 5)->get(8, 9) << std::endl;

	WindowManager *wm = new WindowManager();
	wm->clear(9);

	delete screen;

	return 0;
}