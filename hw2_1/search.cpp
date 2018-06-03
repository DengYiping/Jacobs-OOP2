/*
    JTSK-320111
    search.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <iostream>
#include "Complex.h"

template<typename T>
int array_search(T* arr, const T& ele, int size, bool (*eqs)(const T&, const T&)){
    //use function to make comparision
    if(size < 1)
        return -1;
    for(int i = 0; i < size; i++){
        if(eqs(ele, arr[i]))
            //if existed
            return i;
    }
    return -1;
}

bool eqs_int(const int& i1, const int& i2){
    // make comparision
    if(i1 == i2)
        return true;
    return false;
}

bool eqs_float(const float& f1, const float& f2){
    float diff = f1 - f2;
    if(diff < 0.0001 && diff > -0.0001)
        //don't do floating point equal
        return true;
    return false;
}

bool eqs_complex(const Complex& c1, const Complex& c2){
    float diff1 = c1.getRe() - c2.getRe();
    float diff2 = c1.getIm() - c2.getIm();
    if(diff1 > 0.0001 || diff2 > 0.0001 || diff1 < -0.0001 || diff2 < -0.0001)
        return false;
    return true;
}

int main(int argc, char** argv){
    int is[] = {1, 2, 3, 4, 5};
    float fs[] = {1.2, 4.5, 1.6, 0.0, 2.0, 7};
    Complex cs[] = {Complex(1,2), Complex(1,7), Complex(2, 9)};
    // using lambda to make comparision
    std::cout << "the index of 3 in integer array:";
    std::cout << array_search(is, 3, 5, eqs_int) << std::endl;
    std::cout << "the index of 2 in floating point array:";
    float f = 2.0;
    std::cout << array_search(fs, f, 6, eqs_float) << std::endl;
    std::cout << "the index of Complex (1,7) in the array:";
    Complex c(1,7);
    std::cout << array_search(cs, c, 3, eqs_complex) << std::endl;

    return 0;
}
