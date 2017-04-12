#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char** argv) {
    fs::space_info s = fs::space("~/dev/");
    std::cout << "capacity:" << s.capacity << ", free:" << s.free << ", available:" << s.available << std::endl;
}
