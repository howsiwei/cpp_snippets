// Turn on -Wmissing-prototypes to check that all function declaration matches
// the definitions

#include <iostream>

int f(int n);
auto f(const int n) -> int { return n; }

int g(const int * p);
auto g(const int * volatile p) -> int { return *p; }

int h(const int * const * pp);
auto h(const int * const * pp) -> int { return **pp; }

int i(const int& n);
auto i(const int& n) -> int { return n; }

int main() {
  int n = 0;
  f(n);
  int* p = &n;
  int** pp = &p;
  const int *const cp = p;
  const int *const * cpp = &cp;
  g(p);
  h(cpp);
  i(n);
  return 0;
}
