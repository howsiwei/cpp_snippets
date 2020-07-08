class complex {
    double re, im;
public:
    complex(double r, double i) : re{r}, im{i} {}

    double real() const { return re; }

    double imag() const;

    complex& operator+=(complex z) {
        re += z.re;
        im += z.im;
        return *this;
    }

    friend complex operator+(complex, complex);

    // complex operator+(complex z) {
    //     auto a = *this;
    //     return a += z;
    // }

};

double complex::imag() const { return im; }

complex operator+(complex a, complex b) {
    a.re;
    return a += b;
}

int main() {
    auto a = complex(1, 0);
    auto b = complex(0, 1);
    auto c = a + b;
    return 0;
}
