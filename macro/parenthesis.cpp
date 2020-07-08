#include <iostream>

#define ASSIGN_TWO(x) ((x) = 2)

int main() {
  int x = 0;
  ASSIGN_TWO(x);
  std::cout << x << '\n';
}
