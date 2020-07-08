#include <iostream>

template <int n>
struct confusing {
  static int q;
};

template <>
int confusing<4>::q = 1;

template <>
struct confusing<1> {
  template <int n>
  struct q {
    q(int) { std::cout << "Separated syntax and semantics.\n"; }
    operator int() { return 0; }
  };
};

char x;

int main() {
  int x = confusing<sizeof(x)>::q<3>(2);
  std::cout << x << '\n';
  return 0;
}
