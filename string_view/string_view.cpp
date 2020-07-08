#include <iostream>
// #include <experimental/string_view>

void* operator new(std::size_t n)
{
    std::cout << "[allocating " << n << " bytes]\n";
    return malloc(n);
}

// bool compare(std::experimental::string_view s1, std::experimental::string_view s2)
bool compare(std::string_view s1, std::string_view s2)
{
    if (s1 == s2)
        return true;
    std::cout << '\"' << s1 << "\" does not match \"" << s2 << "\"\n";
    return false;
}

int main()
{
    std::string str = "this is my input string";

    compare(str, "this is the first test string");
    compare(str, "this is the second test string");
    compare(str, "this is the third test string");

    std::string_view sv(&str.at(str.find_first_of('m')));

    compare(str, sv);
    return 0;
}
