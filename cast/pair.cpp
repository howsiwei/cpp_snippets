#include <array>
#include <string>
#include <utility>

const int N = 5;
std::array<int, N> arr;
static_assert(N == N);
constexpr auto M = N;

int main()
{
    std::pair<int, std::string> a;
    a = {0, ""};
    a = std::pair{0, ""};
    a = std::pair(0, "");
    std::pair<int, std::string> b;

}
