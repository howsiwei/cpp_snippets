#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::map<std::vector<int>, std::vector<std::vector<int>>> a;
    a[{0, 1}] = {
        {0, 1, 2},
        {3, 4, 5},
    };
    return 0;
}
