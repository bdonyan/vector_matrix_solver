#include "solver.h"
#include <cmath>
#include <algorithm>

std::vector<double> LinearSolver::solve(const std::vector<std::vector<double>>& A, const std::vector<double>& b) {
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
