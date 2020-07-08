#include <iostream>
#include <vector>

struct Point {
    int x, y;

    Point() {}
    Point(int x, int y) : x{x}, y{y} {}
};

class Shape {
public:
    Shape() {
        std::cerr << "Calling Shape constructor" << std::endl;
    }

    virtual ~Shape() {
        std::cerr << "Calling Shape destructor" << std::endl;
    }
    virtual Point center() const = 0;
};

class Circle : public Shape {
public:
    Circle() {
        std::cerr << "Calling Circle constructor" << std::endl;
    }

    Circle(Point c, int r) {
        std::cerr << "Calling Circle constructor 2" << std::endl;
        _center = c;
        _radius = r;
    }

    Point center() const override {
        return _center;
    }

private:
    Point _center;
    int _radius;
};

class Smiley : public Circle {
public:
    Smiley() {
        std::cerr << "Calling Smiley constructor" << std::endl;
    }

    Smiley(Point c, int r) {
        std::cerr << "Calling Smiley constructor 2" << std::endl;
    }

    ~Smiley() override {
        std::cerr << "Calling Smiley destructor" << std::endl;
        for (auto p: eyes) {
            delete p;
        }
    }
private:
    std::vector<Shape*> eyes;
};

int main() {
    Point p(1, 0);
    Smiley s(p, 1);
}
