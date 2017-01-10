#include <cmath>
#include <functional>
#include <future>
#include <vector>
#include <iostream>

int main(int argc, char **argv) {
  std::vector<std::future<double>> results;
  std::function<double(double)> func = [](double radius) -> double {
    float PI = atan(1.0f) * 4.0f;
		return PI * radius * radius;
	};
  for (int i = 0; i < 28; i++) {
    results.push_back(std::async(func, i));
  }
  for (auto &result : results) {
    std::cout << result.get() << std::endl;
  }
  return 0;
}
