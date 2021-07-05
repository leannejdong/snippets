
#include<iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

struct Vertex{
    Vertex(int v, std::set<int> a) : vertex_number(v), adjacents(a) {}
    int vertex_number;
    std::set<int> adjacents;
};

class Graph {
    public:
    Graph(std::vector<Vertex> v) : v_(std::move(v)) {}
    std::vector<Vertex> v_;
};


int main()
{
    Graph g(
        {Vertex(0, {1, 2}), Vertex(1, {0, 2, 3, 4}), Vertex(2, {0, 1, 3}), Vertex(3, {0, 1, 2})}
    );

    
}

// Using std::move avoids potentially making a copy

// https://stackoverflow.com/questions/51836609/why-can-an-rvalue-not-bind-to-a-non-const-lvalue-reference-other-than-the-fact
// https://compiler-explorer.com/z/znh8exzPK
