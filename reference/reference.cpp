#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
#define SZ(a) (int)(a).size()

set<int> f() {
    return {};
}

int& mut(int& a, int& b) {
    return a;
}

int main() {
    cin.sync_with_stdio(false);
    auto a = 1;
    auto b = 1;
    auto& x = mut(a, b);
    x = 0;
    printf("%d %d\n", a, b);
    auto pa = &a;
    *pa = 2;
    printf("%d %d\n", a, b);
    auto c = f();
    return 0;
}
