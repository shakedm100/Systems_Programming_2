#include "Graph.hpp"
#include <iostream>

using namespace std;

void Graph::addEdge(int source, int destination, int weight)
{
    Vertice* newVerticeSrc = new Vertice;
    newVerticeSrc->data = weight;
    newVerticeSrc->vertex = destination;
    newVerticeSrc->next = nullptr;

    if (adj[source] == nullptr) {
        adj[source] = newVerticeSrc;
    } else {
        Vertice* iterate = adj[source];
        while(iterate->next != nullptr) {
            iterate = iterate->next;
        }
        iterate->next = newVerticeSrc;
    }

    Vertice* newVerticeDest = new Vertice;
    newVerticeDest->data = weight;
    newVerticeDest->vertex = source;
    newVerticeDest->next = nullptr;

    if (adj[destination] == nullptr) {
        adj[destination] = newVerticeDest;
    } else {
        Vertice* iterate = adj[destination];
        while(iterate->next != nullptr) {
            iterate = iterate->next;
        }
        iterate->next = newVerticeDest;
    }
}

void Graph::removeEdge(int source, int destination)
{
    // Remove destination from source's list
    Vertice* current = adj[source];
    Vertice* prev = nullptr;
    while (current != nullptr) {
        if (current->vertex == destination) {
            if (prev == nullptr) 
            {
                // Edge is at the head
                adj[source] = current->next;
            } else 
                prev->next = current->next;
            delete current;
        }
        prev = current;
        current = current->next;
    }
    
    // Remove source from destination's list
    current = adj[destination];
    prev = nullptr;
    while (current != nullptr) {
        if (current->vertex == source) {
            if (prev == nullptr) {
                adj[destination] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
        prev = current;
        current = current->next;
    }
}

void Graph::printGraph()
{
    Vertice* current;
    
    for (int i = 0; i < vertices; i++)
    {
        current = adj[i];
        while(current != nullptr)
        {
            cout << "(" << i << "," << current->vertex << ")";
            current = current->next;
        }

        cout << "\n";
    }
}

int Graph::getVertices()
{
    return vertices;
}

Vertice**& Graph::getAdj()
{
    return adj;
}