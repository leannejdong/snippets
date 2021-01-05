#include <cassert>
#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <stack>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <array>

using namespace std::ranges;
using std::string;
using std::vector;
using std::pair;
using std::istringstream;
using std::stack;
using std::make_pair;
using std::ranges::sort;
using std::array;
constexpr int N = 100000;

static vector<int> StrToVecInts(const string &graph_string)
{
    vector<int> vecInts;
    istringstream input_stream(graph_string);
    int number;
    while(input_stream >> number) {
        vecInts.push_back(number);
    }
    return vecInts;
}

static vector<pair<int,int>> parseGraph(const string &graph_string)
{
    std::istringstream split(graph_string);
    string each;
    vector<pair<int, int>> V;

    while (std::getline(split, each)) {
        vector<int> vec1 = StrToVecInts(each);
        std::getline(split, each);
        vector<int> vec2 = StrToVecInts(each);

        for (int x : vec2) {
            V.push_back(make_pair(vec1[0], x));
        }
    }

    return V;
}

class Graph
{
	//std::vector<std::vector<int>> vertices;
	std::vector<int> parents;
    std::vector<int> v_;
    std::vector<std::pair<int, int>> e_;
	bool cycle_found = false;
  //  int cnt = 0;

public:

    Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e);

	static vector<int> findNeighbors(int node_id, const vector<pair<int,int>> &edges);
	bool has_cycle() const;
	bool has_vertex(int index) const;
	void compute_cycles();
	void print_cycle(int first_vertex, int last_vertex, int &cnt/*, vector<int> &cycles*/) const;


private:
	void dfs_compute_cycle(std::vector<bool>& visited, int current_vertex, int &cnt/*, vector<int> &cycles*/);
};

Graph::Graph(std::vector<int> &v, std::vector<std::pair<int, int>> &e)
    :  parents(v_.size(), -1), v_(v), e_(e) {}

vector<int> Graph::findNeighbors(int node_id, const vector<pair<int,int>> &edges)
{
    vector<int> neighbors;
    for (auto u : edges)
    {
        if ((node_id  == u.first))
        {
            neighbors.push_back(u.second);
        } else if (node_id  == u.second) {
            neighbors.push_back(u.first);
         } 
    }
    return neighbors;
}

bool Graph::has_cycle() const
{
	return cycle_found;
}

bool Graph::has_vertex(int index) const
{
	return index >= 0 && index < (int)e_.size();
}


void Graph::compute_cycles()
{
	auto const vertices_count = e_.size();
   // std::cerr << vertices_count << "\n";
	std::vector<bool> visited(vertices_count, false);
    int cnt = 0;
    vector<int> cycles;

	for (size_t i = 0; i < vertices_count; ++i)
	{
		if (!visited[i]) dfs_compute_cycle(visited, i, cnt/*, cycles*/);
	}
}

void Graph::dfs_compute_cycle(std::vector<bool>& visited, int current_vertex, int &cnt/*, vector<int> &cycles*/)
{
   // std::cerr << current_vertex << "\n";
	assert(has_vertex(current_vertex));
	visited[current_vertex] = true;
      // mark the current vertex as visited
    vector<int> neighbors;
    neighbors = findNeighbors(current_vertex, e_);
    // go through each element of the neighbor
	for (auto v : neighbors)
	{  // here we see the problem
        //std::cerr << visited.size() << "\n";
        //std::cerr << v << "\n";
        // check to see if the neighbor of the current vertex is visited
        if (!visited[v])
		{
            // the neighbor of the current vertex is not visited

			parents[v] = current_vertex;
              // set the parent of the neighbor of the current vertex to the current vertex

			dfs_compute_cycle(visited, v, cnt/*, cycles*/);
              // recursively compute the cycle with the neighbor of the current vertex
		}
		else 
        {

            // the neighbor of the current vertex is visited
            if (v != parents[current_vertex] && current_vertex > v)
            {
                // The neighbor of the current vertex is not the parent of the current vertex.
                // The current vertex has a higher index than the neighbor.
                cycle_found = true;
                // set cycle_found to true

                std::cerr << "cycle found: ";
                cnt++;
                //cycles.push_back(cnt);
                print_cycle(current_vertex, v, cnt/*, cycles*/);
                // print out the cycle using the current vertex and the neighbor of the current
                // vertex

                std::cerr << "\n";
                std::cerr << cnt << "\n";
            }
        }
	}
}

void Graph::print_cycle(int first_vertex, int last_vertex, int &cnt/*, vector<int> &cycles*/) const
{

    // std::cerr<< "parents[first_vertex] " << parents[first_vertex] << "\n";
    // std::cerr<< "last_vertex " << last_vertex  << "\n";
    vector<int> vec;

    for (;;) {
        assert(has_vertex(first_vertex));
	    assert(has_vertex(last_vertex));

        if (first_vertex < last_vertex)
        {
            std::swap(first_vertex, last_vertex);
        }
        
        vec.push_back(first_vertex);


       // std::cout << first_vertex;
        if (first_vertex == last_vertex)
        {
            break;
        }
        first_vertex = parents[first_vertex];
    }
        if ( cnt == 2) {
            vec.resize(vec.size()-2);
            for (const auto &v : vec)
            {
                std::cerr << v << " ";
            }            
        } else {
            for (const auto &v : vec)
            {
                std::cerr << v << " ";
            }   
        }

    //}
 

}


int main()
{
    string graph_string =
      "1\n"     // node number
      "2\n"   // list of nodes connected to node 1
      "6\n"     // node number
      "2 3 4\n" // list of nodes connected to node 2
      "7\n"     // node number
      "4 5\n"
      "8\n"     // node number
      "2 3 5\n"
      ;

    
//    string graph_string =
//       "1\n"     // node number
//       "2 3 4\n"   // list of nodes connected to node 1
//       "2\n"     // node number
//       "3 4 5\n" // list of nodes connected to node 2
//       "4\n"     // node number
//       "5\n"
//       "5\n"     // node number
//       "6 7\n"
//       ;
    
    vector<pair<int,int>> e = parseGraph(graph_string);
    vector<int> v;
#if 1   // via std::transform, copy a vec-pair to vec
    std::transform(begin(e), end(e), std::back_inserter(v),
    [&v](const std::pair<int, int> &pair)
    {v.push_back(pair.first);
     return pair.second ;});
#else   
    for (auto p : e) { // loop over all pairs and add both node_ids to a single vec
        v.push_back(p.first);
        v.push_back(p.second);
    }
#endif
     sort(v);
     auto last = std::unique(begin(v), end(v));
    // v.erase(last, v.end());
   // std::cerr << v.size() << " and " << e.size() <<'\n';
    Graph g(v, e);
	g.compute_cycles();

}
//https://godbolt.org/z/erWjWK
