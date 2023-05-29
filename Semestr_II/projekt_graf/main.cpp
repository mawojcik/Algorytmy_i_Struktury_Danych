#include "GraphAsMatrix.h"
#include "Iterator.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>


int main() {
    int numberOfRows = 3;
    int numberOfColumns = 3;
    GraphAsMatrix graph(numberOfRows, numberOfColumns);
    graph.AddEdge(1, 4);
    graph.AddEdge(2, 5);
    graph.AddEdge(4, 1);
    graph.AddEdge(3, 6);
    graph.AddEdge(5, 8);
    graph.AddEdge(4, 7);
    graph.AddEdge(6, 9);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 6);
    graph.AddEdge(7, 8);
    graph.AddEdge(8, 9);
    graph.printLabyrinth();
}