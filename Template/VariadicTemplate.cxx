#include <iostream>

using namespace std;

template<typename T>
ostream& print(ostream& os, const T& t) {
    return os << t << endl;
}

template<typename T, typename... Args>
ostream& print(ostream &os, const T &t, const Args&... rest) {
    print(os, t);
    return print(os, rest...);
}

int main (int argc, char **argv) {
    print(std::cout, 1, 2.34, 'A', "Rinc");
}