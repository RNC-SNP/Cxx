#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

//std::atomic_flag is an atomic boolean type.
//It can be used to implement a mutex spin-lock.
std::atomic_flag lock = ATOMIC_FLAG_INIT;

void tfunc(int tid) {
  for (int x = 0; x < 10; ++x) {
    while (lock.test_and_set(std::memory_order_acquire)) {//Try to get the lock.
      std::cout << "Thread " << tid << " is spinning..." << std::endl;
    }
    std::cout << "Thread " << tid << " get the lock." << std::endl;
    lock.clear(std::memory_order_release);//Release the lock.
  }
}

int main(int argc, char **argv) {
  std::vector<std::thread> threads;
  for (int i = 0; i < 3; ++i) {
    threads.push_back(std::thread(tfunc, i));
  }
  for (auto& t : threads) {
    t.join();
  }
  return 0;
}
