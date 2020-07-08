#include <cassert>

struct Base {
    virtual int Foo() const {
        return -1;
    }
};

struct Derived : public Base {
    virtual int Foo() const override {
        return -2;
    }
};

int main() {
    Derived x = Derived();

    assert(-2 == x.Foo());
    assert(-2 == x.Derived::Foo());

    //syntax is trippy but it works
    assert(-1 == x.Base::Foo());

    return 0;
}
