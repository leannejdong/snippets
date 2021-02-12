///encode n-ary to binary, decode to n-ary, ser, deser 
///encode, decode follow left is child, right is sibling strategy
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

      // encodes an n-ary tree to a binary tree(left is child, right is sibling)
    unique_ptr<Node> encode(Node* root) {
      if(!root) return nullptr;
         auto node = make_unique<Node>(root->val, copyNodes(root->children));
         cerr << "encode: root->children.size(): " << root->children.size() << "\n";
         if(root->children.size()){
            node->left = encode(root->children[0].get());
            cerr << "encode: node->left: " << node->left.get() << "\n";
         }
         Node* curr = node->left.get();
         for(size_t i = 1; i < root->children.size(); ++i){
            curr->right = encode(root->children[i].get());
            curr = curr->right.get();
         }
         cerr << "encode: returning node->left: " << node->left.get() << "\n";
         return node;
      }

    // Decodes a binary tree to n-ary tree;(left is child, right is sibling)
    unique_ptr<Node> decode(Node* binary_root)
    {
        if(!binary_root) 
            return nullptr;
        auto nary_root = make_unique<Node>(binary_root->val);
        Node* current_binary_child = binary_root->left.get();
        while (current_binary_child)
        {
            nary_root->children.push_back(decode(current_binary_child));
            current_binary_child = current_binary_child->right.get();
        }
        //return std::move(nary_root);
        return nary_root;
    }

    vector<vector<int>> createVector(string s) {
        vector<vector<int>> ret;
        vector<int> tempv;
        string temp = "";
        for (size_t i = 0; i < s.size(); ++i) {
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

int main()
{
    Codec obj;
    auto n5 = make_unique<Node>(5);
    auto n6 = make_unique<Node>(6);
    auto n3 = make_unique<Node>(3);
    n3->children.push_back(std::move(n5));
    n3->children.push_back(std::move(n6));

    auto n2 = make_unique<Node>(2);
    auto n4 = make_unique<Node>(4);
    auto n1 = make_unique<Node>(1);
    n1->children.push_back(std::move(n3));
    n1->children.push_back(std::move(n2));
    n1->children.push_back(std::move(n4));

    std::cout << "Given Tree: " << n_ary_to_str(n1.get()) << "\n";
    std::cout << "Encode n1: " << "\n";
    unique_ptr<Node> root = obj.encode(n1.get());
    std::cout << "root->left: " << root->left.get() << "\n";
    std::cout << "root->right: " << root->right.get() << "\n";
    inord(root.get()); 
    std::cout << "\n";
    string ser = obj.serialize(n1.get());
    std::cout << "Serialize: " << ser << "\n";

   // unique_ptr<Node> deser = obj.deserialize(ser);
   // std::cout << "Deserialized Tree: " << n_ary_to_str(deser.get()) << "\n";
    std::cout << "Decode binary to n-ary: " << "\n";
    unique_ptr<Node> de_root = obj.decode(root.get());
    std::cout << n_ary_to_str(de_root.get());
}
//https://godbolt.org/z/Wj54GE
