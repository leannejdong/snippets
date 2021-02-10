#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <queue>
using std::queue;
using std::vector;
using std::string;
using std::cerr;
using std::unique_ptr;
using std::make_unique;

class Node {
    public:
    int val;
    vector<unique_ptr<Node>> children;
    unique_ptr<Node> left, right;
    Node() {}
    Node(int _val): val{_val}{}

    Node(int _val, vector<unique_ptr<Node>> _children): val{_val}, children{std::move(_children)} {}
};

string n_ary_to_str(Node *root);
static unique_ptr<Node> copyNode(const Node &node);
static vector<unique_ptr<Node>> copyNodes(const vector<unique_ptr<Node>> &originals);


string n_ary_to_str(Node *root){
   string ret = "";
   if(root){
      ret = ret + std::to_string(root->val);
      if(root->children.size() > 0){
         ret += "[";
         for(unique_ptr<Node> &child : root->children){
            ret += n_ary_to_str(child.get()) + ", ";
         }
         ret += "]";
      }
   }
   return ret;
}

static unique_ptr<Node> copyNode(const Node &node)
{
    return make_unique<Node>(node.val, copyNodes(node.children));
}


static vector<unique_ptr<Node>> copyNodes(const vector<unique_ptr<Node>> &originals)
{
    vector<unique_ptr<Node>> result;

    for (const unique_ptr<Node> &original : originals) {
        result.push_back(copyNode(*original));
    }

    return result;
}


class Codec {
    public:

// encodes an n-ary tree to a binary tree
//The left child of each node in the binary tree is the first child of the node in the N-ary tree.
//The right child of each node in the binary tree is the next sibling of the node in the N-ary tree.
    unique_ptr<Node> encode(Node* root) {
      if(!root) return nullptr;
         auto node = make_unique<Node>(root->val, copyNodes(root->children));
         cerr << "encode: root->children.size(): " << root->children.size() << "\n";
         if(root->children.size()){
            node->left = encode(root->children[0].get());
            cerr << "encode: node->left: " << node->left.get() << "\n";
         }
         Node* curr = node->left.get();
         for(size_t i = 1; i < root->children.size(); i++){
            curr->right = encode(root->children[i].get());
            curr = curr->right.get();
         }

         cerr << "encode: returning node->left: " << node->left.get() << "\n";
         return node;
      }

    // Decodes a binary tree to n-ary tree;
    unique_ptr<Node> decode(Node* root)
    {
      if(!root) return nullptr;
      //if(!root->left.get())
      //{ // node := new node with val of root
          /*return*/ make_unique<Node>(root->val, copyNodes(root->children));
      //}
      Node* curr = root->left.get(); // curr := left of root
      while (curr)
      {
          root->children.push_back(decode(curr));
          curr = curr->right.get();
      }
      return make_unique<Node>(root->val, copyNodes(root->children));
    }

    vector<vector<int>> createVector(string s) {
        vector<vector<int>> ret;
        vector<int> tempv;
        string temp = "";
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && s[i] != '#') {
                temp += s[i];
            }
            else if (s[i] == ' ') {
                //cerr << "found ' ' "<< "\n";
                tempv.push_back(stoi(temp));
                temp = "";
            }
            else if (s[i] == '#') {
                ret.push_back(tempv);
                temp = "";
                tempv.clear();
            }
        }
        // for(size_t i = 0; i < ret.size(); ++i) {
        //     cerr << ret[i].size() << "\n";
        // }
        while (!ret.empty() && ret.back().size() == 0)
        {
           // std::cerr << "start popping back" << "\n";
            ret.pop_back();
        }
        return ret;
    }

    string serialize(Node *root) {
        string ret = "";
        if(!root) return ret;
        queue<Node *> q;
        q.push(root);
        ret += std::to_string(root->val);
        ret += " ";
        ret += "#";
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            for (size_t i = 0; i < curr->children.size(); ++i) {
                if (curr->children[i]) {
                    ret += std::to_string(curr->children[i]->val);
                    q.push(curr->children[i].get());
                }
                ret += " ";
            }
            ret += "#";
        }
        return ret;
    }

    unique_ptr<Node> deserialize(string data) {
        unique_ptr<Node> ret;
        if (data.size() == 0){return nullptr;} 
        vector<vector<int>> v = createVector(data);
       // cerr << v.size() << "\n";
        ret = make_unique<Node>(v[0][0]);

        //queue<unique_ptr<Node>> q;
        queue<Node *> q;
        q.push(ret.get());
        size_t i = 1;
        while (!q.empty() && i < v.size()) {
            Node* curr = q.front();
            q.pop();
            //for (auto j : v[i]) {
            for (size_t j = 0; j < v[i].size(); ++j) {
                int node = v[i][j];
                auto temp = make_unique<Node>(node);
                q.push(temp.get());
                curr->children.push_back(std::move(temp));
            }
            ++i;
        }
        return ret;
    }  

};

static void inord(Node *root)
{
    if (root!=nullptr)
    {
        inord(root->left.get());
        std::cout << root->val << " ";
        inord(root->right.get());
    }
}

std::ostream& operator<<(std::ostream& os, const Node* node)
{
    os << node->val;
    return os;
}

int main()
{

    Node number = 1;
    Node *root = &number;
    root->right = make_unique<Node>(3);
    //root->right->left = make_unique<Node>(5);
    root->right->right = make_unique<Node>(7);
    std::cout << root->right << "\n";
   // std::cout << root->left << "\n";

     Codec obj;
     unique_ptr<Node> de_root = obj.decode(root);
     inord(de_root.get()); 
     std::cout << "\n";

}
/*
Define a function encode(), this will take root,

if root is valid, then −

    return null

node = new tree node with value of root

if size of children of root is not 0, then −

    left of node := encode(children[0] of root)

curr = left of node

for initialize i := 1, when i < size of children of root, update (increase i by 1), do −

    right of node := encode(children[i] of root)

    curr := right of curr

return node

Define a function decode(), this will take root,

if root is not present, then −

    return NULL

node := new node with val of root

curr := left of root

while curr is non-zero, do −

    insert decode(curr) at the end of children of node

    curr := right of curr

return node*/


