//Serialize and Deserialize N-ary Tree
#include <string>
#include <vector>

using std::vector;
using std::string;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string buf;
        serializeHelper(root, buf);

        return buf;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int pos = 0;
        return deserializeHelper(data, pos);
    }

private:
    Node* deserializeHelper(const string& buf, int& pos) {
        bool notNull = readBool(buf, pos);
        if (!notNull)   return nullptr;
        int val = readInt(buf, pos);
        int childrenCount = readInt(buf, pos);
        vector<Node*> children;
        for (int i = 0; i < childrenCount; ++i) {
            children.push_back(deserializeHelper(buf, pos));
        }
        Node* node = new Node(val, children);
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
            serializeHelper(root->children[i], buf);
        }
    }

    void writeBool(string& buf, bool val) {
        buf.append(val ? "1000" : "0000"); 
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


static void deleteNode(Node *new_root_ptr)
{
    for (auto *child_ptr : new_root_ptr->children) {
        deleteNode(child_ptr);
    }

    delete new_root_ptr;
}


int main()
{
    Node node5{5,{}};
    Node node6{6,{}};
    Node node3{3,{&node5,&node6}};
    Node node2{2,{}};
    Node node4{4,{}};
    Node node1{1,{&node3,&node2,&node4}};

   //Your Codec object will be instantiated and called as such:
    Codec codec;
    Node *new_root_ptr = codec.deserialize(codec.serialize(&node1));
    deleteNode(new_root_ptr);
}


 

