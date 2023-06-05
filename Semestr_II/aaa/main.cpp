#include "GraphAsMatrix.h"

int main()
{
    int numberOfVaults;
    std::cout << "ilosc skarbonek: " << std::endl;
    std::cin >> numberOfVaults;
    GraphAsMatrix graph(numberOfVaults, false);
    std::cout << "Rozmieszczenie skarbonek:" << std::endl;
    int num;
    for(int i = 0; i < numberOfVaults; i++) {
        std::cin >> num;
        graph.AddEdge(i, num-1);
    }
    std::cout << " ";
    std::cout << "Ilosc skarbonek do rozbicia: " << graph.rozbijacz();
}