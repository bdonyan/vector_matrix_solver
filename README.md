# Vector Matrix Solver

This project provides a C++ implementation for solving a system of linear equations using Gaussian elimination.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Compilation and Execution](#compilation-and-execution)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Overview

This project is a C++ program designed to solve electrical circuits composed of resistors and voltage sources using conductance matrices and numerical methods like Gaussian Elimination and Gauss-Seidel iteration. The program reads circuit data from an input file, constructs the conductance matrix and right-hand side (RHS) vector, and then solves for the node voltages and current through the voltage sources.

## Features

- **Input Parsing**: Reads circuit data from a text file specifying resistors and voltage sources in a netlist format.
- **Matrix Construction**: Constructs a conductance matrix (G matrix) and a RHS vector (b vector) representing the circuit equations.
- **Numerical Solvers**:
  - **Gaussian Elimination**: Direct solver that transforms the conductance matrix into an upper triangular matrix and performs back substitution to find the solution.
  - **Gauss-Seidel Iteration**: Iterative solver that improves the solution estimate until convergence is achieved.
- **Output**: The program outputs the node voltages and current through the voltage sources, with clear labeling of each quantity.

## Project Structure
```
vector_matrix_solver/
├── src/
│   ├── main.cpp
│   ├── vector.cpp
│   ├── matrix.cpp
│   ├── solver.cpp
├── include/
│   ├── vector.h
│   ├── matrix.h
│   ├── solver.h
├── CMakeLists.txt
└── README.md
```

## Usage
The project can be used to solve systems of linear equations of the form `Ax = b`, where `A` is a matrix and `b` is a vector.

## Compilation and Execution
### Prerequisites
- CMake
- g++ (GNU Compiler Collection)

### Steps
1. **Clone the Repository**
    ```sh
    git clone https://github.com/yourusername/your-repo.git
    cd your-repo
    ```

2. **Create a Build Directory and Generate Makefiles**
    ```sh
    mkdir build
    cd build
    cmake ..
    ```

3. **Compile the Project**
    ```sh
    make
    ```

4. **Run the Executable**
    ```sh
    ./solver ../input.txt 0   # For direct solver
    ./solver ../input.txt 1   # For Gauss-Seidel solver
    ```

## Input File Format

The input file should contain the following information:

- Resistor entries in the format: `R <Node1> <Node2> <Resistance Value>`
- Voltage source entries in the format: `V <Node1> <Node2> <Voltage Value>`

### Examples

```txt
R 1 2 10
R 2 0 4
V 1 0 1.5
```
```
Conductance Matrix G:
0.1 -0.1 1
-0.1 0.35 -1
1 -1 0

RHS Vector b:
0 0 1.5

Solution:
Voltage at Node 1: 1.5 V
Voltage at Node 2: 0.428571 V
Current through Voltage Source: -0.107143 A
```

## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License
This project is licensed under the MIT License.
