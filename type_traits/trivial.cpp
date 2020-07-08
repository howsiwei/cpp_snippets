#include <iostream>
#include <tuple>
#include <type_traits>
#include <utility>

struct my_struct {
  int x;
  int y;

  my_struct() {}
  my_struct(int x, int y) :x(x), y(y) {}
};

int main() {
  my_struct a{0, 0};

  std::cout << "is_constructible\n";
  std::cout << "my_struct " << std::is_constructible_v<my_struct> << '\n';
  std::cout << "std::pair<int, int> " << std::is_constructible_v<std::pair<int, int>> << '\n';
  std::cout << "std::tuple<int, int> " << std::is_constructible_v<std::tuple<int, int>> << '\n';
  std::cout << "\n";

  std::cout << "is_trivially_constructible\n";
  std::cout << "my_struct " << std::is_trivially_constructible_v<my_struct> << '\n';
  std::cout << "std::pair<int, int> " << std::is_trivially_constructible_v<std::pair<int, int>> << '\n';
  std::cout << "std::tuple<int, int> " << std::is_trivially_constructible_v<std::tuple<int, int>> << '\n';
  std::cout << "\n";

  std::cout << "is_pod\n";
  std::cout << "my_struct " << std::is_pod_v<my_struct> << '\n';
  std::cout << "std::pair<int, int> " << std::is_pod_v<std::pair<int, int>> << '\n';
  std::cout << "std::tuple<int, int> " << std::is_pod_v<std::tuple<int, int>> << '\n';
  std::cout << "\n";

  std::cout << "is_standard_layout\n";
  std::cout << "my_struct " << std::is_standard_layout_v<my_struct> << '\n';
  std::cout << "std::pair<int, int> " << std::is_standard_layout_v<std::pair<int, int>> << '\n';
  std::cout << "std::tuple<int, int> " << std::is_standard_layout_v<std::tuple<int, int>> << '\n';
  std::cout << "\n";

  std::cout << "is_trivial\n";
  std::cout << "my_struct " << std::is_standard_layout_v<my_struct> << '\n';
  std::cout << "std::pair<int, int> " << std::is_trivial_v<std::pair<int, int>> << '\n';
  std::cout << "std::tuple<int, int> " << std::is_trivial_v<std::tuple<int, int>> << '\n';
  std::cout << "\n";

}
