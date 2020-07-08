#include <iostream>

class A {
 public:
  explicit A(int _n) : n(_n) { std::cout << "A(" << n << ")\n"; }
  A(const A& other) : n(other.n) { std::cout << "A(const A&)\n"; }
  A(A&& other) noexcept : n(other.n) { std::cout << "A(A&&)\n"; }
  A& operator=(const A& other) noexcept {
    std::cout << "operator=(const A&)\n";
    n = other.n;
    return *this;
  }
  A& operator=(A&& other) noexcept {
    std::cout << "operator=(A&&)\n";
    n = other.n;
    return *this;
  }
  ~A() { std::cout << "~A(" << n << ")\n"; }

 private:
  int n;
};

int main() {
  A&& a = A(0);
  std::cout << "a assigned 0\n";
  a = A(1);
  std::cout << "a assigned 1\n";
  A& a1 = a;
  std::cout << "a1 assigned a\n";
  // error: rvalue reference to type 'A' cannot bind to lvalue of type 'A'
  // A&& a2 = a;
  return 0;
}
