#include <iostream>
#include <vector>
#include <list>
#include <string>

//Define function-template
template<typename iteratorT, typename T>
iteratorT find(const iteratorT& first, const iteratorT& last, const T& value) {
    if (first == last) {
        return last;
    } else {
        for (auto it = first; it != last; ++it) {
            if(*it == value) {
                return it;
            }
        }
        return last;
    }
}

int main(int argc, char** argv) {
    std::vector<char> vc = {'A','B','C','D','E','F','R'};
    auto itvc = find(vc.cbegin(), vc.cend(), 'R');//Call function-template
    std::cout << *itvc << std::endl;

    std::list<std::string> ls = {"Andy", "Bob", "Chris", "Denny", "Emma", "Frank", "Rinc"};
    std::list<std::string>::const_iterator itls = find(ls.cbegin(), ls.cend(), "Rinc");
    std::cout << *itls << std::endl;

    return 0;
}