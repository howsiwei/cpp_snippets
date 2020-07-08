#include "helpers.h"

void func0(std::string&& s) {
    puts(s.c_str());
    s = "";
}
