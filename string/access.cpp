#include <iostream>
#include <string>

int main() {
    std::string s("abc");
    std::cout << (s[s.size()] == '\0') << '\n';
    // throw exceptioin
    // std::cout << (s.at(s.size()) == '\0') << '\n';

    std::cout << 1["abc"] << '\n';
}
