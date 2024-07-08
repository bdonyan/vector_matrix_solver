#include <iostream>
#include <vector>

class Vector {
public:
    std::vector<double> data;

    Vector(int size) : data(size) {}

    // Addition
    Vector operator+(const Vector& other) const {
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Subtraction
    Vector operator-(const Vector& other) const {
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Dot product
    double dot(const Vector& other) const {
        double result = 0;
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    // Print vector
    void print() const {
        for (const auto& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};
