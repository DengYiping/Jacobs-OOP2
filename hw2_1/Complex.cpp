/*
    JTSK-320111
    Complex.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
/*
    CH08-320142
    Complex.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Complex.h"
#include <iostream>

Complex::Complex(){
    re = 0.0;
    im = 0.0;
}

Complex::Complex(float n_re, float n_im): re(n_re), im(n_im) {}

//copy constructor
Complex::Complex(const Complex& other){
    re = other.re;
    im = other.im;
}

//set the proper imagnary and real part

Complex::~Complex(){} //empty destructor

float Complex::getRe() const {
    return re;
}

float Complex::getIm() const {
    return im;
}

void Complex::setRe(float n_re){
    re = n_re;
}

void Complex::setIm(float n_im){
    im = n_im;
}

//getter and setter method

void Complex::print(){
    std::cout << re;
    if(im < 0.0)
        std::cout << " - " << -1.0 * im << "i" << std::endl;
    else if(im > 0.0)
        std::cout << " + " << im << "i" <<std::endl;
    else
        std::cout << std::endl;//if there is no imagnary part
}

    //get the proper sign

//all the operation on Complex number
Complex Complex::conjugate(){
    return Complex(re, im * -1.0);
}

Complex Complex::add(const Complex& other) const{
    return Complex(re + other.re, im + other.im);
}

Complex Complex::sub(const Complex& other) const{
    return Complex(re - other.re, im - other.im);
}

Complex Complex::mul(const Complex& other) const{
    float new_re = re * other.re - im * other.im;
    float new_im = re * other.im + im * other.re;
    return Complex(new_re, new_im);
}

//copy assignment operator
Complex& Complex::operator=(const Complex& other){
    re = other.re;
    im = other.im;
    return *this;
}

// just call the function
Complex operator+(const Complex& lhs, const Complex& rhs){
    return lhs.add(rhs);
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    return lhs.sub(rhs);
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    return lhs.mul(rhs);
}

std::ostream& operator<<(std::ostream& os, const Complex& comp){
    // the output will be a tuple
    os << "(" << comp.getRe() << "," << comp.getIm() << ")" << std::endl;
    return os;
}
std::istream& operator>>(std::istream& is, Complex& comp){
    // the input is seperated by space or \n
    float im;
    float re;
    is >> re >> im;
    comp.setRe(re);
    comp.setIm(im);
    return is;
}
