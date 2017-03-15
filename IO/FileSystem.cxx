#include <iostream>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

int main(int argc, char** argv) {
    fs::space_info s = fs::space("~/dev/");
    std::cout << "capacity:" << s.capacity << ", free:" << s.free << ", available:" << s.available << std::endl;
}
