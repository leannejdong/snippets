#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
//.NET
// class HierarchyMember
// {
//     public string Name { get; set; }
//     public List<HierarchyMember> Children { get; set; }
// }

///in header file
class Node
{
    public:
        Node(const string &name, const vector<Node> &children)
        : name(name), children(children)
        {

        }
         const string& getName() const;
         void setName(const string& newName);
         vector<Node> children;
    private:
         string name;
};

//in source file

const string&Node::getName() const
{
     return name;
}

void Node::setName(const string& newName)
{
      name = newName;
}

static void printRoot(const Node &root)
{
    if (root.children.size() == 0) {
        std::cout << root.getName() << "\n";
    } else if(root.children.size() > 0) {
        for (const auto &child : root.children)
        {
             std::cout << child.getName() << "\n";
        }
    }
}

int main()
{
    Node root0{"root", {}};
    printRoot(root0);
    Node root1{"root",{{"child1",{}},{"child2",{}}}};
    printRoot(root1);

// https://stackoverflow.com/questions/46680634/compiler-error-passing-const-something-as-this-argument-discards-qualifier/46680705

}

