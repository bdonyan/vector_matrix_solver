#include <iostream>
#include <vector>
#include <string>
#include "vector.h"
#include "matrix.h"
#include "solver.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " -solver [0|1]" << std::endl;
        return 1;
    }

    int solver_type = std::stoi(argv[1]);

    std::vector<std::vector<double>> A;
    std::vector<double> b;

    if (solver_type == 0) {
        // Direct Solver Matrix
        A = {
            {2, 1, -1},
            {-3, -1, 2},
            {-2, 1, 2}
        };
        b = {8, -11, -3};
    } else if (solver_type == 1) {
        // Gauss-Seidel Solver Matrix (diagonally dominant)
        A = {
            {10, -1, 2},
            {-1, 11, -1},
            {2, -1, 10}
        };
        b = {6, 25, -11};
    } else {
        std::cerr << "Invalid solver type. Use 0 for direct solver or 1 for Gauss-Seidel solver." << std::endl;
        return 1;
    }

    std::vector<double> x;

    if (solver_type == 0) {
        x = LinearSolver::solve_direct(A, b);
    } else if (solver_type == 1) {
        x = LinearSolver::solve_gauss_seidel(A, b);
    }

    // Print the solution
    std::cout << "Solution:" << std::endl;
    for (const auto& val : x) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
