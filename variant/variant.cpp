#include <variant>
#include <string>
#include <iostream>

int main()
{
    std::variant<int, float> v{12}, w;
    int i = std::get<int>(v);
    w = std::get<int>(v);
    w = std::get<0>(v);  // same effect as the previous line
    // w = 0.0;  // error
    w = 0.0f;

    //  std::get<double>(v); // error: no double in [int, float]
    //  std::get<3>(v);      // error: valid index values are 0 and 1

    try {
        std::get<float>(w); // w contains int, not float: will throw
    }
    catch (std::bad_variant_access&) {}

    constexpr std::variant<int, int> a(std::in_place_index<1>, 3);
    // a = 0;  // error
    // auto b = std::get<0>(a);  // error
    std::cout << a.index() << " " << std::get<a.index()>(a) << std::endl;

    if(auto pval = std::get_if<int>(&v))
        std::cout << "variant value: " << *pval << '\n';
    else
        std::cout << "failed to get value!" << '\n';
}
