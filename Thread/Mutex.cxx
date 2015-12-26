#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

//Sleep the current thread for a specified time duration:
#define sleep(duration) std::this_thread::sleep_for(std::chrono::seconds(duration))

volatile int data(0);
std::mutex mtx;

void func_thread(const int duration) {
	std::cout << "Old:" << data << std::endl;
	sleep(duration);//Simulate the time-wasting operation.
	if (mtx.try_lock()) {//Try to get the lock.
		++data;
		mtx.unlock();//Release the lock.
	}
	std::cout << "New:" << data << std::endl;
}

int main(int argc, char **argv) {
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; ++i) {
		std::thread t(func_thread, i);
		threads.push_back(std::move(t));
	}
	for (auto &t : threads) {
		t.join();
	}
	return 0;
}
