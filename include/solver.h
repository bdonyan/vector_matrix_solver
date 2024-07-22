#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>

class LinearSolver {
public:
    static std::vector<double> solve_direct(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    static std::vector<double> solve_gauss_seidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    static std::pair<std::vector<std::vector<double>>, std::vector<double>> read_matrix_from_file(const std::string& filename);
};

#endif // SOLVER_H
