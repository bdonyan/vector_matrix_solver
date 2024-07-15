#ifndef SOLVER_H
#define SOLVER_H

#include <vector>

class LinearSolver {
public:
    static std::vector<double> solve_direct(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
    static std::vector<double> solve_gauss_seidel(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
};

#endif // SOLVER_H
