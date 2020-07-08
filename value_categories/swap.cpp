#include<vector>

int main() {
    std::vector<int> x;
    std::vector<int>(x).swap(x);
    // swap(x, std::vector<int>(x));
}
