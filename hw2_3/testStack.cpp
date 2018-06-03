/*
    JTSK-320111
    testStack.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Stack.h"
#include <iostream>

using namespace std;
int main(int argc, char** argv){

    //three integers
    int a = 1;
    int b = 2; 
    int c = 3;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    Stack<int> s;
    s.push(a);
    s.push(b);
    s.push(c);

    cout << "current size: " << s.getSize() << endl;
    cout << "let's resize a bit" << endl;
    s.resize(30);
    cout << "current size: " << s.getSize() << endl;

    int d, e, f;
    s.pop(d);
    s.pop(e);
    s.pop(f);

    cout << "d: " << d << endl;
    cout << "e: " << e << endl;
    cout << "f: " << f << endl;


    s.push(a);
    s.push(b);
    s.push(c);

    cout << "current size: " << s.getSize() << endl;
    cout << "let's resize a bit" << endl;
    s.resize(2);
    cout << "current size: " << s.getSize() << endl;

    int g, h;

    s.pop(g);
    s.pop(h);
    cout << "g: " << g << endl;
    cout << "h: " << h << endl;

    return 0;
}
