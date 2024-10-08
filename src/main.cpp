#include "solver.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input file> <solver type: 0 for direct, 1 for Gauss-Seidel>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    int solver_type = std::stoi(argv[2]);

    auto [A, b] = LinearSolver::read_matrix_from_file(filename);
    std::vector<double> x;

    if (solver_type == 0) {
        x = LinearSolver::solve_direct(A, b);
    } else if (solver_type == 1) {
        x = LinearSolver::solve_gauss_seidel(A, b);
    } else {
        std::cerr << "Invalid solver type. Use 0 for direct solver or 1 for Gauss-Seidel solver." << std::endl;
        return 1;
    }

    std::cout << "Solution:\n";
    for (size_t i = 0; i < x.size(); ++i) {
        if (i < x.size() - 1) {
            std::cout << "Voltage at Node " << i + 1 << ": " << x[i] << " V\n";
        } else {
            std::cout << "Current through Voltage Source: " << x[i] << " A\n";
        }
    }

    std::cout << std::endl;
    return 0;
}
