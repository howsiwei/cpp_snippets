#include <iostream>
#include <utility>

struct A {
    A(int id) : id_ { id } {}

    A(const A& rhs) { std::cout << "cctor from " +
            std::to_string(rhs.id_) << std::endl; }
    A(A&& rhs) { std::cout << "mctor from " +
            std::to_string(rhs.id_) << std::endl; }

    int id_;
};

template<typename T>
struct B1 {
    constexpr B1(T&& x) noexcept : x_ { std::forward<T>(x) } {}

    T x_;
};

template<typename T>
struct B2 {
    constexpr B2(T&& x) noexcept;

    T x_;
};

template<typename T>
constexpr
B2<T>::B2(
    T&& x
    ) noexcept :
    x_ { std::forward<T>(x) } {
}

int
main(
    ) {
    A a { 1 };

    B1 b11 { a }; // Not compiling
    B1 b12 { A { 2 } };

    B2 b21 { a }; // Should be compile error
    B2 b22 { A { 3 } };

    return 0;
}
