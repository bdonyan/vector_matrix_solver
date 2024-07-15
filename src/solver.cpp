#include "solver.h"
#include <cmath>
#include <algorithm>
#include <iostream>

std::vector<double> LinearSolver::solve_direct(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    int n = A.size();
    std::vector<std::vector<double>> augmented_matrix(n, std::vector<double>(n + 1));

    // Create augmented matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            augmented_matrix[i][j] = A[i][j];
        }
        augmented_matrix[i][n] = b[i];
    }

    // Gaussian elimination
    for (int i = 0; i < n; ++i) {
        // Find pivot
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::abs(augmented_matrix[k][i]) > std::abs(augmented_matrix[max_row][i])) {
                max_row = k;
            }
        }
        std::swap(augmented_matrix[i], augmented_matrix[max_row]);

        // Make upper triangular
        for (int k = i + 1; k < n; ++k) {
            double factor = augmented_matrix[k][i] / augmented_matrix[i][i];
            for (int j = i; j <= n; ++j) {
                augmented_matrix[k][j] -= factor * augmented_matrix[i][j];
            }
        }
    }

    // Back substitution
    std::vector<double> x(n);
    for (int i = n - 1; i >= 0; --i) {
        x[i] = augmented_matrix[i][n] / augmented_matrix[i][i];
        for (int k = i - 1; k >= 0; --k) {
            augmented_matrix[k][n] -= augmented_matrix[k][i] * x[i];
        }
    }

    return x;
}

std::vector<double> LinearSolver::solve_gauss_seidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
    int n = A.size();
    std::vector<double> x(n, 0.0); // Initial guess
    std::vector<double> x_old(n, 0.0);
    int max_iterations = 10000; // Increase iterations for better accuracy
    double tolerance = 1e-10;

    for (int iter = 0; iter < max_iterations; ++iter) {
        for (int i = 0; i < n; ++i) {
            double sum = b[i];
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    sum -= A[i][j] * x[j];
                }
            }
            x[i] = sum / A[i][i];
        }

        // Check for convergence
        double norm = 0.0;
        for (int i = 0; i < n; ++i) {
            norm += std::pow(x[i] - x_old[i], 2);
        }
        if (std::sqrt(norm) < tolerance) {
            break;
        }
        x_old = x;
    }

    return x;
}
