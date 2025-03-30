shaked1mi@gmail.com
Shaked Michael
318772191

This project implements various Algorithms we learned in Algorithms 1 course.
The implements Algorithms are:
1. Breadth-first search (BFS)
2. Depth-first search (DFS)
3. Dijkstra (Single source shortest path)
4. Prim (Minimum Spanning Tree)
5. Kruskal (Minimum Spanning Tree)

The division between the files are:
1. units folder that contains implementations of the necessary basic data structures:
    a. Vertex and Edge structs
    b. Queue
    c. UnionFind
2. Graph.cpp that contains the implementation of an undirected graph
3. Algorithms.cpp that contains the implementation of the algorithms that are stated above
4. Test.cpp that contains a test for all the algorithms and the graph using doctest
5. Main.cpp basic interface for running the algorithms on a pre defined graph
6. Makefile that has a few targets:
    a. main - compiles the files using Main.cpp
    b. test - compiles the files using Test.cpp
    c. valgrind - compiles the files using Test.cpp and then check for poor memory optimazations (Memory leaks)
    d. clean - deletes all the object files in the folder
