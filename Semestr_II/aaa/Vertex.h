#include <iostream>

class Vertex
{
private:
    int number{-1};
public:
    int weight{0};
    bool visited = false;
    std::string label{"EMPTY"};
    Vertex(int n) : number{n} {}
    int Number() const { return number; };

    friend bool operator==(const Vertex& v0, const Vertex& v1) { return v0.number == v1.number; }
    friend std::ostream& operator<<(std::ostream& ost, Vertex const& v)
    {
        ost << v.number;
        return ost;
    }
};