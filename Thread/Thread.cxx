#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

//Get thread id:
#define tid() std::this_thread::get_id()
//Sleep the current thread for a specified time duration:
#define sleep(duration) std::this_thread::sleep_for(std::chrono::seconds(duration))

void func_thread(const int duration) {
	std::cout << "Called from thread " << tid() << "." << std::endl;
	sleep(duration);
}

int main(int argc, char **argv) {
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i) {
		//Create a new threads:
		std::thread t(func_thread, i);
		//threads.push_back(static_cast<std::thread&&>(t));
		threads.push_back(std::move(t));
	}
	for (auto &t : threads) {
		//Wait for the new thread, or it is possible that the main thread will finish first
		//and the program will kill the new thread and exit.
		t.join();
	}
	std::cout << "Called from main thread " << tid() << "." << std::endl;
	return 0;
}
