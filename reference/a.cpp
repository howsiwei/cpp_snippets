#include <cstdio>
#include <set>
using namespace std;

class A {
	int x;
public:
	const int& getX() {
		return 1;
	}
	void setX(int _x) {
		x = _x;
	}
};

int main() {
	A a;
	a.setX(0);
	const int& x = a.getX();
	printf("%d\n", x);
	return 0;
}
