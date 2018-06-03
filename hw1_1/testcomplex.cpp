/*
    CH08-320142
    testcomplex.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Complex.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char** argv){
    ifstream in1("in1.txt");
    ifstream in2("in2.txt");
    ofstream out("output.txt");

    Complex comp1;
    Complex comp2;
    in1 >> comp1;
    in2 >> comp2;
    cout << "Complex 1:";
    comp1.print();
    cout << "Complex 2:";
    comp2.print();

    cout << "the sum:" << comp1 + comp2;
    out << comp1 + comp2;

    cout << "the difference:" << comp1 - comp2;
    out << comp1 - comp2;

    cout << "the product:" << comp1 * comp2;
    out << comp1 * comp2;

    in1.close();
    in2.close();
    out.close();
}
