#include <string>
#include <vector>
#include <iostream>
#include <memory>

using std::vector;
using std::string;
using std::cerr;
using std::unique_ptr;
using std::make_unique;

// Definition for a Node.
class Node {
public:
    int val;
    vector<unique_ptr<Node>> children;
    unique_ptr<Node> left, right;

    Node() {}

    Node(int _val, vector<unique_ptr<Node>> _children) {
        val = _val;
        children = std::move(_children);
    }
};

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


static vector<unique_ptr<Node>> copyNodes(const vector<unique_ptr<Node>> &originals);


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

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string buf;
        serializeHelper(root, buf);

        return buf;
    }


    // Decodes your encoded data to tree.
    unique_ptr<Node> deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    unique_ptr<Node> deserializeHelper(const string& buf, int& pos) {
        bool notNull = readBool(buf, pos);
        if (!notNull)   return nullptr;
        int val = readInt(buf, pos);
        int childrenCount = readInt(buf, pos);
        vector<unique_ptr<Node>> children;
        for (int i = 0; i < childrenCount; ++i) {
            children.push_back(deserializeHelper(buf, pos));
        }
        auto node = make_unique<Node>(val,  std::move(children));
        return node;
    }


    void serializeHelper(Node* root, string& buf) {
        if (root == nullptr) {
            writeBool(buf, false);
            return;
        }

        writeBool(buf, true);
        writeInt(buf, root->val);
        int childrenCount = root->children.size();

        writeInt(buf, childrenCount);
        for (size_t i = 0; i < root->children.size(); ++i) {
            serializeHelper(root->children[i].get(), buf);
        }
    }

    void writeBool(string& buf, bool val) {
        buf.append(val ? "1000" : "0000"); // alignment!!!!
    }

    bool readBool(const string& str, int& pos) {
        char c = str[pos];
        pos += 4;
        return c == '1';
    } 

    void writeInt(string& str, int& val) {
        const char* valStr = reinterpret_cast<const char*> (&val);
        str.append(valStr, sizeof(val));
    }

    int readInt(const string& str, int& pos) {
        int val = *((reinterpret_cast<const int*> (str.data() + pos)));
        pos += sizeof(int);
        return val;
    }

};


// static void deleteNode(Node *new_root_ptr)
// {
//     for (auto *child_ptr : new_root_ptr->children) {
//         deleteNode(child_ptr);
//     }

//     delete new_root_ptr;
// }


static void printNodes(Node *root)
{
    cerr << "In printNodes()\n";
    cerr << "  root = " << root << "\n";
    if (!root) return;
    // if node is leaf node, print its data
    cerr << "  root->children.size(): " << root->children.size() << "\n";
    for(size_t i = 1; i < root->children.size(); i++){
        cerr << "root->children[" << i << "]: " << root->children[i].get() << "\n";
        if(root->children[i]) {
            cerr << "Printing out root->val\n";
            std::cout << root->val << " ";
        }
        else {
            cerr << "Not printing out root->val\n";
        }
    }
    if (root->left)
    {
        printNodes(root->left.get());
    }
    if (root->right)
    {
        printNodes(root->right.get());
    }
}

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
    auto node5 = make_unique<Node>(5,vector<unique_ptr<Node>>());
    auto node6 = make_unique<Node>(6,vector<unique_ptr<Node>>());
   vector<unique_ptr<Node>> node3_children;
   node3_children.push_back(std::move(node5));
   node3_children.push_back(std::move(node6));
   unique_ptr<Node> node3 = make_unique<Node>(3,std::move(node3_children));
   auto node2 = make_unique<Node>(2,vector<unique_ptr<Node>>());
   auto node4 = make_unique<Node>(4,vector<unique_ptr<Node>>());
    vector<unique_ptr<Node>> node1_children;
    node1_children.push_back(std::move(node3));
    node1_children.push_back(std::move(node2));
    node1_children.push_back(std::move(node4));
   unique_ptr<Node> node1 = make_unique<Node>(1,std::move(node1_children));

    Codec codec;
    std::cout << "Given Tree: " << n_ary_to_str(node1.get()) << "\n";
    unique_ptr<Node> root = codec.encode(node1.get());
    std::cout << "root->left: " << root->left.get() << "\n";
    std::cout << "root->right: " << root->right.get() << "\n";
    inord(root.get()); 
    std::cout << "\n";
}


 

