#include "GraphAsMatrix.h"
#include "Iterator.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>


int main() {
    int numberOfRows = 4;
    int numberOfColumns = 4;
    GraphAsMatrix graph(numberOfRows, numberOfColumns);
    graph.AddEdge(2, 3);
    graph.AddEdge(2, 6);
    graph.AddEdge(6, 7);
    graph.AddEdge(3, 7);
    Vertex *v = graph.SelectVertex(3);
    int startingNumber = v->Number();
//    graph.AddEdge(5, 8);
//    graph.AddEdge(4, 7);
//    graph.AddEdge(6, 9);
//    graph.AddEdge(1, 2);
//    graph.AddEdge(2, 3);
//    graph.AddEdge(1, 5);
//    graph.AddEdge(10, 14);
//    graph.AddEdge(4, 5);
//    graph.AddEdge(5, 6);
//    graph.AddEdge(7, 8);
//    graph.AddEdge(8, 9);
//    graph.AddEdge(7, 10);
//    graph.AddEdge(11, 14);
//    graph.AddEdge(13, 14);
//    graph.AddEdge(18, 19);
    graph.chooseRandomEdges();
    graph.printLabyrinth();
    graph.IsCyclic(v);
}