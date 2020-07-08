#include <cstdio>

class Base {
public:
    virtual void bar() const = 0;
private:
    long long base_value;
};

class Derived : public Base {
public:
    void bar() const {}
private:
    long long value;
};

class Derived2 : public Derived {
public:
    void bar() const {
        puts("Derived2");
    }
};

int main() {
    // Base base;
    const Derived& derived = Derived2();
    const Base& base = derived;
    printf("%zd\n", sizeof(derived));
    printf("%zd\n", sizeof(base));
    base.bar();
    derived.bar();
}
