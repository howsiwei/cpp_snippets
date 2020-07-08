#include <iostream>

// ctor: zero-initialize? no
// no warning about slicing? yes

class A
{
private:
    int a;

public:
    void f()
    {
        std::cout << a << '\n';
    }
};

struct B : A
{
    int b;
};

int main()
{
    A a;
    // std::cout << a.a << '\n';
    B b;
    a = b;
    b.f();
}
