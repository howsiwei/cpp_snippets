class any {
    virtual ~any() = 0;
    virtual any(const any&) = 0;
    virtual any& operator=(const any&) = 0;
    virtual any(any&&) = 0;
    virtual any& operator=(any&&) = 0;
};

template <typename T>
class tany {
public:
    tany(const T& v) : value(v) {}
    T value;
};

template <typename T>
tany<T> make_any(const T& value) {
    return tany<T>(value);
}

int main() {
    make_any(0);
}
