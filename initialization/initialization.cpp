#include <iostream>
#include <vector>

int main() {
  std::vector<int> a{3, 4};
  std::vector<int> b = {3, 4};
  std::cout << a.size() << '\n';
  std::cout << b.size() << '\n';
  return 0;
}
