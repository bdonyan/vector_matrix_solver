#include <iostream>
#include <vector>
#include "vector.h"
#include "matrix.h"
#include "solver.h"

int main() {
    // Define a matrix A
    std::vector<std::vector<double>> A = {
        {2, 1, -1},
        {-3, -1, 2},
        {-2, 1, 2}
    };

    // Define a vector b
    std::vector<double> b = {8, -11, -3};

    // Solve for x in Ax = b
    std::vector<double> x = LinearSolver::solve(A, b);

    // Print the solution
    std::cout << "Solution:" << std::endl;
    for (const auto& val : x) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
