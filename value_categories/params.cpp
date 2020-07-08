#include <cstdio>
#include <string>
#include "helpers.h"

template <typename T>
T clone(T x) {
    return x;
}

void func0(std::string&& s) {
    puts(s.c_str());
    s = "";
}

int main() {
    std::string s = "hello";
    func0(clone(s));
    func0(move(s));
    func0(clone(s));
    func0(move(s));
}
