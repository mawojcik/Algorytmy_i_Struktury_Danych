#include "GraphAsMatrix.h"

int main()
{
    int n;
    std::cout << "ilosc skarbonek: " << std::endl;
    std::cin >> n;
    GraphAsMatrix graph(n, false);
    std::cout << "Rozmieszczenie skarbonek:" << std::endl;
    int num;
    for(int i = 0; i<n; i++) {
        std::cin >> num;
        graph.AddEdge(i, num-1);
    }
    std::cout << " ";
    graph.piggy_banks();
}