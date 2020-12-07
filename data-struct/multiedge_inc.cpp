// incidence matrix for undirected graph (multiedges)
#include <iostream>
#include <vector>
void addEdge(std::vector<std::vector<int> >& inc, size_t u, size_t v);
using std::vector;

struct inc_Mat {
    vector<int> elements;
    int n_cols;

    inc_Mat(int n_rows, int n_cols)
    : elements(n_cols*n_rows),
      n_cols(n_cols)
      {}
    int &operator()(int i, int j)
    {
        return elements[i*n_cols + j];
    }
};



void addEdge(inc_Mat &inc, int u, int v, int &ed_no)
{
    inc(u, ed_no) = 1;
    inc(v, ed_no) = 1; // don't use adj[u].push_back(v)
    ed_no++;
}

void print_graph(inc_Mat mat, int n_rows, int n_cols)
{
    for(int i = 0; i < n_rows; ++i)
    {
        for (int j = 0; j < n_cols; ++j)
        {
            std::cout << " " << mat(i, j);
        }
        std::cout << " \n";
    }
}


int main()
{
    int n_rows = 3;
    int n_cols = 5;
    int ed_no = 0;
    inc_Mat m2(n_rows, n_cols);
    addEdge(m2, 0, 1, ed_no);
    addEdge(m2, 0, 2, ed_no);
    addEdge(m2, 0, 2, ed_no);
    addEdge(m2, 0, 2, ed_no);
    addEdge(m2, 1, 2, ed_no);
    print_graph(m2, n_rows, n_cols);

}

