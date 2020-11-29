#include<vector>
#include<memory>
#include<string>
#include<iostream>

using std::vector;
using std::string;
using std::unique_ptr;
using std::make_unique;

// structure of A node of N-ary tree 
struct Node { 
   string key; 
   vector<Node> children;  // An array of pointers for N children 
};


int main()
{
    Node root{"root",{{"child1",{}},{"child2",{}}}};
}

//If we don't have any user-defined constructors, 
//then we can initialize a class with {} by just giving the values of the members.
