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
This project implements a simple C++ linear algebra library with the following components:
- **Vector**: A class for vector operations.
- **Matrix**: A class for matrix operations.
- **LinearSolver**: A class for solving systems of linear equations using Gaussian elimination.

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

## Examples
```sh
./solver ../input.txt 0
# Solution:
2 3 -1

./solver ../input.txt 1
# Solution:
6.80688 1.3733 4.71023
```

## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License
This project is licensed under the MIT License.
