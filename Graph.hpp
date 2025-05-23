//shaked1mi@gmail.com

#pragma once
#include "units/DataStructures.hpp"

namespace graph
{

class Graph{
    private:
        int vertices;
        Vertex** adj;
    
    public:
        void addEdge(int source, int destination, int weight);
        void removeEdge(int source, int destination);
        void printGraph() const;
        int getVertices() const;
        //Vertex** getAdj() const;
        const Vertex* const * getAdj() const;
        bool hasEdge(int source, int destination) const;
        int getWeight(int source, int destination) const;
        Graph(int vertices);
        ~Graph();
    };

}