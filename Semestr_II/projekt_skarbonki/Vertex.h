#include <iostream>

class Vertex {
private:
    int number;
public:
    int weight;
    std::string label;
    Vertex(int n) {
        number = n;
    }
    int Number() const {
        return number;
    }
};