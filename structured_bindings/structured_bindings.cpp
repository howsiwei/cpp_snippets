#include <iostream>
#include <tuple>

int main()
{
    auto tuple = std::make_tuple(1, 'a', 2.3);

    // unpack the tuple into individual variables declared at the call site
    auto [ i, c, d ] = tuple;

    std::cout << "i=" << i << " c=" << c << " d=" << d << '\n';

    return 0;
}

