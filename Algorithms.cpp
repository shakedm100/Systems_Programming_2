#include "Algorithms.hpp"
#include "Graph.hpp"
#include <bits/stdc++.h>

using namespace std;

Graph BFS(const Graph& graph, const Vertex start)
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

    const Vertex* const* adj = graph.getAdj();
    visited[start.vertex] = true;
    queue.enqueue(start.vertex);

    while (!queue.isEmpty())
    {
        int curr = queue.peek();
        queue.dequeue();

        const Vertex* currentEdge = adj[curr];
        while (currentEdge != nullptr)
        {
            int neighbor = currentEdge->vertex;
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = curr; 
                weights[neighbor] = currentEdge->data;
                queue.enqueue(neighbor);
            }
            currentEdge = currentEdge->next;
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


void DFSHelper(const Graph& graph, int start, bool* visited, Graph& DFSTree)
{
    visited [start] = true;

    for (int neighbor = 0; neighbor < graph.getVertices(); neighbor++) {
        if (!visited[neighbor] && graph.hasEdge(start, neighbor))
        {
            DFSTree.addEdge(start, neighbor, graph.getWeight(start, neighbor));
            DFSHelper(graph, neighbor, visited, DFSTree);
        }

    }
}

Graph DFS(const Graph& g, int start) 
{
    bool* visited = new bool[g.getVertices()];
    Graph DFSTree(g.getVertices());

    for (size_t i = 0; i < g.getVertices(); i++)
    {
        visited[i] = false;
    }
    
    
    DFSHelper(g, start, visited, DFSTree);

    delete[] visited;

    return DFSTree;
}

int minDist(int* dist, bool* shortestPaths, int vertices)
{
    int min = INT_MAX;
    int index = -1;

    for (int i = 0; i < vertices; i++) {
        if (!shortestPaths[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    
    return index;
}


void relax(const Graph& graph, int u, int v, int* distances, int* prev)
{
    if (graph.hasEdge(u, v) && distances[u] != INT_MAX) 
    {
        int weight = graph.getWeight(u, v);
        if (distances[u] + weight < distances[v]) 
        {
            distances[v] = distances[u] + weight;
            prev[v] = u;
        }
    }
}

int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index = -1;

    for (size_t v = 0; v < vertices; v++)
    {
        if(mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

Graph dijkstra(const Graph& graph, int start)
{
    int vertices = graph.getVertices();
    int* distances = new int[vertices];
    bool* shortestPaths = new bool[vertices];
    int* prev = new int[vertices];
    Graph shortestPathTree(vertices);

    for (size_t i = 0; i < vertices; i++)
    {
        distances[i] = INT_MAX;
        shortestPaths[i] = false;
        prev[i] = -1;
    }
    
    distances[start] = 0;

    for (size_t i = 0; i < vertices-1; i++)
    {
        int u = minDist(distances, shortestPaths, vertices);
        if(u == -1)
            break;
        
        //cout << "u is: " + to_string(u) + "  vertice is: " + to_string(vertices) << endl;
        shortestPaths[u] = true;
        for (int v = 0; v < vertices; v++) 
        {
            relax(graph, u, v, distances, prev);
        }
    }

    for (size_t v = 0; v < vertices; v++)
    {
        if (v != start && prev[v] != -1) 
        {
            shortestPathTree.addEdge(prev[v], v, graph.getWeight(prev[v], v));
        }
    }

    delete[] distances;
    delete[] shortestPaths;
    delete[] prev;

    return shortestPathTree;
}

Graph primMST(const Graph& graph)
{
    int vertices = graph.getVertices();
    int* parent = new int[vertices];
    int* key = new int[vertices];
    bool* mstSet = new bool[vertices];

    for (size_t i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
        parent[0] = -1;
    }
    
    key[0] = 0;

    for (size_t i = 0; i < vertices - 1; i++)
    {
        int u = minKey(key, mstSet, vertices);
        if(u == -1)
            break;

        mstSet[u] = true;

        for (size_t v = 0; v < vertices; v++)
        {
            int currentWeight = graph.getWeight(u,v);
            if(graph.hasEdge(u,v) && mstSet[v] == false && currentWeight < key[v])
            {
                parent[v] = u;
                key[v] = currentWeight;
            }
        }   
    }

    Graph minSpanningTree(vertices);
    for (int v = 1; v < vertices; v++) // Start from 1 since 0 is the root.
    {
        if (parent[v] != -1)
        {
            minSpanningTree.addEdge(parent[v], v, graph.getWeight(parent[v], v));
        }
    }

    delete[] parent;
    delete[] key;
    delete[] mstSet;

    return minSpanningTree;
}

void swapEdges(Edge& a, Edge& b) 
{
    Edge temp = a;
    a = b;
    b = temp;
}

int partition(Edge arr[], int low, int high) 
{
    int pivot = arr[high].weight;
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (arr[j].weight < pivot) 
        {
            i++;
            swapEdges(arr[i], arr[j]);
        }
    }
    swapEdges(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Edge arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

Graph kruskalMST(const Graph& graph) 
{
    int vertices = graph.getVertices();
    
    int edgeCount = 0;
    const Vertex* const * adj = graph.getAdj();
    for (int i = 0; i < vertices; i++) 
    {
        const Vertex* curr = adj[i];
        while (curr != nullptr) 
        {
            if (i < curr->vertex) 
            {
                edgeCount++;
            }
            curr = curr->next;
        }
    }
    
    Edge* edges = new Edge[edgeCount];
    int index = 0;
    for (int i = 0; i < vertices; i++) 
    {
        const Vertex* curr = adj[i];
        while (curr != nullptr) 
        {
            if (i < curr->vertex) 
            {
                edges[index].src = i;
                edges[index].dest = curr->vertex;
                edges[index].weight = curr->data;
                index++;
            }
            curr = curr->next;
        }
    }
    
    quickSort(edges, 0, edgeCount - 1);
    
    UnionFind uf(vertices);
    
    Graph mstGraph(vertices);
    
    int iEdge = 0; 
    int e = 0;     
    while (e < vertices - 1 && iEdge < edgeCount) 
    {
        Edge nextEdge = edges[iEdge++];
        
        int x = uf.find(nextEdge.src);
        int y = uf.find(nextEdge.dest);
        
        if (x != y) {
            mstGraph.addEdge(nextEdge.src, nextEdge.dest, nextEdge.weight);
            uf.unionSets(x, y);
            e++;
        }
    }
    
    delete[] edges;
    
    return mstGraph;
}
