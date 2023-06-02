#include <vector>
#include <iostream>
#include "Vertex.h"
#include "Edge.h"
#include "Iterator.h"
#include "CountingVisitor.h"

class GraphAsMatrix
{
    std::vector<Vertex *> vertices;
    std::vector<std::vector<Edge *> > adjacencyMatrix;
    int numberOfVertices;
    int numberOfRows;
    int numberOfColumns;
    int numberOfEdges = 0;
public:
    GraphAsMatrix(int r, int c)
    {
        numberOfVertices = r * c+1;
        numberOfRows = r;
        numberOfColumns = c;
        for (int i = 0; i < numberOfVertices; i++)
        {
            Vertex *v = new Vertex(i);
            vertices.push_back(v);
        }
        createAdjacencyMatrix(numberOfVertices);
    }

    GraphAsMatrix CopyGraph(GraphAsMatrix& graph)
    {
        numberOfRows = graph.numberOfRows;
        numberOfColumns = graph.numberOfColumns;

        GraphAsMatrix newGraph(numberOfRows, numberOfColumns);

        for (int i = 0; i < graph.vertices.size(); i++)
        {
            for (int j = 0; j < graph.vertices.size(); j++)
            {
                if (graph.IsEdge(i, j))
                    newGraph.AddEdge(i, j);
            }
        }


        return newGraph;
    }


    void printLabyrinth() {
        int number = 1;
        int counter = 1;
        for (int i = 0; i < numberOfRows; i ++) {
            for (int j = 0; j < numberOfColumns; j++) {
                if (number < 10) {
                    std::cout <<"  " << number << "  ";
                } else {
                    std::cout << " " << number << "  ";
                }
                if (j < numberOfColumns - 1) {
                    if(IsEdge(j + counter, j + counter+1)) {
                        std::cout << " | ";
                    } else {
                        std::cout << "   ";
                    }
                }
                number++;
            }

            std::cout << std::endl;
            for (int k = 0; k < numberOfColumns; k++) {
                if (IsEdge(counter + k, counter + k + numberOfColumns)) {
                    std::cout << " ------";
                } else {
                    std::cout << "       ";
                }
            }
            counter += numberOfColumns;
            std::cout << std::endl;
        }
    }
    int randomNumber(int from, int to) {
        srand((unsigned) time(nullptr));
        return from + (rand() % (to - from + 1));
    }

    void chooseRandomEdges() {
        std::vector<bool> visited(vertices.size(), false);
//        while(!IsConnected()) {
        int randomVertex = randomNumber(1, numberOfVertices-1);
        int randomEdge = randomNumber(1, 4);
//        Vertex *v = this->SelectVertex(randomVertex);
//        std::cout << "vertex: " << randomVertex << std::endl;
//        std::cout << "edge: " << randomEdge << std::endl;
        int mateVertex = 0;
        if (randomEdge == 1) {
            mateVertex = randomVertex - numberOfColumns;
        } else if (randomEdge == 2) {
            mateVertex = randomVertex - 1;
        } else if (randomEdge == 3) {
            mateVertex = randomVertex + 1;
        } else {
            mateVertex = randomVertex + numberOfColumns;
        }
        GraphAsMatrix tempGraph = CopyGraph(*this);
        tempGraph.AddEdge(randomVertex, mateVertex);
//        std::cout<< "edge: " << this->IsEdge(2, 6);
//        tempGraph.printLabyrinth();
//        AddEdge(randomVertex, mateVertex);
        // check if we have a cycle
        // if true delete previous vertex and continue
        // if false continue
        //OR
        //create temporary graph same as current graph, add edge to it
        //check if we have a cycle
        //if true: contine and delete temporary graph
        //if false: AddEdge to final graph, delete temporary grap continue
//        }

        //choose random vertex, then choose random edge coming out of this vertex
        // do this untill grap is not connected
    }
    bool IsCyclic(Vertex *v) {
        std::vector<bool> visited(vertices.size(), false);
        int parent = -1;
//        for (int i = 0; i < vertices.size(); i++) {
            CheckingCycle(v, visited, parent);
//        }
    }

    bool CheckingCycle(Vertex *v, std::vector<bool> &visited, int parent) {
        visited[v->Number()] = true;
        Iterator<Edge> &emIter = this->EmanatingEdgesIter(v->Number());
        for (emIter; !emIter.IsDone(); ++emIter)
        {
            Edge e = *emIter;
//            std::cout << e.V0()->Number() << " --- " << e.V1()->Number() << std::endl;
            std::cout << e.V0()->Number();
            if (!visited[e.V0()->Number()]) {
                parent = v->Number();
                CheckingCycle(e.V0(), visited, parent);
            }
        }
    }


    class AllVerticesIter : public Iterator<Vertex>
    {
        GraphAsMatrix &owner;
        int current;

    public:


        AllVerticesIter(GraphAsMatrix &owner) : owner(owner)
        {
            current = 0;
            this->owner = owner;
        };
        bool IsDone()
        {
            if (current >= owner.vertices.size())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Vertex &operator*() { return *owner.vertices[current]; }
        void operator++() { current++; }
    };

