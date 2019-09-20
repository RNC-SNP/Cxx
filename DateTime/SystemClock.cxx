#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string currentDatetimeStr(const char* format) {
    auto now = std::chrono::system_clock::now();
    auto dt = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&dt), format);
    return ss.str();
}

int main(int argc, char **argv) {
    std::cout << currentDatetimeStr("%Y-%m-%d %X") << std::endl;
	return 0;
}
