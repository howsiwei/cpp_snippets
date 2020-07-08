#include <cmath>
#include <string>

void foo(const std::string&) {}

void main1() { foo(0); }

class A {
 public:
  int a;
};

class B : public A {
 public:
  int b;
};

void main2() {
  A* p = new B[10];
  p[5].a = 1;
}

struct my_class {
  my_class(int) {}
};

inline my_class operator&&(my_class, int) { return my_class(0); }

void main3() { [[maybe_unused]] double x = std::pow(1.0, 1.0); }
