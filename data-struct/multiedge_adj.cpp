// print the number of (parallel) edges between vertices
#include <boost/graph/adjacency_list.hpp>
#include <iostream>
#include <iterator>

using namespace boost;

template <typename Graph>
void displayMatrix(Graph const &inc) 
{
    for(std::size_t i = 0; i != num_vertices(inc); i++)
    {
        for(std::size_t j = 0; j != num_vertices(inc); j++)
        {
            auto parallel_edges = edge_range(i, j, inc);
            std::cout << std::distance(parallel_edges.first, parallel_edges.second) << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    adjacency_list<multisetS, vecS, undirectedS> inc;
    add_edge(0, 1, inc);
    add_edge(0, 2, inc);
    add_edge(0, 2, inc);
    add_edge(1, 2, inc);
    displayMatrix(inc);
}


