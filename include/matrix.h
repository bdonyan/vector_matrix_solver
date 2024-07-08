#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix {
public:
    std::vector<std::vector<double>> data;
    Matrix(int rows, int cols);
    Matrix(std::vector<std::vector<double>> d);
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    void print() const;
};

#endif // MATRIX_H
