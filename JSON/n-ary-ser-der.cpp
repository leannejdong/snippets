/// Serialize and deserialize n-ary tree
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
    //Node() {}
    Node(int _val): val{_val}{}

    Node(int _val, vector<unique_ptr<Node>> _children): val{_val}, children{std::move(_children)} {}
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

class Codec {
    public:
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
    string ser = obj.serialize(n1.get());
    std::cout << "Serialize: " << ser << "\n";

    unique_ptr<Node> deser = obj.deserialize(ser);
    std::cout << "Deserialized Tree: " << n_ary_to_str(deser.get()) << "\n";

}
