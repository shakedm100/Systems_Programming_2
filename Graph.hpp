#pragma once
#include "DataStructures.hpp"


class Graph{
    private:
        const int vertices;
        Vertice** adj;
    
    public:
        void addEdge(int source, int destination, int weight);
        void removeEdge(int source, int destination);
        void printGraph();
        int getVertices();
        Vertice**& getAdj();

        Graph(int vertices) : vertices(vertices)
        {   
            adj = new Vertice*[vertices];

            for (int i = 0; i < vertices; i++)
            {
                adj[i] = nullptr;
            }
        }

        ~Graph()
        {
            for (int i = 0; i < vertices; i++)
            {
                Vertice* temp = adj[i];
                while (temp != nullptr)
                {
                    Vertice* next = temp->next;
                    delete temp;
                    temp = next;
                }
            }

            delete[] adj;
        }
    
    };