/*
    JTSK-320111
    Vector.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
/*
    CH08-320142
    Vector.cpp
    Yiping Deng
    y.deng@jacobs-university.de
*/
#include "Vector.h"
#include <iostream>
#include <cstring>
#include <cmath>

Vector::Vector(){
    db_arr = NULL;
    size = 0;
}

Vector::Vector(int s){
    size = s;
    db_arr = new double[s];
}

Vector::Vector(const Vector& other){
    size = other.size;
    db_arr = new double[size];
    memcpy(db_arr, other.db_arr, sizeof(double) * size);
    //copy raw memory to the destination
}

Vector::~Vector(){
    if(db_arr != NULL)
        delete [] db_arr;// delete if not null
}

double Vector::at(int i) const{
    return db_arr[i];
}//indexing

void Vector::setAt(int i, double d){
    if(i >= size)
        exit(1); // error on size
    db_arr[i] = d;
}

int Vector::length() const {
    return size;
}
//return the size

void Vector::grow(int i){
    double* tmp = db_arr;
    int prev_size = size;
    //previous info
    if(i <= size)
        return;
    //set proper value and grow
    db_arr = new double[i];
    size = i;
    if(prev_size == 0 || tmp == NULL)
        return;
    //make sure the pointers are valid
    memcpy(db_arr, tmp, sizeof(double) * prev_size);
    //copy the content
    delete [] tmp;
    //free the resources
}

void Vector::print() const {
    if(size == 0){
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for(int i = 0; i < size; i++){
        std::cout << db_arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

double Vector::norm() const {
    double sq_sum = 0.0;
    for(int i = 0; i < size; i++)
        sq_sum += db_arr[i];
    return sqrt(sq_sum);
}

Vector Vector::sum(const Vector& other) const {
   if(size != other.size)
       return Vector();
   Vector rst(size); // create a equal size vector
   for(int i = 0; i < size; i++){
       rst.setAt(i, at(i) + other.at(i));
   }//add the result
   return rst;
}

Vector Vector::diff(const Vector& other) const {
   if(size != other.size)
       return Vector();
   Vector rst(size); // create a equal size vector
   for(int i = 0; i < size; i++){
       rst.setAt(i, at(i) - other.at(i));
   }//add the result
   return rst;
}

double Vector::scalarP(const Vector& other) const {
    if(size == 0 || size != other.size)
        return 0;
    double p = 0.0;
    for(int i = 0; i < size; i++){
        p += at(i) * other.at(i);
    }
    return p;
}

std::istream& operator>>(std::istream& is, Vector& vec){
    //retrieve a integer for the dimension of the vector
    //then retrieve every entry of the vector
    int n;
    int tmp;

    is >> n;
    vec.grow(n);

    for(int i = 0; i < n; i++){
        is >> tmp; //retrieve the data
        vec.setAt(i, tmp);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Vector& vec){
    //give the output of the file
    if(vec.length() == 0)
        return os;
    os << "[";
    for(int i = 0; i < vec.length() - 1; i++){
        os << vec.at(i) << ",";
    }
    os << vec.at(vec.length() - 1) << "]" << std::endl;
    //comma seperated
    return os;
}
