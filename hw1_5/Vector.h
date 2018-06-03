/*
    JTSK-320111
    Vector.h
    Yiping Deng
    y.deng@jacobs-university.de
*/
/*
    CH08-320142
    Vector.h
    Yiping Deng
    y.deng@jacobs-university.de
*/

#include <iostream>
class Vector{
    private:
        double* db_arr;
        int size;
    public:
        Vector();
        Vector(int n_size);
        Vector(const Vector&);
        ~Vector();

        double at(int index) const; //return the value at given index
        void setAt(int index, double value);

        int length() const;
        void grow(int s); //extend the size of the Vector to a given number

        void print() const;
        double norm() const;
        Vector sum(const Vector& other) const;
        Vector diff(const Vector& other) const;
        double scalarP(const Vector& other) const;
};

std::istream& operator>>(std::istream& is, Vector& vec);
std::ostream& operator<<(std::ostream& os, const Vector& vec);
