#include <cstdio>
#include <utility>

// Local Variables:
// rmsbolt-command: "g++ -std=c++17 -Wall -Wextra -Werror"
// rmsbolt-demangle: t
// rmsbolt-disassemble: nil
// End:

struct Animal {
    Animal(int id) : id(id) {
        puts("Constructing Animal");
    }
    virtual ~Animal() = default;
    virtual void eat() {
        puts("Animal eating");
    }
    // Animal(const Animal&) {
    //     puts("Calling Animal copy constructor");
    // }
    // Animal(Animal&&)
    // = default;
        // {
        //     puts("Calling Animal move constructor");
        // }

    int id;
};

// void Animal::eat() {
//     puts("Animal eating");
// }

struct Mammal: virtual Animal {
    Mammal(int id) : Animal(id) {
        puts("Constructing Mammal");
    }
    // ~Mammal() = default;
    virtual void eat() override {
        puts("Mammal eating");
    }
    // virtual void breathe() {}
};

struct WingedAnimal: virtual Animal {
    WingedAnimal(int id) : Animal(id) {
        puts("Constructing WingedAnimal");
    }
    // ~WingedAnimal() = default;
    virtual void eat() override {
        puts("WingedAnimal eating");
    }
    // virtual void flap() {}
};

// A bat is a winged mammal
struct Bat: Mammal, WingedAnimal {
    Bat(int id) : Animal(id), Mammal(id), WingedAnimal(id) {
        puts("Constructing Bat");
    }
    // ~Bat() = default;
    virtual void eat() override {
        puts("Bat eating");
    }
};

// void f(Bat& bat);

void f(Bat bat) {
    bat.eat();
    static_cast<Mammal&>(bat).eat();
}

void g() {
    Animal m(13);
    m.eat();
    // Animal m1 = m;
    // Animal m2 = std::move(m);
}

int main() {
    Bat bat(13);
    f(bat);
    // g();
}
