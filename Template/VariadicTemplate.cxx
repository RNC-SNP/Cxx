#include <iostream>

template<typename T>
std::ostream& print(std::ostream& os, const T& t) {
    return os << t << std::endl;
}

template<typename T, typename... Args>
std::ostream& print(std::ostream &os, const T &t, const Args&... rest) {
    print(os, t);
    return print(os, rest...);
}

int main (int argc, char **argv) {
    print(std::cout, 1, 2.34, 'A', "Rinc");
}