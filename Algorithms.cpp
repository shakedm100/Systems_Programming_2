#include "Graph.hpp"

using namespace std;

Graph bfsAlgo(Graph& graph, Vertice start)
{
    Queue queue;
    int vertices = graph.getVertices();
    queue.setCapacity(vertices);
    int* parent = new int[vertices];
    bool* visited = new bool[vertices];
    int* weights = new int[vertices];

    for (size_t i = 0; i < vertices; i++)
    {
        visited[i] = false;
        parent[i] = -1;
        weights[i] = 0;
    }

    const Vertice** adj = graph.getAdj();
    visited[start.vertex] = true;
    queue.enqueue(start.vertex);

    while (!queue.isEmpty())
    {
        int curr = queue.peek();
        queue.dequeue();

        int j = 0;
        while (adj[curr] != nullptr)
        {
            int neighbor = adj[curr][j].vertex;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = curr; 
                weights[neighbor] =  adj[curr][j].data;
                queue.enqueue(neighbor);
            }
            j++;
        }
    }

    Graph tree(vertices);

    for (size_t i = 0; i < vertices; i++)
    {
        if(parent[i] != -1)
        {
            tree.addEdge(parent[i], i, weights[i]);
        }
    }
    

    delete[] weights;
    delete[] parent;
    delete[] visited;

    return tree;
}