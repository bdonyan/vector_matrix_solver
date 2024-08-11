#include "solver.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <cmath>
#include <algorithm>

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

std::pair<std::vector<std::vector<double>>, std::vector<double>> LinearSolver::read_matrix_from_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file " + filename);
    }

    int num_nodes = 0; // Total number of nodes
    std::vector<std::vector<double>> G; // Conductance matrix
    std::vector<double> b; // RHS vector

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string element_type;
        int node1, node2;
        double value;

        iss >> element_type >> node1 >> node2 >> value;

        // Update the number of nodes
        num_nodes = std::max(num_nodes, std::max(node1, node2));

        // Resize the matrix and vector if necessary
        if (G.size() != num_nodes) {
            G.resize(num_nodes, std::vector<double>(num_nodes, 0.0));
            b.resize(num_nodes, 0.0);
        }

        if (element_type[0] == 'R') {
            // Handle resistor
            double conductance = 1.0 / value;
            if (node1 != 0) {
                G[node1-1][node1-1] += conductance;
                if (node2 != 0) {
                    G[node1-1][node2-1] -= conductance;
                    G[node2-1][node2-1] += conductance;
                    G[node2-1][node1-1] -= conductance;
                }
            } else {
                G[node2-1][node2-1] += conductance;
            }
        } else if (element_type == "V") {
            int voltage_index = num_nodes; // New row/column for the voltage source
            G.resize(voltage_index + 1);
            for (auto &row : G) {
                row.resize(voltage_index + 1, 0.0);
            }
            b.resize(voltage_index + 1, 0.0);

            if (node1 != 0) {
                G[node1-1][voltage_index] = 1;
                G[voltage_index][node1-1] = 1;
            }

            if (node2 != 0) {
                G[node2-1][voltage_index] = -1;
                G[voltage_index][node2-1] = -1;
            }

            b[voltage_index] = value;
        }
    }
    
    // // Print Conductance Matrix G
    // std::cout << "Conductance Matrix G:\n";
    // for (size_t i = 0; i < G.size(); ++i) {
    //     for (size_t j = 0; j < G[i].size(); ++j) {
    //         std::cout << G[i][j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // // Print RHS Vector b
    // std::cout << "RHS Vector b:\n";
    // for (size_t i = 0; i < b.size(); ++i) {
    //     std::cout << b[i] << " ";
    // }
    // std::cout << std::endl;

    return {G, b};
}


// REGULAR MATRIX SOLVER
// std::pair<std::vector<std::vector<double>>, std::vector<double>> LinearSolver::read_matrix_from_file(const std::string& filename) {
//     std::ifstream file(filename);
//     if (!file.is_open()) {
//         throw std::runtime_error("Could not open file " + filename);
//     }

//     std::vector<std::vector<double>> A;
//     std::vector<double> b;
//     std::string line;
//     while (std::getline(file, line)) {
//         std::istringstream iss(line);
//         std::vector<double> row((std::istream_iterator<double>(iss)), std::istream_iterator<double>());
//         if (row.size() > 1) {
//             b.push_back(row.back());
//             row.pop_back();
//             A.push_back(row);
//         }
//     }

//     return {A, b};
// }
