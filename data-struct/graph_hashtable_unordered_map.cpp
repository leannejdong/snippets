#include <unordered_set>
#include <cstddef>
#include <cassert>
#include <iostream>
#include <unordered_map>


struct Graph {
    using Weight = double;
    using Vertex = int;
    using Edge = std::pair<Vertex,Vertex>;
// To use a hash table, we define a mapping from the keys to hash values
// That mapping is defined by the EdgeHash function object
// basically, this encript keys(given by two nodes) to values
    struct EdgeHash {
        size_t operator()(const Edge &e) const
        {
            return std::hash<int>()(e.first) ^ std::hash<int>()(e.second);
        }
    };

    std::unordered_set<Edge, EdgeHash> edge_set;
    std::unordered_map<Edge, Weight, EdgeHash> edge_map;

    void addEdge(Vertex from_vertex, Vertex to_vertex, Weight to_weight)
    {
        edge_map.insert({{from_vertex, to_vertex}, to_weight});
    }
    void printEdge(){
        for(const auto&p: edge_map){
            std::cerr << p.first.first << "--" << p.first.second << " with weight " << p.second << "\n";
            
        }
    }
};

//std::unordered_map<std::pair<int,int>, double, Graph::EdgeHash> em;


std::ostream & operator<<(std::ostream &stream, 
                          const std::unordered_map<std::pair<int,int>, double, Graph::EdgeHash> &emap )
{
    for(const auto &item: emap){
        //for(auto x : item.first) stream << x.first << "--" << x.second << " ";
        stream << item.first.first << "--" << item.first.second << ":" << item.second;
        stream << "\n";
    }
    return stream;
}
std::ostream & operator <<(std::ostream &os, 
                           const std::unordered_map<std::string, std::pair<int,int>> &m)
{
    for (const auto &p : m)
    {
        os << p.first << ": ";
        //for (int x : p.second) os << x << ' ';
        os << p.second.first << "--" << p.second.second << " ";
        os << std::endl;
    }

    return os;
}



int main()
{
    Graph g;
    g.addEdge(0,1, 0.2);
    g.addEdge(1,2, 2.2);
  //  g.printEdge();
    std::unordered_map<std::pair<int,int>, double, Graph::EdgeHash> edge_map0{{{0, 1}, 0.2},{{1, 2}, 0.1}};
    std::cout << edge_map0;
}
// https://compiler-explorer.com/z/8MdPobxs4
