#include <iostream>
#include <map>

struct A
{
    A()
    {
        std::cout << "default constructed\n";
    }

    A(int)
    {
        std::cout << "constructed with parameter\n";
    }

    A(const A&)
    {
        std::cout << "copy constructed\n";
    }

    A& operator=(const A&)
    {
        std::cout << "copy assigned\n";
        return *this;
    }
};

int main()
{
    A a = A(0);
    std::cout << '\n';

    std::map<int, A> amap;
    amap[0] = A(0);
    std::cout << '\n';

    amap.emplace(1, 0);
    std::cout << '\n';

    amap.emplace(1, A(0));
    std::cout << '\n';

    amap.insert({1, A(0)});
    std::cout << '\n';

    return 0;
}
