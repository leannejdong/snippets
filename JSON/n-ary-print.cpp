#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<memory>

using std::vector;
using std::string;
using std::queue;
using std::cout;
using std::cerr;
using std::unique_ptr;

// structure of A node of N-ary tree 
struct Node { 
   string key; 
   vector<Node> children;  // An array of pointers for N children 
};

Node newNode(string key)
{
    return Node(key,{});
}

static void printRoot(/*const*/ Node* root)
{
    if(root == nullptr) return;
    // create a queue and enqueue root to it
    queue<Node *> q;
    q.push(root);

    // do level order traversal. We use 2 loops
    // to make sure different levels are printed
    // in different lines
    while (!q.empty())
    {
        {
            Node *p = q.front();
            q.pop();
            cerr << p->key << " ";
            for (size_t i=0; i<p->children.size(); ++i) 
            {
                q.push(&p->children[i]); 
            }
            cerr << "\n";
        }
    }
    
}


int main()
{
    Node root = newNode("root");
    Node child1 = newNode("child1");
    root.children.push_back(child1);
    Node child2 = newNode("child2");
    root.children.push_back(child2);

    Node child3 = newNode("child3");
    root.children.push_back(child3);
 
    printRoot(&root);
}
