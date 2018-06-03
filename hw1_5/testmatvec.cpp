/*
    JTSK-320111
    testmatvec.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Matrix.h"
#include <fstream>

using namespace std;
int main(int argc, char** argv){
    Matrix mat;
    Vector vec;

    ifstream in1("in1.txt");
    ifstream in2("in2.txt");
    in1 >> mat;
    in2 >> vec;

    cout << "Vector:" << endl;
    cout << vec;

    cout << "Matrix:" << endl;
    cout << mat;

    ofstream out1("out1.txt");
    ofstream out2("out2.txt");
    out1 << mat;
    out2 << vec;
    
    //let's try multiplication
    cout << "Multiplication:" << endl;
    cout << mat * vec;
    cout << "Another multiplciation:" << endl;
    cout << vec* mat;
}

