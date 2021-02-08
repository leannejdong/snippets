#include <bits/stdc++.h>
#include <memory>
using namespace std;
class Node {
public:
   int val;
   vector<Node*> children;
   Node() {}
   Node(int _val) {
      val = _val;
   }
   Node(int _val, vector<Node*> _children) {
      val = _val;
      children = _children;
   }
};
string n_ary_to_str(Node *root){
   string ret = "";
   if(root){
      ret = ret + to_string(root->val);
      if(root->children.size() > 0){
         ret += "[";
         for(Node* child : root->children){
            ret += n_ary_to_str(child) + ", ";
         }
         ret += "]";
      }
   }
   return ret;
}
class Codec {
public:
   vector<vector<int>>createVector(string s) {
      vector<vector<int>> ret;
      vector<int> tempv;
      string temp = "";
      for (size_t i = 0; i < s.size(); i++) {
         if (s[i] != ' ' && s[i] != '#') {
            temp += s[i];
         }
         else if (s[i] == ' ') {
            cerr << "found ' ' "<< "\n";
            cerr << stoi(temp) << "\n";
            tempv.push_back(stoi(temp));
            temp = "";
         }
         else if (s[i] == '#') {
            ret.push_back(tempv);
            temp = "";
            tempv.clear();
         }
      }
      for(size_t i = 0; i < ret.size(); ++i) {
            cerr << ret[i].size() << "\n";
      }
      while (!ret.empty() && ret.back().size() == 0)
      //std::cerr << "start popping back" << "\n";
      ret.pop_back();
      return ret;
   }
   string serialize(Node *root) {
      string ret = "";
      if (!root)
         return ret;
      queue<Node *> q;
      q.push(root);
      ret += to_string(root->val);
      ret += " ";
      ret += "#";
      while (!q.empty()) {
         Node *curr = q.front();
         q.pop();
         for (size_t i = 0; i < curr->children.size(); i++) {
            if (curr->children[i]) {
               ret += to_string(curr->children[i]->val);
               q.push(curr->children[i]);
            }
            ret += " ";
         }
         ret += "#";
      }
      return ret;
   }
   Node *deserialize(string data) {
      Node *ret;
      if (data.size() == 0) return nullptr;
      vector<vector<int>> v = createVector(data);
      //cerr << v.size() << "\n";
      ret = new Node(v[0][0]);
      queue<Node *> q;
      q.push(ret);
      size_t i = 1;
      while (!q.empty() && i < v.size()) {
        Node *curr = q.front();
        q.pop();
        for (size_t j = 0; j < v[i].size(); j++) {
            int node = v[i][j];
            Node *temp = new Node(node);
            curr->children.push_back(temp);
            q.push(temp);
        }
        i++;
      }
      return ret;
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
   Codec ob;
   Node n5(5), n6(6);
   Node n3(3); n3.children.push_back(&n5); n3.children.push_back(&n6);
   Node n2(2), n4(4);
   Node n1(1); n1.children.push_back(&n3); n1.children.push_back(&n2);
   n1.children.push_back(&n4);
   cout << "Given Tree: " << n_ary_to_str(&n1) << endl;
   string ser = ob.serialize(&n1);
   cout << "Serialize: " << ser << endl;
   Node *deser = ob.deserialize(ser);

   cout << "Deserialized Tree: " << n_ary_to_str(deser);
//     for (Node *child_ptr : deser->children) {
//        delete child_ptr;
//    }
   deleteNode(deser);
   //delete deser;
 }
