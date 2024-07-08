#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <iostream>

class Vector {
public:
    std::vector<double> data;
    Vector(int size);
    Vector(std::vector<double> d);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    double dot(const Vector& other) const;
    void print() const;
};

#endif // VECTOR_H
