/*
    JTSK-320111
    minheritance1.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include<iostream>
using namespace std;
 
class A
{
  int x;
public:
  void setX(int i) {x = i;}

  // this method will be inherited by both class B and class C
  // also, let's break the line. It is bad that you print without a line break
  void print() { cout << x << endl; }
};
 
// we can use virtual inheritence to fix it
class B:  public virtual A
{
public:
  B()  { setX(10); }
};
 
// also use virtual inheritence
class C:  public virtual A  
{
public:
  C()  { setX(20); }
};
 
class D: public B, public C {
    //here print() is inherited twice
    // the later it inherited, it will be executed
};
 
int main()
{
    D d;
    d.print();
    return 0;
}
