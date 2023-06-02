#include "Visitor.h"

class CountingVisitor : Visitor<Vertex>
{
private:
    int ctr = 0;
public:
    void Visit(Vertex& element) { ctr++; }
    bool IsDone() { return false; }
    int counter() { return ctr; }
    void reset() { ctr = 0; }
};