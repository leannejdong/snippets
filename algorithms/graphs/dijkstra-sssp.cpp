// Dijkstra's shortest path algorithm via adjacency matrix representation
#include <iostream>
#include <iomanip>
#include <climits>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>
#include <utility>
#include <algorithm>

using std::vector;
using std::array;
using std::setw;
using std::cout;

constexpr int V = 10;

// utilit yfunction to find the vertex with minimum distance value,
// from the set of vertices not yet included in shortest path tree

int minDistance(array<int, V> &dist, array<bool, V> &sptSet)
{
    // Initialize min
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;

}

void printSoln(array<int, V> &dist)
{
    cout << "Vertex" << setw(3) << "Distance from source" << " \n";
    for (int i = 0; i < V; i++)
    {
        cout << i << setw(16) << dist[i] << " \n";
    }

}

void dijkstra(array<array<int, V>, V> graph, int src)
{
    array<int, V> dist; // The output array. dist[i] will distance from src to i
    array<bool, V> sptSet; // sptSet[i] will be true if vertex i is included in shortest path tree or shortest distance from src to i is finalized

    // Initilialize all distances as infinite and stpSet as false
    for (int i = 0; i < V; i++) 
    {
        dist[i] = INT_MAX, sptSet[i] = false;
    }
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    std::priority_queue<std::pair<int, int> > q;      // first int is point index, second int is priority

    q.push({0,src});
    while (!q.empty())
    {
        int a = q.top().second; q.pop();
        if (sptSet[a]) continue;

        int u = minDistance(dist, sptSet);
        sptSet[a] = true;
        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    q.push({-dist[v], v});
                }

        }
    }
    // print the constructed distance array
    printSoln(dist);

    // Find shortest path for all vec
}

int main() 
{ 
    /* Let us create the example graph discussed above */
    array<array<int, V>, V> graph = { { { 0, 4, 0, 0, 0, 0, 0, 8, 0 , 7}, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0, 13 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 , 3}, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 , 9}, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 , 9}, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 , 15}, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6, 9 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7, 10 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0, 9} } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
} 


