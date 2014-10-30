#include <string>

using std::string;

class Screen {
public:
	//typedef string::size_type pos;
	using pos = string::size_type;	

	Screen() = default;//default constructor(C++11)

	Screen(pos h, pos w, char c) : height(h), width(w), content(h * w, c){
		//constructor with initializer-list
	}

	const char get(){//inplicitly inline, needn't to implement
		return content[cursor];
	}

	inline const char get(pos h, pos w);//explicitly inline, need to implement

	Screen &move(pos r, pos c);

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string content;
};