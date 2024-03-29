#include <vector>
#include "Iterator.h"
#include "Vertex.h"
#include "Edge.h"
#include <iostream>

class GraphAsMatrix
{
public:
    GraphAsMatrix(int n, bool directed)
    {
        numberOfVertices = n;
        isDirected = directed;
        for(int i = 0; i<n; i++) {
            vertices.push_back(new Vertex(i));
            adjacencyMatrix.push_back(std::vector<Edge*>(n, nullptr));
        }
    }
private:
    std::vector<Vertex*> vertices;
    std::vector<std::vector<Edge*> > adjacencyMatrix;
    bool isDirected;
    int numberOfVertices;
    int numberOfEdges = 0;

    class AllVerticesIter: public Iterator<Vertex>
    {
    private:
        GraphAsMatrix& owner;
        int current = 0;
    public:
        AllVerticesIter(GraphAsMatrix& owner): owner(owner) {};
        bool IsDone() const { return current >= owner.numberOfVertices; }
        Vertex& operator*() { return *(owner.vertices[current]); }
        void operator++() { ++current; }
    };
    class AllEdgesIter: public Iterator<Edge>
    {
    private:
        GraphAsMatrix& owner;
        int row, col;
        bool end = false;
    public:
        void next()
        {
            for(; row < owner.numberOfVertices; row++) {
                for(++col; col < owner.numberOfVertices; col++) {
                    if(owner.adjacencyMatrix[row][col] != nullptr)
                        return;
                }
                col = -1;
            }
            end = true;
        }
        AllEdgesIter(GraphAsMatrix& owner): owner(owner) {
            row = 0;
            col = 0;
        next();
        }
        bool IsDone() const { return end; }
        Edge& operator*() { return *owner.SelectEdge(row,col); }
        void operator++(){ next(); }
    };
    class EmanEdgesIter: public Iterator<Edge>
    {
    private:
        GraphAsMatrix& owner;
        int row;
        int col;
        bool end = false;
    public:
        void next()
        {
            for(++col; col < owner.numberOfVertices; col++) {
                if(owner.adjacencyMatrix[row][col] != nullptr)
                    return;
            }
            end = true;
        }
        EmanEdgesIter(GraphAsMatrix& owner, int u): owner(owner) {
            row = u;
            col = -1;
            next();
        }
        bool IsDone() const { return end; }
        Edge& operator*() { return *owner.SelectEdge(row,col); }
        void operator++() { next(); }
    };
    class InciEdgesIter: public Iterator<Edge>
    {
    private:
        GraphAsMatrix& owner;
        int row;
        int col;
        bool end = false;
    public:
        void next()
        {
            for(++row; row < owner.numberOfVertices; row++) {
                if(owner.adjacencyMatrix[row][col] != nullptr)
                    return;
            }
            end = true;
        }
        InciEdgesIter(GraphAsMatrix& owner, int v): owner(owner) {
            row = -1;
            col = v;
            next();
        }
        bool IsDone() const { return end; }
        Edge& operator*() { return *owner.SelectEdge(row,col); }
        void operator++(){ next(); }
    };

public:
    bool IsDirected() { return isDirected; }
    int NumberOfVertices() { return numberOfVertices; }
    int NumberOfEdges() { return numberOfEdges; }
    bool IsEdge(int u, int v) { return adjacencyMatrix[u][v] != nullptr; }
    void MakeNull()
    {
        for(int i = 0; i<numberOfVertices; i++) {
            for(int j = 0; j<numberOfVertices; j++) {
                if(adjacencyMatrix[i][j]) delete adjacencyMatrix[i][j];
            }
        }
        numberOfEdges = 0;
    }
    void AddEdge(int u, int v)
    {
        if(!adjacencyMatrix[u][v]) {
            adjacencyMatrix[u][v] = new Edge(vertices[u], vertices[v]);
            numberOfEdges++;
        }
        if(!isDirected && !adjacencyMatrix[v][u]) {
            adjacencyMatrix[v][u] = new Edge(vertices[v], vertices[u]);
        }
    }

    Edge* SelectEdge (int u, int v) { return adjacencyMatrix[u][v]; }
    Vertex* SelectVertex(int v) { return vertices[v]; }

    Iterator<Vertex>& VerticesIter() { return *(new AllVerticesIter(*this)); }
    Iterator<Edge>& EdgesIter() { return *(new AllEdgesIter(*this)); }
    Iterator<Edge>& EmanatingEdgesIter(int u) { return *(new EmanEdgesIter(*this, u)); }
    Iterator<Edge>& IncidentEdgesIter(int v) { return *(new InciEdgesIter(*this, v)); }

    int rozbijacz()
    {
        int broken = 0;
        std::vector<bool> visited(this->numberOfVertices, false);
        for(int i = 0; i<numberOfVertices; i++) {
            if(!visited[i]) {
                DFS1(vertices[i], visited);
                broken++;
            }
        }
        return broken;
    }

    void DFS1(Vertex *v, std::vector<bool> &visited)
    {
        visited[v->Number()] = true;
        auto &it = EmanatingEdgesIter(v->Number());
        while(!it.IsDone()) {
            if(!visited[(*it).V1()->Number()])
                DFS1((*it).V1(), visited);
            ++it;
        }
    }
};
