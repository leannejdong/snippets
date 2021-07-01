#include <unordered_set>
#include <cstddef>
#include <cassert>


struct Graph {
    using Vertex = int;
    using Edge = std::pair<Vertex,Vertex>;
// To use a hash table, we define a mapping from the keys to hash values
// That mapping is defined by the EdgeHash function object
    struct EdgeHash {
        size_t operator()(const Edge &e) const
        {
            return std::hash<int>()(e.first) ^ std::hash<int>()(e.second);
        }
    };

    std::unordered_set<Edge, EdgeHash> edge_set;

    void addEdge(Vertex from_vertex, Vertex to_vertex)
    {
        edge_set.insert({from_vertex, to_vertex});
    }
};


int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
}
// https://compiler-explorer.com/z/5dsejPnsn
