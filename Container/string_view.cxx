#include <iostream>
#include <string_view>

// By overloading the global operator new,
// we can see that dynamic allocations are occurring when we call compare with a string-literal
void* operator new(std::size_t n) {
    std::cout << "-> allocating " << n << " bytes" << std::endl;
    return malloc(n);
}

//bool compare(std::string s1, std::string s2) {
//    if (s1 == s2) return true;
//    std::cout << "string: '" << s1 << "' != '" << s2 << "'" << std::endl;
//    return false;
//}

// string_view, a way to wrap an existing string in a NON-OWNING way.
// The creation of string_vew from the literals DOES NOT require a dynamic allocation.
// The likely implementation will consist of just two data members, a pointer to the start of the string and a length.
bool compare(std::string_view s1, std::string_view s2) {
    if (s1 == s2) return true;
    std::cout << "string_view: '" << s1 << "' != '" << s2 << "'" << std::endl;
    return false;
}

int main(int argc, char** argv) {
    std::string s = "qwertyuiopasdfghjklzxcvbnm_";
    compare(s, "qwertyuiopasdfghjklzxcvbnm_1");
    compare(s, "qwertyuiopasdfghjklzxcvbnm_22");
    compare(s, "qwertyuiopasdfghjklzxcvbnm_333");
    return 0;
}
