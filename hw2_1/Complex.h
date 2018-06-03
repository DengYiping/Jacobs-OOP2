/*
    JTSK-320111
    Complex.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
/*
    CH08-320142
    Complex.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <iostream>

class Complex{
    private:
        float re; //the real part
        float im; //the imaginary part
    public:
        Complex();
        Complex(float n_re, float n_im);
        ~Complex();

        Complex(const Complex& other); //copy constructor
        Complex& operator=(const Complex& other);//copy assignment constructor
        //constructor, destructor
        //

        float getRe() const;
        float getIm() const;
        void setRe(float n_re);
        void setIm(float n_im);
        //getter and setter

        Complex mul(const Complex& other) const;
        Complex add(const Complex& other) const;
        Complex sub(const Complex& other) const;
        Complex conjugate();

        friend std::istream& operator>>(std::istream& is, Complex& comp);

        void print();
};

// outside definition
// better have it outside
Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

std::ostream& operator<<(std::ostream& os, const Complex& comp);
std::istream& operator>>(std::istream& is, Complex& comp);
