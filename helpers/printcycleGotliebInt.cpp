#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <iterator>
#include <cassert>

using namespace std;

class Graph {
    int nodeCount;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<std::vector<int>> treeAdjMat;
    
public:
    // Initialize the matrix to zero
    Graph(int nodeCount): nodeCount(nodeCount), adjMatrix(nodeCount, std::vector<int>(nodeCount, 0)),
     treeAdjMat(nodeCount, std::vector<int>(nodeCount)) {}
     
      void addEdge(int i, int j) {
            assert(i >= 0 && i < nodeCount && j > 0 && j < nodeCount);
            ++adjMatrix[i][j]/* = true*/;
            ++adjMatrix[j][i]/*= true*/;
      }
      void removeEdge(int i, int j) {
            assert(i >= 0 && i < nodeCount && j > 0 && j < nodeCount);
            ++adjMatrix[i][j] /*= false*/;
            ++adjMatrix[j][i] /*= false*/;
      }
      bool isEdge(int i, int j) {
            if (i >= 0 && i < nodeCount && j > 0 && j < nodeCount)
                  return adjMatrix[i][j];
            else
                  return false;
      }

        template <class OutputIterator>
        void DFSCheckCycle(std::vector<std::vector<int>> &adjMat, int u, int par, std::vector<bool> &visited, 
                      std::vector<int> &parents, int source, OutputIterator foundCycle) 
        {
          if (visited[u]) {
              if (u == source) {
                  //cycle found
                  parents[u] = par;
                  while (true) {
                      *foundCycle++ = u;
                      u = parents[u];
                      if (u == source) {
                          *foundCycle++ = u;
                          break;
                      }
                  }
              }
              return;
          }
          visited[u] = true;
          parents[u] = par;
          for (int v = 0; v < adjMat.size(); ++v) {
              if (adjMat[u][v] == 1 && v != parents[u]) {
                  DFSCheckCycle(adjMat, v, u, visited, parents, source, foundCycle);
              }
          }
      }

