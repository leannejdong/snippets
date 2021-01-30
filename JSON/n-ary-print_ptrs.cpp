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
   vector<Node *> children;  // An array of pointers for N children 
};

unique_ptr<Node>newNode(string key)
{
    return std::make_unique<Node>(key);
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
        Node *p = q.front();
        q.pop();
        cerr << p->key << " ";

        // Enqueue all children of the dequeued item
        // for ( const auto &child : root->children)
        // {
        //     q.push(p->child);
        // }
        for (size_t i=0; i<p->children.size(); ++i) 
        {
            q.push(p->children[i]); 
            //   n--; 
        }
        cout << "\n";
    }
    
}


int main()
{
    unique_ptr<Node> root = newNode("root");
    unique_ptr<Node> child1 = newNode("child1");
    root->children.push_back(child1.get());
     unique_ptr<Node> child2 = newNode("child2");
    root->children.push_back(child2.get());

    unique_ptr<Node> child3 = newNode("child3");
    root->children.push_back(child3.get());

    printRoot(root.get());
    
}
