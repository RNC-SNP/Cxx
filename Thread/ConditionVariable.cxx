#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

//Sleep the current thread for a specified time duration:
#define sleep(duration) std::this_thread::sleep_for(std::chrono::seconds(duration))

std::mutex mtx;
std::condition_variable con;

int data;
bool ready = false;
bool done = false;

void handler() {
  //Wait for the main thread:
  std::unique_lock<std::mutex> lock(mtx);
  con.wait(lock, []{return ready;});

  //Own the lock, handle data.
  std::cout << "Handling data..." << std::endl;
  sleep(5);
  ++data;
  done = true;

  //Release the lock and notify the main thread.
  lock.unlock();
  con.notify_one();
}

int main(int argc, char **argv) {
  std::thread t(handler);

  std::cout << "Main thread is preparing data..." << std::endl;
  std::unique_lock<std::mutex> lock1(mtx);
  sleep(3);
  data = 0;
  ready = true;
  std::cout << "Main thread is ready..." << std::endl;
  lock1.unlock();
  con.notify_one();

  //Wait for the handler thread:
  std::unique_lock<std::mutex> lock2(mtx);
  con.wait(lock2, []{return done;});

  std::cout << "Result of handling:" << data << std::endl;

  t.join();

  return 0;
}
