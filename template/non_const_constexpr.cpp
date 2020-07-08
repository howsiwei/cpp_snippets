#include <iostream>

namespace detail {
    struct A {
        constexpr A () { }
        friend constexpr int adl_flag (A);
    };

    template<class Tag>
    struct writer {
        friend constexpr int adl_flag (Tag) {
            return 0;
        }
    };
}

template<class Tag>
constexpr bool is_flag_usable (...) {
    return false;
}

template<class Tag, int = adl_flag (Tag {})>
constexpr bool is_flag_usable (int) {
    return true;
}

template<bool B, class Tag = detail::A>
struct dependent_writer : detail::writer<Tag> { };

template
< class Tag = detail::A
, bool    B = is_flag_usable<Tag> (0)
, int       = sizeof (dependent_writer<B>)
>
constexpr int f () {
    return B;
}

int main () {
    constexpr int a = f ();
    constexpr int b = f ();
    constexpr int c = f ();

    std::cerr << "a: " << a << std::endl;
    std::cerr << "b: " << b << std::endl;
    std::cerr << "c: " << c << std::endl;
    // static_assert (a != b, "fail");
}
