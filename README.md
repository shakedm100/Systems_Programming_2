# Exercise 1: Graph Algorithms

## Overview
This project implements several fundamental graph algorithms taught in the Algorithms 1 course. The algorithms included are:

1. **Breadth-First Search (BFS):**  
   Builds a shortest-path tree (without edge weights) using a custom Queue.

2. **Depth-First Search (DFS):**  
   Builds a depth-first tree (without edge weights).

3. **Dijkstra's Algorithm:**  
   Computes the shortest-path tree from a single source, taking edge weights into account.

4. **Prim's Algorithm:**  
   Constructs a Minimum Spanning Tree (MST) by greedily selecting the next lightest edge.

5. **Kruskal's Algorithm:**  
   Constructs an MST using a Union-Find data structure for cycle detection.

The project is implemented in C++ and uses custom data structures for graph representation and algorithm support.

## Features

- **Graph Representation:**  
  An undirected graph is implemented using adjacency lists.

- **Algorithms Implemented:**
  - **BFS:** Uses a custom Queue to traverse the graph level by level.
  - **DFS:** Recursively traverses the graph.
  - **Dijkstra's Algorithm:** Finds the shortest-path tree from a source vertex.
  - **Prim's Algorithm:** Constructs an MST by selecting the next minimal edge.
  - **Kruskal's Algorithm:** Constructs an MST by sorting edges (via selection sort) and using Union-Find to avoid cycles.

- **Custom Data Structures:**
  - **Queue:** A basic queue implementation used in BFS.
  - **UnionFind:** Implements union by rank and path compression; used in Kruskal's algorithm.

- **Testing and Quality Assurance:**
  - **Unit Tests:** Written using the Doctest framework.
  - **Memory Leak Checks:** Conducted using Valgrind.

## Installation and Build Instructions

This project uses a Makefile for building. Ensure you have `make` and a C++ compiler (supporting C++11) installed and a g++ compiler.

### Build Targets

- **Main Application:**  
  Compiles the project with `Main.cpp` as the entry point.
  ```bash
  make main
  ```
  
- **Test Suite:**  
  Compiles and runs the unit tests (located in `Test.cpp`).
  ```bash
  make test
  ```
  
- **Valgrind Check:**  
  Compiles the test target and runs Valgrind to check for memory leaks.
  ```bash
  make valgrind
  ```

- **Clean Build Artifacts:**  
  Removes all generated object files and executables.
  ```bash
  make clean
  ```

## Project Structure

```
.
├── units/                    
│   ├── DataStructures.hpp   # Common header for basic data structures (e.g., Vertex, Edge).
│   ├── Queue.cpp            # Implementation of the Queue class.
│   └── UnionFind.cpp        # Implementation of the UnionFind class.
├── Algorithms.cpp           # Implementation of graph algorithms (BFS, DFS, Dijkstra, Prim, Kruskal).
├── Algorithms.hpp           # Declarations for graph algorithms.
├── Graph.cpp                # Implementation of the undirected graph using adjacency lists.
├── Graph.hpp                # Graph class definition.
├── Main.cpp                 # Main program entry point.
├── Makefile                 # Build configuration and targets.
├── Test.cpp                 # Unit tests using Doctest.
└── README.md                # Project documentation.
```

### Detailed Components

1. **units/**:  
   Contains custom data structures required by the algorithms:
   - **DataStructures.hpp:** Definitions for `Vertex`, `Edge`, etc.
   - **Queue.cpp:** Implements a basic queue for BFS.
   - **UnionFind.cpp:** Implements union-find operations for Kruskal's algorithm.

2. **Algorithms.cpp / Algorithms.hpp:**  
   Implements the following graph algorithms:
   - BFS, DFS, Dijkstra's Algorithm, Prim's Algorithm, and Kruskal's Algorithm.

3. **Graph.cpp / Graph.hpp:**  
   Implements an undirected graph using adjacency lists.

4. **Main.cpp:**  
   Provides a basic interface to run the algorithms on a predefined graph.

5. **Test.cpp:**  
   Contains unit tests to validate the correctness of the algorithms and graph functionality using Doctest.

6. **Makefile:**  
   Contains targets to build the main application, run tests, perform Valgrind memory checks, and clean up build artifacts.

## Usage Examples

To compile and run the main application:
```bash
make main
./main
```

To compile and run the unit tests:
```bash
make test
```

To run the tests under Valgrind (for memory leak checking):
```bash
make valgrind
```

To clean up build artifacts:
```bash
make clean
```

## Author

**Shaked Michael**  
Email: shaked1mi@gmail.com
