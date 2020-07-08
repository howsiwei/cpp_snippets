#include <iostream>

struct foo {
  int default_constructor_count = 0;
  int copy_constructor_count = 0;
  int copy_assignment_count = 0;
  int move_constructor_count = 0;
  int move_assignment_count = 0;

  foo() : default_constructor_count(1) { std::cout << "foo()\n"; }

  ~foo() {
    std::cout << "~foo()\n";
    std::cout << "default_constructor_count: " << default_constructor_count
              << "\n";
    std::cout << "copy_constructor_count: " << copy_constructor_count << "\n";
    std::cout << "copy_assignment_count: " << copy_assignment_count << "\n";
    std::cout << "move_constructor_count: " << move_constructor_count << "\n";
    std::cout << "move_assignment_count: " << move_assignment_count << "\n";
  }

  foo(const foo&) : copy_constructor_count(1) {
    std::cout << "foo(const foo&)\n";
  }

  foo& operator=(const foo&) {
    std::cout << "foo& operator=(const foo&)\n";
    copy_assignment_count += 1;
    return *this;
  }

  foo(foo&& other)
      : default_constructor_count(other.default_constructor_count),
        copy_constructor_count(other.copy_constructor_count),
        copy_assignment_count(other.copy_assignment_count),
        move_constructor_count(other.move_constructor_count + 1),
        move_assignment_count(other.move_assignment_count) {
    std::cout << "foo(foo&&)\n";
    other.default_constructor_count = 0;
    other.copy_constructor_count = 0;
    other.copy_assignment_count = 0;
    other.move_constructor_count = 0;
    other.move_assignment_count = 0;
  }

  foo& operator=(foo&& other) {
    std::cout << "foo& operator=(foo&&)\n";
    std::swap(default_constructor_count, other.default_constructor_count);
    std::swap(copy_constructor_count, other.copy_constructor_count);
    std::swap(copy_assignment_count, other.copy_assignment_count);
    std::swap(move_constructor_count, other.move_constructor_count);
    std::swap(move_assignment_count, other.move_assignment_count);
    move_assignment_count += 1;
    return *this;
  }
};

// auto bar(foo) {
//   std::cout << "bar(foo)\n";
// }

auto bar(foo&) {
  std::cout << "bar(foo&)\n";
}

auto bar(const foo&) {
  std::cout << "bar(const foo&)\n";
}

auto bar(foo&&) {
  std::cout << "bar(foo&&)\n";
}

auto make_foo() -> foo {
  std::cout << "make_foo()\n";
  return {};
}

template <typename T, typename F>
auto with(T&& t, F&& fn) -> void {
  fn(std::forward<T>(t));
}

auto empty_function(foo &&) -> void { return; }

auto main() -> int {
  std::cout << "before\n";
  foo foo_val;
  bar(foo_val);
  // empty_function(std::move(foo_val));
  // with(make_foo(), [](auto f) {
  //     std::cout << "during" << "\n";
  // });
  std::cout << "after\n";
}
