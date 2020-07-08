#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <random>

using rg = std::default_random_engine;

int main() {
  std::array<int, 10> arr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::shuffle(std::begin(arr), std::end(arr), std::default_random_engine(std::random_device()()));
  for (auto x : arr) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
