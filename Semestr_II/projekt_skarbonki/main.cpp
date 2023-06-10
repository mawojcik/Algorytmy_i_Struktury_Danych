#include "GraphAsMatrix.h"

int main()
{
    int numberOfVaults;
    std::cout << "ilosc skarbonek: " << std::endl;
    std::cin >> numberOfVaults;
    GraphAsMatrix graph(numberOfVaults, false);
    std::cout << "Rozmieszczenie skarbonek:" << std::endl;
    int vaultNumber;
    for(int i = 0; i < numberOfVaults; i++) {
        std::cin >> vaultNumber;
        graph.AddEdge(i, vaultNumber-1);
    }
    std::cout << "Ilosc skarbonek do rozbicia: " << graph.rozbijacz();
}