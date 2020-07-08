#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define SZ(a) (int)(a).size()
typedef long long ll;

namespace std {
	template<typename S, typename T>
	struct hash<pair<S, T>> {
		size_t operator()(const pair<S, T> p) const {
			size_t seed = 0;
			seed ^= hash<S>()(p.first) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			seed ^= hash<T>()(p.second) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
			return seed;
		}
	};
}

int main() {
	cin.sync_with_stdio(false);
	return 0;
}
