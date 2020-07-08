#include <iostream>
#include <numeric>
#include <type_traits>
#include <utility>
#include <vector>

template <typename F>
struct y_comb {
  F func;

  // y_comb(const y_comb<F>&) = delete;

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) {
    return func(*this, std::forward<Args>(args)...);
  }

  template <typename... Args>
  decltype(auto) operator()(Args&&... args) const {
    return func(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
y_comb(F) -> y_comb<F>;

template <typename F>
y_comb<std::decay_t<F>> make_y_comb(F func) {
  return {std::forward<F>(func)};
}

int main() {
  std::vector<int> a(30);
  std::iota(begin(a), end(a), 0);
  auto f = y_comb{[&a](auto& self, int n) -> int {
    if (n == 0) return 0;
    return a[n - 1] + self(n - 1);
  }};
  y_comb{[&a](auto&& self, int n) -> void {
    if (n == 0) {
      std::cout << '\n';
      return;
    }
    std::cout << a[n - 1] << ' ';
    self(n - 1);
  }}(10);
  const auto g = make_y_comb([&a](auto& self, int n) -> void {
    if (n == 0) {
      std::cout << '\n';
      return;
    }
    std::cout << a[n - 1] << ' ';
    self(n - 1);
  });
  std::cout << sizeof(a) << '\n';
  std::cout << sizeof(f) << '\n';
  std::cout << f(30) << '\n';
  g(5);
}
