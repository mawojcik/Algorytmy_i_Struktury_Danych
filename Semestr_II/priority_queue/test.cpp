#include "BinaryHeap.h"

void test(BinaryHeap<int> heap){
    std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
    heap.Enqueue(5);
    std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(6);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(8);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(3);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(9);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(2);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    heap.Enqueue(1);
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    std::cout << "Minimum dequeued" << std::endl;
    heap.DequeueMin();
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    std::cout << "Minimum dequeued" << std::endl;
    heap.DequeueMin();
    std::cout <<"on heap: ";
    heap.Print();
    std::cout <<"Minimum: "<< heap.FindMin() << std::endl;
    std::cout << "Makenull" << std::endl;
    heap.MakeNull();
    std::cout <<"IsEmpty: "<< heap.IsEmpty() << std::endl;
}

int main(){
    BinaryHeap<int> heap(10);
    test(heap);
    std::cout<<std::endl;
}