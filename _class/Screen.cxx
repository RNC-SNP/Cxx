#include "Screen.hxx"

const char Screen::get(pos r, pos c){
	pos row = r * width;
	return content[r + c];
}

Screen *Screen::move(pos r, pos c){
	pos row = r * width;
	cursor = row + c;
	return this;
}