#include <iostream>
#include <sstream>
#include <vector>
#include <array>
#include <utility>
#include <string>

using Pair = std::vector<std::pair<int, int>>;
struct matrix
{
  matrix(int r) : storage_(r*r), size_(r) {}

  int& operator()(int i, int j)       noexcept {
     // std::cerr << "i= " << i << " and j= " << j << " and size_ =" << size_ << "\n";  
       return storage_[i-1 + size_*(j-1)]; }
  int  operator()(int i, int j) const noexcept { return storage_[i + size_*j]; }

  int size() const noexcept { return size_; }
  
  private:
  std::vector<int> storage_;
  int size_;
};
static std::vector<int> strToVecInts(const std::string &graph_string);
void printVecPair (Pair &V);
static Pair parseGraph(const std::string &graph_string);
void addEdge(matrix &adj, int u, int v);
void displayMatrix(matrix const& inc);
 
int main()
{
    std::string graph_string =
      "1\n"     // node number
      "2\n"   // list of nodes connected to node 1
      "6\n"     // node number
      "2 3 4\n" // list of nodes connected to node 2
      "7\n"     // node number
      "4 5\n"
      "8\n"     // node number
      "2 3 5\n"
      ;

      Pair result = parseGraph(graph_string);
      printVecPair(result);
      matrix adj(8);
      //std::cerr << adj.size() << "\n";
      for (auto &v : result)
      {
        // std::cerr << v.first << " " << v.second << "\n";
         addEdge(adj, v.first, v.second);
      }


    displayMatrix(adj);
}

template <typename T>
void printVec(T V)
{
    for (auto &v : V)
    {
        std::cerr << v << "\n";
    }
    std::cerr << "End of Print " << "\n";

}
static std::vector<int> strToVecInts(const std::string &graph_string)
{
    std::vector<int> vecInts;
    std::istringstream input_stream(graph_string);
    int number;
    while(input_stream >> number) {
        vecInts.push_back(number);
    }
 //   printVec(vecInts);
    return vecInts;
}
void printVecPair (Pair &V)
{
    for(auto &v : V)
    {
        std::cerr <<  v.first << " " << v.second << "\n";
    }
    std::cerr << "End of Print " << "\n";

}
static Pair parseGraph(const std::string &graph_string)
{
    std::istringstream split(graph_string);
    std::string each;
    Pair V;

    while(std::getline(split, each)) {
        std::vector<int> vec1 = strToVecInts(each);
        std::getline(split, each);// print 1 6 7 8
        std::vector<int> vec2 = strToVecInts(each);
       // std::cerr<< vec1[0] << "\n";

        for (int x : vec2) {
            V.push_back(std::make_pair(vec1[0], x));
        }
    }
    return V;
}
void addEdge(matrix &adj, int u, int v)
{
    adj(u, v) += 1;
    adj(v, u) += 1;
}

void displayMatrix(matrix const& adj) 
{
    for(/*std::size_t*/int i = 0; i < adj.size(); i++)
    { 
        for(/*std::size_t*/int j = 0; j < adj.size(); j++) 
        {
            std::cout << adj(i,j) << "  ";
        }
        std::cout << std::endl;
    }
}