    class AllEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            int width = owner.adjacencyMatrix.size();
            if (!this->IsDone())
            {
                col++;
                if (col >= width)
                {
                    row++;
                    col = 0;
                }
            }
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                col++;
                if (col >= width)
                {
                    row++;
                    col = 0;
                }
            }
        }
        AllEdgesIter(GraphAsMatrix &owner) : owner(owner)
        {
            this->owner = owner;
            row = 0;
            col = -1;
        }
        bool IsDone()
        {
            int width = owner.adjacencyMatrix.size();
            if (col >= width - 1 && row >= owner.adjacencyMatrix[width - 1].size() - 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (col < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

    class EmanEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            col++;
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                col++;
            }
        }
        EmanEdgesIter(GraphAsMatrix &owner, int v) : owner(owner)
        {
            row = v;
            col = -1;
            this->owner = owner;
//            next();
        }
        bool IsDone()
        {
            int value = owner.adjacencyMatrix.size();
            if (col >= (value - 1))
                return true;
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (col < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

    class InciEdgesIter : public Iterator<Edge>
    {
        GraphAsMatrix &owner;
        int row;
        int col;

    public:
        void next()
        {
            row++;
            while (owner.adjacencyMatrix[col][row] == NULL && !this->IsDone())
            {
                row++;
            }
        }
        InciEdgesIter(GraphAsMatrix &owner, int v) : owner(owner)
        {
            row = -1;
            col = v;
            this->owner = owner;
        }
        bool IsDone()
        {
            int value = owner.adjacencyMatrix[0].size();
            if (row >= (value - 1))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        Edge &operator*()
        {
            if (row < 0)
                next();
            return *owner.adjacencyMatrix[col][row];
        }
        void operator++() { next(); }
    };

public:
    bool IsConnected()
    {
            Vertex *v = vertices[0];
            CountingVisitor visitor;
            std::vector<bool> visited(vertices.size(), false);
            DFS_visitor(&visitor, v, visited);
            return (visitor.GetNumber() == vertices.size());
    }

    void DFS(Vertex *v)
    {
        CountingVisitor visitor;
        std::vector<bool> visited(vertices.size(), false);
        DFS_visitor(&visitor, v, visited);
        AllVerticesIter iter(*this);
        while (!iter.IsDone())
        {
            Vertex *x = &(*iter);
            if (!iter.IsDone())
            {
                if (visited[x->Number()] == false)
                {
                    DFS_visitor(&visitor, &(*iter), visited);
                }
            }
            ++iter;
        }
        std::cout << "\nNumber of vertices counted: " << visitor.GetNumber() << std::endl;
    }

    void DFS_visitor(CountingVisitor *visitor, Vertex *v, std::vector<bool> &visited)
    {
        visitor->Visit(*v);
        visited[v->Number()] = true;
//        std::cout << v->Number() << " ";
        EmanEdgesIter emanIter(*this, v->Number());
        while (!emanIter.IsDone())
        {
            ++emanIter;
            if (!emanIter.IsDone())
            {
                Edge vEdge = *emanIter;
                Vertex *u = vEdge.Mate(v);
                if (visited[u->Number()] == false)
                    DFS_visitor(visitor, u, visited);
            }
        }
    }

    void createAdjacencyMatrix(int n)
    {
        std::vector<Edge *> column(n, nullptr);
        for (int i = 0; i < n; i++)
        {
            adjacencyMatrix.push_back(column);
        }
    }

    int NumberOfVertices()
    {
        return numberOfVertices;
    }

    int NumberOfEdges()
    {
        return numberOfEdges;
    }

    bool IsEdge(int u, int v)
    {
        bool ifEdgeExists = false;
        if (u && v > numberOfVertices)
        {
        }
        else if (adjacencyMatrix[u][v] != NULL)
        {
            ifEdgeExists = true;
        }
        return ifEdgeExists;
    }

    void MakeNull()
    {
        for (int i = 0; i < numberOfVertices; i++)
        {
            for (int j = 0; j < numberOfVertices; j++)
                adjacencyMatrix[i][j] = NULL;
        }
        numberOfEdges = 0;
    }

    void AddEdge(int u, int v)
    {
        if (!IsEdge(u, v) && ((u == (v - numberOfColumns)) || v == (u - numberOfColumns) ||  u == v-1 || v==u-1) && ((u > 0 && v > 0) && (u < numberOfVertices && v < numberOfVertices)))
        {
            Edge *edge = new Edge(vertices[u], vertices[v]);
            adjacencyMatrix[u][v] = edge;
            numberOfEdges++;
            adjacencyMatrix[v][u] = edge;
        }
    }

    Edge *SelectEdge(int u, int v)
    {
        if (IsEdge(u, v))
            return adjacencyMatrix[u][v];
    }

    Vertex *SelectVertex(int v)
    {
        return vertices[v];
    }

    Iterator<Vertex> &VerticesIter()
    {
        return *new AllVerticesIter(*this);
    }
    Iterator<Edge> &EdgesIter()
    {
        return *new AllEdgesIter(*this);
    }
    Iterator<Edge> &EmanatingEdgesIter(int v)
    {
        return *new EmanEdgesIter(*this, v);
    }
    Iterator<Edge> &IncidentEdgesIter(int v)
    {
        return *new InciEdgesIter(*this, v);
    }
};