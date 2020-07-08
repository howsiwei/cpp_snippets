#include <iostream>
#include <cstdio>
#include <limits>
#include <cmath>
using namespace std;
typedef long long ll;
#define SZ(a) (int)(a).size()

int main() {
	cin.sync_with_stdio(false);
	long double a = 1-1e-16L;
	printf("%.17Lf\n", a);
	printf("%d\n", numeric_limits<long double>::digits10);
	printf("%d\n", numeric_limits<long double>::digits);
	printf("%Lf\n", pow(2.l, 64)+1);
	printf("%Lf\n", pow(2.l, 64)+2);
	printf("%Lf\n", pow(2.l, 64)-1);
	printf("%d\n", numeric_limits<double>::digits);
	printf("%f\n", pow(2., 53)+1);
	printf("%f\n", pow(2., 53)+2);
	printf("%f\n", pow(2., 53)-1);
	printf("%d\n", numeric_limits<float>::digits);
	return 0;
}
