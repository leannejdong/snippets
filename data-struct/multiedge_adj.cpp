#include <iostream>
#include <vector>
using std::vector;
using std::cerr;

struct adj_Mat {
    vector<int> elements;
    int n_cols;

    adj_Mat(int n_rows, int n_cols)
    : elements(n_cols*n_rows),
      n_cols(n_cols)
      {}
    int &operator()(int i, int j)
    {
        return elements[i*n_cols + j];
    }
};



void addEdge(adj_Mat &adj, int u, int v)
{
    cerr << "In addEdge(u=" << u << ", v=" << v << ")\n";
    cerr << "1: adj(u,v) == " << adj(u,v) << "\n";
    adj(u, v) += 1;
    cerr << "2: adj(u,v) == " << adj(u,v) << "\n";
    cerr << "3: adj(v,u) == " << adj(v,u) << "\n";
    adj(v, u) += 1; 
    cerr << "4: adj(v,u) == " << adj(v,u) << "\n";
    cerr << "Leaving addEdge(u=" << u << ", v=" << v << ")\n";
}

void print_graph(adj_Mat mat, int n_rows, int n_cols)
{
    for(int i = 0; i < n_rows; ++i)
    {
        for (int j = 0; j < n_cols; ++j)
        {
            std::cerr << " " << mat(i, j);
        }
        std::cerr << " \n";
    }
}



int main()
{
    int n_rows = 3;
    int n_cols = 3;
    int ed_no = 0;
    adj_Mat m2(n_rows, n_cols);
    addEdge(m2, 0, 1);
    cerr << "After 1st call to addEdge, the graph is:\n";
    print_graph(m2, n_rows, n_cols);
    addEdge(m2, 0, 2);
    cerr << "After 2nd call to addEdge, the graph is:\n";
    print_graph(m2, n_rows, n_cols);
    addEdge(m2, 2, 0);
    cerr << "After 3rd call to addEdge, the graph is:\n";
    print_graph(m2, n_rows, n_cols);
    addEdge(m2, 1, 2);
    print_graph(m2, n_rows, n_cols);

}

