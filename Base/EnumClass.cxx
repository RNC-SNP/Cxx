#include <iostream>
#include <cstdint>
#include <string>

//Define Enum Class:
//enum class OS {ANDROID, IOS, WINDOWS_PHONE};

//Specify Enum Class size with 'cstdint'(C++11):
enum class OS : std::int8_t {ANDROID = 1, IOS = 2, WINDOWS_PHONE = 3};

//Use Enum Class as a strong type:
const void printOS(OS &os);

const void printStrLn(const std::string &str);

int main (int argc, char **argv) {
	OS os = OS::ANDROID;
	printOS(os);

	return 0;
}

const void printOS(OS &os) {
	switch(os) {
		case OS::ANDROID:
		printStrLn("Android");
		break;
		case OS::IOS:
		printStrLn("iOS");
		break;
		case OS::WINDOWS_PHONE:
		printStrLn("Windows Phone");
		break;
	}
}

const void printStrLn(const std::string &str) {
	std::cout << str << std::endl;
}