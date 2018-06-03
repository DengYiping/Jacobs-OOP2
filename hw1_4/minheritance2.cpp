/*
    JTSK-320111
    minheritance2.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include<iostream>
using namespace std;

class A
{
  int x;
public:
  A(int i) { x = i; }
  // this is bad, line break is important
  void print() { cout << x << endl; }
};

class B: virtual public A
{
public:
  B():A(10) {  }
};

class C:  virtual public A
{
public:
  C():A(10) {  }
};

class D: public B, public C {
    // there is no default constructor for D
    // We should call the constructor of C, B, and A seperately
public:
    D(): C(), B(), A(10) {}
};

int main()
{
    D d;
    d.print();
    return 0;
}
