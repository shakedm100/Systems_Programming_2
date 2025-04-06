//shaked1mi@gmail.com

#include "Algorithms.hpp"
#include <iostream>

using namespace std;
using namespace graph;

int main()
{
    Graph mainGraph(8);
    mainGraph.addEdge(0, 1, 1);
    mainGraph.addEdge(1, 2, 2);
    mainGraph.addEdge(2, 3, 3);
    mainGraph.addEdge(3, 4, 4);
    mainGraph.addEdge(4, 5, 5);
    mainGraph.addEdge(5, 6, 2);
    mainGraph.addEdge(6, 7, 3);
    mainGraph.addEdge(7, 0, 1);
    mainGraph.addEdge(2, 6, 2);
    mainGraph.addEdge(3, 7, 5);
    mainGraph.addEdge(3, 5, 8);
    mainGraph.addEdge(0, 4, 3);


    cout << "The original graph:" << endl;
    mainGraph.printGraph();

    int input = 5;
    while(input != 0)
    {
        cout << "Enter an algorithm you want run on the graph:\n 1. Breadth-first search (BFS)\n 2. Depth-first search (DFS)\n 3. Dijkstra (Single source shortest path)\n 4. Prim (Minimum Spanning Tree)\n 5. Kruskal (Minimum Spanning Tree)\n 6. Original Graph\n 0. Exit\n" << endl;

        cin >> input;

        switch (input)
        {
            case 1:
            {
                const Vertex* first = mainGraph.getAdj()[0];
                Graph algo = BFS(mainGraph, (*first));
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 2:
            {
                Graph algo = DFS(mainGraph, 0);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 3:
            {
                Graph algo = dijkstra(mainGraph,0);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 4:
            {
                Graph algo = primMST(mainGraph);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 5:
            {
                Graph algo = kruskalMST(mainGraph);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 6:
            {
                mainGraph.printGraph();
                break;
            }
            case 0:
                break;
            default:
                cout << "Wrong input, try again" << endl;
                break;
        }
    }

    return 0;
}