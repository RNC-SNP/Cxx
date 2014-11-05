#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

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
    vector<char> vc = {'A','B','C','D','E','F','R'};
    auto itvc = find(vc.cbegin(), vc.cend(), 'R');//Call function-template
    cout << *itvc << endl;

    list<string> ls = {"Andy", "Bob", "Chris", "Denny", "Emma", "Frank", "Rinc"};
    list<string>::const_iterator itls = find(ls.cbegin(), ls.cend(), "Rinc");
    cout << *itls << endl;

    return 0;
}