//shaked1mi@gmail.com


#include "Algorithms.hpp"
#include <iostream>
#include "Graph.hpp"

using namespace graph;
using namespace std;

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);

    cout << "The original graph:" << endl;
    graph.printGraph();

    int input = 5;
    while(input != 0)
    {
        cout << "Enter an algorithm you want run on the graph:\n 1. Breadth-first search (BFS)\n 2. Depth-first search (DFS)\n 3. Dijkstra (Single source shortest path)\n 4. Prim (Minimum Spanning Tree)\n 5. Kruskal (Minimum Spanning Tree)\n 6. Original Graph\n" << endl;

        cin >> input;

        switch (input)
        {
            case 1:
            {
                const Vertex* first = graph.getAdj()[0];
                Graph algo = BFS(graph, (*first));
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 2:
            {
                Graph algo = DFS(graph, 0);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 3:
            {
                Graph algo = dijkstra(graph,0);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 4:
            {
                Graph algo = primMST(graph);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 5:
            {
                Graph algo = kruskalMST(graph);
                algo.printGraph();
                cout << "\n";
                break;
            }
            case 6:
            {
                graph.printGraph();
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