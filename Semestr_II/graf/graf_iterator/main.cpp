#include "GraphAsMatrix.h"
#include "Iterator.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>

void EdgeTest(GraphAsMatrix graph, int u, int v)
{

    std::cout << "Test for edge (" << u << "," << v << ")" << std::endl;

    if(!graph.IsEdge(u, v)) {
        std::cout << "There is no such edge!" << std::endl;
        return;
    }
    Edge *e = graph.SelectEdge(u, v);

    // Wypisz V0 dla e
    // Wypisz V1 dla e
    std::cout << "V0 of edge: " << e->V0()->Number() << std::endl;
    std::cout << "V1 of edge: " << e->V1()->Number() << std::endl;

    // Wypisz sąsiada(V0) dla e // test metody Mate
    // Wypisz sąsiada(V1) dla e // test metody Mate
    std::cout << "Neighbor of V0 for edge: " << e->Mate(e->V0())->Number() << std::endl;
    std::cout << "Neighbor of V1 for edge: " << e->Mate(e->V1())->Number() << std::endl;

    // Nadaj krawędzi e wagę V0 + V1
    // Wypisz wagę krawędzi e
    e->weight = e->V0()->Number() + e->V1()->Number();
    std::cout << "Weight of edge: " << e->weight << std::endl
              << std::endl;
}

void zad_1_test(bool IsDirected)
{
    if (IsDirected)
        std::cout << "\nTest for directed graph" << std::endl
                  << std::endl;
    else
        std::cout << "\n\n\n\n\n\n\n\n\n\nTest for undirected graph" << std::endl
                  << std::endl;

    // Utwórz graf złożony z 10 wierzchołków
    GraphAsMatrix graph(10, IsDirected);

    // Wypisz, ile jest wierzchołków
    std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;

    // Wypisz, ile jest krawędzi
    std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl;

    Vertex *v = graph.SelectVertex(2);

    // Wypisz unikalny numer v
    std::cout << "V number: " << v->Number() << std::endl;

    // Nadaj v wagę unikalnyNumer*uniklanyNumer
    // Wypisz wagę v
    v->weight = v->Number() * v->Number();
    std::cout << "V weight: " << v->weight << std::endl;

    graph.AddEdge(1, 2);
    graph.AddEdge(1, 2);
    graph.AddEdge(2, 3);
    graph.AddEdge(3, 4);
    graph.AddEdge(9, 9);

    // Wypisz, ile jest wierzchołków
    std::cout << "Number of vertices: " << graph.NumberOfVertices() << std::endl;

    // Wypisz, ile jest krawędzi
    std::cout << "Number of edges: " << graph.NumberOfEdges() << std::endl;

    // Wypisz, czy istnieje krawędź (1,1)
    // Wypisz, czy istnieje krawędź (1,2)
    // Wypisz, czy istnieje krawędź (2,1)
    std::cout << "If edge (1,1) exists: " << std::boolalpha << graph.IsEdge(1, 1) << std::endl;
    std::cout << "If edge (1,2) exists: " << std::boolalpha << graph.IsEdge(1, 2) << std::endl;
    std::cout << "If edge (2,1) exists: " << std::boolalpha << graph.IsEdge(2, 1) << std::endl
              << std::endl;

    EdgeTest(graph, 1, 2);
    EdgeTest(graph, 2, 3);
    EdgeTest(graph, 3, 4);
    EdgeTest(graph, 9, 9);



    std::cout << "\n\n\n\n\n\n\n\n"
                 "Iterator:"
                 "\n\n";
    // Wypisz wszystkie wierzchołki korzystając z iteratora po wierzchołkach (ich unikalny numer i wagę)
    std::cout<<"Vertex iterator test: "<<std::endl;
    Iterator<Vertex> &vIter = graph.VerticesIter();
    for (vIter; !vIter.IsDone(); ++vIter)
    {
        Vertex e = *vIter;
        std::cout << "Vertex number: " << e.Number() << " Vertex weight: " << e.weight << std::endl;
    }
    std::cout << std::endl;

    graph.AddEdge(3, 5);
    graph.AddEdge(8, 3);
    graph.AddEdge(5, 2);

    // Wypisz wszystkie krawędzie korzystając z odpowiedniego iteratora
    // to znaczy, wypisz pierwszy i drugi wierzchołek krawędzi – v0 i v1)
    std::cout<<"Edge iterator test: "<<std::endl;
    Iterator<Edge> &eIter = graph.EdgesIter();
    for (eIter; !eIter.IsDone(); ++eIter)
    {
        Edge e = *eIter;
        std::cout << "Edge V0: " << e.V0()->Number() << " Edge V1: " << e.V1()->Number() << std::endl;
    }
    std::cout << std::endl;

    // Wypisz wszystkie krawędzie wychodzące z wierzchołka o numerze 3
    // korzystając z odpowiedniego iteratora (to znaczy, wypisz pierwszy i drugi wierzchołek krawędzi – v0 i v1)
    std::cout<<"EmanIterator test: "<<std::endl;
    Iterator<Edge> &emIter = graph.EmanatingEdgesIter(3);
    for (emIter; !emIter.IsDone(); ++emIter)
    {
        Edge e = *emIter;
        std::cout << "Edge V0: " << e.V0()->Number() << " Edge V1: " << e.V1()->Number() << std::endl;
    }
    std::cout << std::endl;

    // Wypisz wszystkie krawędzie dochodzące do wierzchołka o numerze 2, korzystając z odpowiedniego iteratora
    //( to znaczy, wypisz pierwszy i drugi wierzchołek krawędzi – v0 i v1)
    std::cout<<"InciIterator test:"<<std::endl;
    Iterator<Edge> &inIter = graph.IncidentEdgesIter(2);
    for (inIter; !inIter.IsDone(); ++inIter)
    {
        Edge e = *inIter;
        std::cout << "Edge V0: " << e.V0()->Number() << " Edge V1: " << e.V1()->Number() << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    zad_1_test(true);
    zad_1_test(false);
}