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
   git clone https://github.com/yourusername/vector_matrix_solver.git
   cd vector_matrix_solver
   ```

2. **Create a Build Directory**
   ```sh
   mkdir build
   cd build
   ```

3. **Generate Build Files**
   ```sh
   cmake ..
   ```

4. **Compile the Project**
   ```sh
   make
   ```

5. **Run the Executable**
   ```sh
   ./solver
   ```

## Examples
### Input
Matrix \( A \):
```
2  1 -1
-3 -1 2
-2  1 2
```
Vector \( b \):
```
8
-11
-3
```

### Output
Solution vector \( x \):
```
2 3 -1
```

## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes.

## License
This project is licensed under the MIT License.
