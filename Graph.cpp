#include "Graph.hpp"
#include <iostream>

using namespace std;

Graph::Graph(int vertices) : vertices(vertices)
{   
    adj = new Vertex*[vertices];

    for (int i = 0; i < vertices; i++)
    {
        adj[i] = nullptr;
    }
}

Graph::~Graph()
{
    for (int i = 0; i < vertices; i++)
    {
        Vertex* temp = adj[i];
        while (temp != nullptr)
        {
            Vertex* next = temp->next;
            delete temp;
            temp = next;
        }
    }

    delete[] adj;
}

void Graph::addEdge(int source, int destination, int weight)
{
    if(hasEdge(source, destination))
        return;

    Vertex* newVerticeSrc = new Vertex;
    newVerticeSrc->data = weight;
    newVerticeSrc->vertex = destination;
    newVerticeSrc->next = nullptr;

    if (adj[source] == nullptr) 
        adj[source] = newVerticeSrc;
    else
     {
        Vertex* iterate = adj[source];
        while(iterate->next != nullptr) 
        {
            iterate = iterate->next;
        }

        iterate->next = newVerticeSrc;
    }

    Vertex* newVerticeDest = new Vertex;
    newVerticeDest->data = weight;
    newVerticeDest->vertex = source;
    newVerticeDest->next = nullptr;

    if (adj[destination] == nullptr)
        adj[destination] = newVerticeDest;
    else 
    {
        Vertex* iterate = adj[destination];
        while(iterate->next != nullptr) 
        {
            iterate = iterate->next;
        }
        
        iterate->next = newVerticeDest;
    }
}

void Graph::removeEdge(int source, int destination)
{
    if(!hasEdge(source, destination))
        return;

    // Remove destination from source's list
    Vertex* current = adj[source];
    Vertex* prev = nullptr;
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

void Graph::printGraph() const
{
    Vertex* current;
    
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

int Graph::getVertices() const
{
    return vertices;
}

/*Vertex** Graph::getAdj() const
{
    return adj;
}*/

const Vertex* const * Graph::getAdj() const
{
    return adj;
}

bool Graph::hasEdge(int source, int destination) const
{
    Vertex* current = adj[source];

    while (current != nullptr)
    {
        if (current->vertex == destination)
        {
            //cout << "The edge (" + to_string(source) + "," + to_string(destination) + ") exists" << endl;
            return true;
        }
        current = current->next;
    }

    //cout << "The edge (" + to_string(source) + "," + to_string(destination) + ") doesn't exist" << endl;
    return false;
}


int Graph::getWeight(int source, int destination) const
{
    Vertex* current = adj[source];

    while (current != nullptr)
    {
        if (current->vertex == destination)
        {
            //cout << "found weight for (" + to_string(source) + "," + to_string(destination) + ") with value: " + to_string(current->data) << endl;
            return current->data;
        }

        current = current->next;
    }
    
    //cout << "didn't find weight for (" + to_string(source) + "," + to_string(destination) + ")" << endl;
    return -1;
}
