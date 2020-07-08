#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

// Local Variables:
// rmsbolt-command: "g++ -O3"
// rmsbolt-disassemble: nil
// End:

#define SZ(a) (int)(a).size()
using ll = long long;

int main() {
    cin.sync_with_stdio(false);
    unordered_set<string> ss;
    ss.insert("a");
    for (auto s: ss) {
        cout << s << endl;
    }
    return 0;
}
