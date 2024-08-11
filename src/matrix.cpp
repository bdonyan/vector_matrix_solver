#include <iostream>
#include <vector>

class Matrix {
public:
    std::vector<std::vector<double>> data;

    Matrix(int rows, int cols) : data(rows, std::vector<double>(cols)) {}

    // Addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(data.size(), data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Subtraction
    Matrix operator-(const Matrix& other) const {
        Matrix result(data.size(), data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < data[i].size(); ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Multiplication
    Matrix operator*(const Matrix& other) const {
        Matrix result(data.size(), other.data[0].size());
        for (size_t i = 0; i < data.size(); ++i) {
            for (size_t j = 0; j < other.data[0].size(); ++j) {
                for (size_t k = 0; k < data[0].size(); ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Print matrix
    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    void resize(int rows, int cols) {
        data.resize(rows);
        for (auto &row : data) {
            row.resize(cols);
        }
    }

    void insert(int i, int j, double value) {
        data[i][j] += value;
    }
};
