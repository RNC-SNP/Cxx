#include <iostream>
#include <thread>
#include <chrono>

static const int threads_num = 10;

void func_thread(const int duration) {
	//Get thread id:
	std::cout << "Called from thread " << std::this_thread::get_id() << "." << std::endl;
	//Sleep the current thread for a specified time duration:
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

int main(int argc, char **argv) {
	std::thread threads[threads_num];
	for (int i = 0; i < threads_num; ++i) {
		//Create a new threads:
		threads[i] = std::thread(func_thread, i);
		//Wait for the new thread, or it is possible that the main thread will finish first
		//and the program will kill the new thread and exit.
		threads[i].join();
	}
	return 0;
}
