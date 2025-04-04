/*
shaked1mi@gmail.com
Shaked Michael
318772191
*/

#pragma once
#include "Graph.hpp"

Graph BFS(const Graph& graph, const Vertex start);
Graph DFS(const Graph& g, int start);
Graph dijkstra(const Graph& graph, int start);
Graph primMST(const Graph& graph);
Graph kruskalMST(const Graph& graph);