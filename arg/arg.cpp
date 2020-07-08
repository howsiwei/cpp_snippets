#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define SZ(a) (int)(a).size()
typedef long long ll;

int main(int argc, char* argv[]) {
	cin.sync_with_stdio(false);
	printf("%d\n", argc);
	for (int i = 0; i < argc; i++) {
		puts(argv[i]);
	}
	return 0;
}
