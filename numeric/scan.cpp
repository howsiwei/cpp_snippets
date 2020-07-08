#include <numeric>
#include <iostream>
#include <vector>

int main() {
  std::vector data {3, 1, 4, 1, 5, 9, 2, 6};
  std::exclusive_scan(begin(data), end(data), begin(data), 0);
  for (auto x : data) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}
