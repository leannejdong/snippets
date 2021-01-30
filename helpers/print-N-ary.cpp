#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;

// structure of A node of N-ary tree 
struct Node { 
   string key; 
   vector<Node> children;  // An array of pointers for N children 
};


static void printRoot(const Node &root)
{
    // If the root has no children, then print '[root]'
    if(root.children.size() == 0) {
        std::cout << root.key << "\n";
    } else if(root.children.size() > 0) {
        //for(size_t i = 0; i < root.children.size(); ++i)
        for(const auto &child : root.children)
        {
            std::cout << child.key << "\n";
        }
    }
}


int main()
{
    Node root1{"root",{{"child1",{}},{"child2",{}}}};
    // std::cout << root1.key << "\n";
    // std::cout << root1.children[0].key << "\n";
    Node root{"root",{}};
    printRoot(root);
    printRoot(root1);
}
