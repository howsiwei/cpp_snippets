#include <iostream>

int a[] = {0, 1, 2};

int main() {
    for (const auto& x: a) {
        std::cout << x << std::endl;
    }
    int n = 3;
    while (--n) {
        std::cout << n;
    }
}