    template <class OutputIterator>
    OutputIterator Gotlieb(OutputIterator cycles) {
          auto orgAdjMat = adjMatrix;
          //const auto &nodes = orgAdjMat.nodes();
          const auto nodeCount = orgAdjMat.size();

        // Initialize adjacency matrix for spanning tree
          treeAdjMat = std::vector<std::vector<int>> (nodeCount, std::vector<int>(nodeCount, 0));
          for (int i = 0; i < nodeCount; ++i) {
              for (int j = i; j < nodeCount; ++j) {
                  if (orgAdjMat[i][j] == 1) {
                      treeAdjMat[i][j] = 1;
                      treeAdjMat[j][i] = 1;
                      break;
                  }
              }
          }

                // BLOCK 2: Find all connected components
            /* Example: C = [ [ 1 1 1 0 0 1 ],
            *                [ 0 0 0 1 0 0 ],
            *                [ 0 0 0 0 1 0 ] ] */

            std::vector<std::vector<int>> connComponents;
            std::vector<bool> visited(nodeCount, false);
            for (int u = 0; u < nodeCount; ++u)
            {
                if (visited[u])
                    continue;
                std::vector<int> component(nodeCount, 0);
                std::stack<int> s;
                s.push(u);
                while (!s.empty())
                {
                    int v = s.top();
                    visited[v] = true;
                    component[v] = 1;
                    s.pop();
                    for (int w = 0; w < nodeCount; w++)
                    {
                        if (treeAdjMat[v][w] && !visited[w])
                        {
                            s.push(w);
                        }
                    }
                }
                connComponents.push_back(component);
            }
            // Now focus on finding cycle base
            /* Block 3: Here the connected components are amalgamated by
            adding appropriate edges to the adjacency matrix B (treeAdjMat)
            Example: edge(2, 5) and (2, 6) are added back to B
            */

            //NOTE: 
            //  some utility functions for connected components 
            auto connComponentOrder = [](auto &c){ return std::count(std::begin(c),std::end(c),true); };
            auto toComponent =
                [&](auto n)->auto &{ //NOTE: return auto &, since we get a copy by default 
                    return *std::find_if(std::begin(connComponents),std::end(connComponents),[&](auto &c){ return c[n]; });
                };
            
            while(connComponents.size() > 1){
                //  sort the components in descending order (node count). descending so that we can easily remove the smallest with a pop_back. 
                std::sort(std::begin(connComponents),std::end(connComponents),[&](auto &c0,auto &c1){ return connComponentOrder(c0) > connComponentOrder(c1); });
                auto &small = connComponents.back();
                auto &big = 
                    [&]()->auto &{ //NOTE: find cross edge to bigger component, auto & again to get reference 
                        for (int i = 0; i < nodeCount; ++i){
                            if(!small[i])
                                continue;
                            for (int j = 0; j < nodeCount; ++j){
                                if(adjMatrix[i][j] == 1 && !small[j]){
                                    treeAdjMat[i][j] = 1;
                                    treeAdjMat[j][i] = 1;              
                                    return toComponent(j);
                                }
                            }
                        }
                        __builtin_unreachable(); //NOTE: we should never reach this 
                    }();

                //NOTE: move the nodes from small component to big component 
                for (int i = 0; i < nodeCount; ++i)
                    if(small[i])
                        big[i] = true;
                connComponents.pop_back();
            }

            // BLOCK 4
            /* Collect all edges eliminated from the original adjacency matrix to
            build the spanning tree matrix
            */
            std::vector<std::pair<int, int>> eliminatedEdges;
            for (int i = 0; i < nodeCount; ++i)
                for (int j = i; j < nodeCount; ++j)
                    if (treeAdjMat[i][j] !=orgAdjMat[i][j])
                        eliminatedEdges.emplace_back(i, j);
            // FINAL: Iterate through each eliminated edge, try adding it into mat B(treeAdjMat)
            // The use DFS to check the cycle, the source node is the first node of the edge
            for (auto edge: eliminatedEdges)
            {
                visited = std::vector<bool>(nodeCount, false);
                std::vector<int> parents(nodeCount, -1);
                treeAdjMat[edge.first][edge.second] = treeAdjMat[edge.second][edge.first] = 1;
                DFSCheckCycle(treeAdjMat, edge.first, -1, visited, parents, edge.first, cycles);
                treeAdjMat[edge.first][edge.second] = treeAdjMat[edge.second][edge.first] = 0;
            }
        return cycles;
    }

      void printMat() {
          int i, j;
          for (i = 0; i < nodeCount; i++ )
          {
              for (j = 0; j < nodeCount; j++)
              {
                  std::cout << to_string(adjMatrix[i][j]) << " ";
              }
              std::cout << "\t";

              for (j = 0; j < nodeCount; j++)
              {
                  std::cout << to_string(treeAdjMat[i][j]) << " ";
              }

              cout << endl;
          }
      }


};


// Requires a sequence of closed cycles.
template <class ForwardIterator>
void print_cycles(ForwardIterator first, ForwardIterator last)
{
    using T = typename iterator_traits<ForwardIterator>::value_type;
    while (first != last)
    {
        auto const cycle_start = first++;
        first = ++find(first, last, *cycle_start);
        copy(cycle_start, first, ostream_iterator<T>(cout, " "));
        cout << "\n";
    }    
}


int main() 
{
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(5, 1);
    g.addEdge(5, 2);
    g.addEdge(5, 3);
    g.addEdge(6, 3);
    g.addEdge(6, 4);
    g.addEdge(7, 4);
    g.addEdge(7, 1);
    g.addEdge(7, 2);
  

    std::vector<int> cycles;
    g.Gotlieb(back_inserter(cycles));
    print_cycles(begin(cycles), end(cycles));

    g.printMat();
}

