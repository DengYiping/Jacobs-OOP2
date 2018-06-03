/*
    JTSK-320111
    Matrix.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include <iostream>
#include "Vector.h"
class Matrix{
    private:
        int m;
        int n;
        //its dimensions
        double* darr; //store the thing in a dynamic array
    public:
        Matrix();
        Matrix(int m, int n); //constructor
        ~Matrix();

        void setPosition(int m, int n, double data);
        double at(int m, int n) const;
        int calIndex(int m, int n) const;

        void resize(int m, int n);
        int rows() const {
            return m;
        }

        int columns() const {
            return n;
        }
};

std::istream& operator>>(std::istream& is, Matrix& mat);
std::ostream& operator<<(std::ostream& os, const Matrix& mat);

//matrix vector multiplication
Vector operator*(const Matrix& mat, const Vector& vec);

//vector matrix multiplication
Vector operator*(const Vector& vec, const Matrix& mat);
