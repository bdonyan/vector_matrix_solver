cmake_minimum_required(VERSION 3.10)
project(WorkSolver)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(solver src/main.cpp src/vector.cpp src/matrix.cpp src/solver.cpp)
