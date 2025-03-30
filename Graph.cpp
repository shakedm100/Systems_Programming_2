/*
shaked1mi@gmail.com
Shaked Michael
318772191
*/

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

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

/**
 * @brief Adds an edge to an undirected graph
 * @param source - The starting vertex
 * @param destination - The ending vertex
 * @param weight - The weight of the edge
 */
void Graph::addEdge(int source, int destination, int weight)
{
    if(weight < 0)
        throw invalid_argument("Edge cannot be negative!");
    if(source < 0 || source >= vertices)
        throw invalid_argument("Invalid argument for source");
    if(destination < 0 || destination >= vertices)
        throw invalid_argument("Invalid argument for destination");
    if(hasEdge(source, destination))
        throw invalid_argument("Edge already exists!");

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

/**
 * @brief Removes an edge from an undirected graph
 * @param source - The starting vertex
 * @param destination - The ending vertex
 */
void Graph::removeEdge(int source, int destination)
{
    if(source < 0 || source >= vertices)
        throw invalid_argument("Invalid argument for source");
    if(destination < 0 || destination >= vertices)
        throw invalid_argument("Invalid argument for destination");
    if(!hasEdge(source, destination))
        throw invalid_argument("Edge doesn't exists!");

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

/**
 * @brief Prints the graph
 */
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


const Vertex* const * Graph::getAdj() const
{
    return adj;
}

/**
 * @brief Checks if a given edge exists in the graph
 * @param source - The starting vertex
 * @param destination - The ending vertex
 * @return true if the edge exists, false otherwise
 */
bool Graph::hasEdge(int source, int destination) const
{
    if(source < 0 || source >= vertices)
        throw invalid_argument("Invalid argument for source");
    if(destination < 0 || destination >= vertices)
        throw invalid_argument("Invalid argument for destination");

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

/**
 * @brief Checks a given edge's weight
 * @param source - The starting vertex
 * @param destination - The ending vertex
 * @return returns the weight if the edge exists, -1 otherwise
 */
int Graph::getWeight(int source, int destination) const
{
    if(source < 0 || source >= vertices)
        throw invalid_argument("Invalid argument for source");
    if(destination < 0 || destination >= vertices)
        throw invalid_argument("Invalid argument for destination");

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
