#include <memory>

void f(int* a, int* b, const int* c) {
  *a += *c;
  *b += *c;
}


void g(int& __restrict__ a, int& __restrict__ b, const int& __restrict__ c) {
  a += c;
  b += c;
}


void h(std::unique_ptr<int> a, std::unique_ptr<int> b, std::unique_ptr<int> c) {
  *a += *c;
  *b += *c;
}


// Local Variables:
// rmsbolt-command: "g++ -O3 -std=c++17 -Wall -Wextra -Wpedantic"
// rmsbolt-disassemble: nil
// End:
