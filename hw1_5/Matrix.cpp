/*
    JTSK-320111
    Matrix.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Matrix.h"

int Matrix::calIndex(int m, int n) const {
    //calculate the index at the dynamic array
    return m * (this->n) + n;
}

Matrix::Matrix(){
    this->m = 0;
    this->n = 0;
    this->darr = NULL;
}

Matrix::Matrix(int m, int n){
    this->darr = new double[m * n]; //dynamic allocation
    this->m = m;
    this->n = n;
}

Matrix::~Matrix(){
    delete [] this->darr;
}

void Matrix::resize(int m, int n){
    delete [] this->darr;
    this->darr = new double[m * n];
    this->m = m;
    this->n = n;
    return;
}

void Matrix::setPosition(int m, int n, double data){
    //set data in corresponding position
    int idx = calIndex(m, n);
    this->darr[idx] = data; //assign the data
    return;
}

double Matrix::at(int m, int n) const {
    return this->darr[calIndex(m, n)];
}

std::istream& operator>>(std::istream& is, Matrix& mat){
    //read dimensions
    int m;
    int n;
    is >> m;
    is >> n;
    mat.resize(m, n);

    double tmp;

    //read it row by row, then column
    for(int i = 0; i < mat.rows(); i++){
        //outer loop, index for n
        for(int j = 0; j < mat.columns(); j++){
            is >> tmp;
            mat.setPosition(i, j, tmp);
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat){
    for(int i = 0; i < mat.rows(); i++){
        for(int j = 0; j < mat.columns(); j++){
            os << mat.at(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

Vector operator*(const Matrix& mat, const Vector& vec){
    if(mat.columns() != vec.length())
        return Vector();
    Vector res(mat.rows());
    for(int i = 0; i < mat.rows(); i++){
        double sum = 0.0;
        for(int j = 0; j < mat.columns(); j++){
            sum += mat.at(i,j) * vec.at(j);
        }
        res.setAt(i, sum);
    }
    return res;
}

Vector operator*(const Vector& vec, const Matrix& mat){
    if(mat.rows() != vec.length())
        return Vector();
    Vector res(mat.columns());
    for(int i = 0; i < mat.columns(); i++){
        double sum = 0.0;
        for(int j = 0; j < mat.rows(); j++){
            sum += mat.at(j, i) * vec.at(j);
        }
        res.setAt(i, sum);
    }
    return res;
}
