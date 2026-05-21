# Hungarian Algorithm for Cost Minimization

This repository contains a C++ implementation of the **Hungarian Algorithm**, a combinatorial optimization algorithm that solves the assignment problem in polynomial time. 

> **Note:** This project is currently **incomplete** and is a work in progress. Additional updates and refinements will be added later.

## Overview

The Hungarian Algorithm is used to find the minimum cost in a bipartite matching problem, often represented as assigning a set of workers to a set of jobs, where each worker-job pair has an associated cost. The goal is to minimize the total cost of all assignments.

### Current Implementation Status

The existing `assignment.cpp` includes the foundational steps of the algorithm:
- **Row Operation**: Subtracts the minimum value of each row from all elements in that row.
- **Column Operation**: Subtracts the minimum value of each column from all elements in that column.
- **Assignment Check**: Attempts to find a complete assignment using the zeros in the matrix.
- **Matrix Adjustment**: Adjusts the cost matrix using the minimum uncovered value when a complete assignment is not yet possible.

*(Note: The assignment checking and matrix adjustment logic might be incomplete or require further refinement for complex edge cases).*

## Usage

### Prerequisites
- A C++ compiler (e.g., GCC/g++)

### Running the Code

1. Compile the code:
   ```bash
   g++ assignment.cpp -o a.exe
   ```
2. Run the executable:
   ```bash
   ./a.exe
   ```
3. Enter the input when prompted:
   - First, enter the number of jobs (and workers).
   - Then, provide the cost matrix.

## Future Work
- Finalize the algorithm to handle all edge cases correctly.
- Add test cases and input validation.
- Improve efficiency and code structure.
