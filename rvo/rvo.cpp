#include <cstdio>
#include <utility>

struct nocopy {
    nocopy() = default;
    nocopy(const nocopy&) = delete;
    nocopy(nocopy&&) {
        puts("moving nocopy");
    }
};

template <typename T0, typename T1>
struct many {
    many(const many&) = delete;
    many(many&&) = delete;

    // many(T0 m0, T1 m1) : m0(), m1() {}

    T0 m0;
    T1 m1;
};

decltype(auto) construct_many() {
    return many{nocopy{}, nocopy{}};
}

int main() {
    auto [x, y] = construct_many();
    // auto z = construct_many().m0;
}
