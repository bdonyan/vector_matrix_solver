#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <iostream>

class LinearSolver {
public:
    static std::vector<double> solve(const std::vector<std::vector<double>>& A, const std::vector<double>& b);
};

#endif // SOLVER_H
