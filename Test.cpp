//shaked1mi@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Algorithms.hpp"

using namespace graph;

//Remark: DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN implements main automatically for the test functions


/*
This struct is to create a single Graph that all the test cases will use
*/
struct GraphFixture {
    Graph g;

    GraphFixture() : g(5) 
    {
        g.addEdge(0, 1, 2);
        g.addEdge(0, 2, 4);
        g.addEdge(1, 2, 1);
        g.addEdge(1, 3, 7);
        g.addEdge(2, 4, 3);
        g.addEdge(3, 4, 1);
    }
};


TEST_CASE_FIXTURE(GraphFixture, "Graph: basic operations") {
    CHECK(g.getVertices() == 5);
    
    CHECK(g.hasEdge(0, 1) == true);
    CHECK(g.getWeight(0, 1) == 2);
    
    CHECK(g.hasEdge(0, 2) == true);
    CHECK(g.getWeight(0, 2) == 4);

    CHECK(g.hasEdge(2, 0) == true);
    CHECK(g.getWeight(2, 0) == 4);

    CHECK(g.hasEdge(3,2) == false);
    CHECK(g.hasEdge(2,3) == false);
    CHECK(g.hasEdge(1,4) == false);
    CHECK(g.hasEdge(4,1) == false);
    CHECK(g.hasEdge(1,1) == false);

    CHECK_THROWS(g.addEdge(-1,1,5));
    CHECK_THROWS(g.addEdge(1,-1,5));
    CHECK_THROWS(g.addEdge(1,1,-5));
    CHECK_THROWS(g.addEdge(0,1,5)); //Exists
    
    CHECK_THROWS(g.removeEdge(-1,1));
    CHECK_THROWS(g.removeEdge(1,-1));
    CHECK_THROWS(g.removeEdge(0,3));
}

TEST_CASE_FIXTURE(GraphFixture, "BFS")
{
    const Vertex* first = g.getAdj()[0];
    Graph BFSGraph = BFS(g, (*first));

    CHECK(BFSGraph.hasEdge(0, 1) == true);
    CHECK(BFSGraph.hasEdge(1, 0) == true);
    CHECK(BFSGraph.getWeight(0, 1) == 2);

    CHECK(BFSGraph.hasEdge(1, 3) == true);
    CHECK(BFSGraph.hasEdge(3, 1) == true);
    CHECK(BFSGraph.getWeight(1, 3) == 7);

    CHECK(BFSGraph.hasEdge(3, 4) == false);
    CHECK(BFSGraph.hasEdge(4, 3) == false);
}

DOCTEST_TEST_CASE_FIXTURE(GraphFixture, "DFS")
{
    Graph DFSGraph = DFS(g, 0);

    CHECK(DFSGraph.hasEdge(0, 1) == true);
    CHECK(DFSGraph.hasEdge(1, 0) == true);
    CHECK(DFSGraph.getWeight(0, 1) == 2);

    CHECK(DFSGraph.hasEdge(1, 2) == true);
    CHECK(DFSGraph.hasEdge(2, 1) == true);
    CHECK(DFSGraph.getWeight(1, 2) == 1);

    CHECK(DFSGraph.hasEdge(2, 4) == true);
    CHECK(DFSGraph.hasEdge(4, 2) == true);
    CHECK(DFSGraph.getWeight(2, 4) == 3);

    CHECK(DFSGraph.hasEdge(3, 4) == true);
    CHECK(DFSGraph.hasEdge(4, 3) == true);
    CHECK(DFSGraph.getWeight(3, 4) == 1);

    CHECK(DFSGraph.hasEdge(0, 2) == false);
    CHECK(DFSGraph.hasEdge(2, 0) == false);

    CHECK(DFSGraph.hasEdge(1, 3) == false);
    CHECK(DFSGraph.hasEdge(3, 1) == false);
}


TEST_CASE_FIXTURE(GraphFixture, "Dijkstra")
{
    Graph shortestPaths = dijkstra(g, 0);

    CHECK(shortestPaths.hasEdge(0, 1) == true);
    CHECK(shortestPaths.hasEdge(1, 0) == true);
    CHECK(shortestPaths.getWeight(0, 1) == 2);

    CHECK(shortestPaths.hasEdge(1, 3) == false);
    CHECK(shortestPaths.hasEdge(3, 1) == false);

    CHECK(shortestPaths.hasEdge(3, 4) == true);
    CHECK(shortestPaths.hasEdge(4, 3) == true);
    CHECK(shortestPaths.getWeight(4, 3) == 1);
}

TEST_CASE_FIXTURE(GraphFixture, "Prim")
{
    Graph prim = primMST(g);

    CHECK(prim.hasEdge(0, 1) == true);
    CHECK(prim.hasEdge(1, 0) == true);
    CHECK(prim.getWeight(0, 1) == 2);

    CHECK(prim.hasEdge(1, 2) == true);
    CHECK(prim.hasEdge(2, 1) == true);
    CHECK(prim.getWeight(1, 2) == 1);

    CHECK(prim.hasEdge(2, 4) == true);
    CHECK(prim.hasEdge(4, 2) == true);
    CHECK(prim.getWeight(2, 4) == 3);

    CHECK(prim.hasEdge(3, 4) == true);
    CHECK(prim.hasEdge(4, 3) == true);
    CHECK(prim.getWeight(3, 4) == 1);

    CHECK(prim.hasEdge(0, 2) == false);
    CHECK(prim.hasEdge(2, 0) == false);

    CHECK(prim.hasEdge(1, 3) == false);
    CHECK(prim.hasEdge(3, 1) == false);
}

TEST_CASE_FIXTURE(GraphFixture, "Kruskal")
{
    Graph kruskal = kruskalMST(g);

    CHECK(kruskal.hasEdge(0, 1) == true);
    CHECK(kruskal.hasEdge(1, 0) == true);
    CHECK(kruskal.getWeight(0, 1) == 2);

    CHECK(kruskal.hasEdge(1, 2) == true);
    CHECK(kruskal.hasEdge(2, 1) == true);
    CHECK(kruskal.getWeight(1, 2) == 1);

    CHECK(kruskal.hasEdge(2, 4) == true);
    CHECK(kruskal.hasEdge(4, 2) == true);
    CHECK(kruskal.getWeight(2, 4) == 3);

    CHECK(kruskal.hasEdge(3, 4) == true);
    CHECK(kruskal.hasEdge(4, 3) == true);
    CHECK(kruskal.getWeight(3, 4) == 1);

    CHECK(kruskal.hasEdge(0, 2) == false);
    CHECK(kruskal.hasEdge(2, 0) == false);

    CHECK(kruskal.hasEdge(1, 3) == false);
    CHECK(kruskal.hasEdge(3, 1) == false);
}
