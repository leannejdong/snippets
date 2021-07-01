#include <iostream>
#include <list>
#include <cstdlib>
#include <cassert>
#include <vector>

#define NEW 1
#if NEW
#include <random>
#endif

using std::cerr;
using std::list;
using std::vector;

class HashTable{
private:
    // Number of buckets to store elements
    int buckets;

    // Pointer to said buckets
    std::vector<list<int>> table;

public:
    // Simple constructor
    HashTable(int b){
        // Allocate space for the number of buckets asked for 
        buckets = b;
        table = vector<list<int>>(buckets);// create a table of bucket
    }

    // insert into hash table
    void insert(int d);

    // Print out the hash table
    void print();
};


void HashTable::insert(int d){
    // Simple hash function is just modulo number of buckets
    int bucket = d % buckets;

    // Insert into hash table bucket
    table[bucket].push_back(d);
}

void HashTable::print(){
    for(int i = 0; i < buckets; i++){
        cerr << "| Bucket " << i << " | ";
        for(auto j : table[i]){
            cerr << "-> | " << j << " | ";
        }
        cerr << "\n";
    }
}

int main(){
    // Create a hash table with 8 buckets
    HashTable ht(8);

    // Set the random number seed
    // srand(2);
    std::mt19937 random_engine(32);
    std::uniform_int_distribution<> distrib(1, 6);

    // Insert 20 random integers
    for(int i = 0; i < 20; ++i){
//        ht.insert(rand() % 100);
        ht.insert(distrib(random_engine) % 100);          
    }

    // Print the state of the hash table
    ht.print();

    return 0;
}
