#include <list>
#include <iostream>
#include <vector>
using namespace std;

class Hash
{
    int Bucket;

    vector<list<int>> table;

public:
    Hash(int V);

    void insertItem(int x);

    void deleteItem(int key);

    int hashfunction(int x)
    {
        return (x % Bucket);
    }

    void displayHash();

};

Hash::Hash(int b)
{
    this->Bucket = b;
    table.resize(Bucket);
}

void Hash::insertItem(int key)
{
    int index = hashfunction(key);
    table[index].push_back(key);

}

void Hash::deleteItem(int key) 
{ 
  // get the hash index of key 
    int index = hashfunction(key); 
    // if key is found in hash table, remove it 
    table[index].remove(key);
//   // alternatively, use std::find
//     auto result = std::find(std::begin(table), std::end(table), key);

//     if (result != std::end(table))
//     {
//         table[index].remove(key);
//     }

} 
  
// function to display hash table 
void Hash::displayHash() { 
  for (int i = 0; i < Bucket; i++) { 
    cout << i; 
    for (auto x : table[i]) 
      cout << " --> " << x; 
    cout << endl; 
  } 
} 

int main()
{
    std::vector<int> a { 15, 11, 27, 8, 12};
    //int n = a.size();

    Hash h(7);

    for (auto r : a)
    {
        h.insertItem(r);
    }

    h.deleteItem(12);

    h.displayHash();

    return 0;

}
