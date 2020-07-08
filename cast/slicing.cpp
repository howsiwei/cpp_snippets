class A {
 public:
  int a;
};
class B : public A {
 public:
  int b;
};
int main() {
  B barray[5];
  A *aarray = barray;
  aarray[4].a = 5;
}
