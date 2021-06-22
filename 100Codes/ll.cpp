#include <iostream>
#include <memory>

// Creating Node Structure
struct Node{
    int data;
    std::unique_ptr<Node> next;

    Node(int node_data) : data{node_data}, next{nullptr} {}
};

#if 0
// Create List structure
struct List{
    std::unique_ptr<Node> head;
    std::unique_ptr<Node> tail;

    List() : head{nullptr}, tail{nullptr}{}
};
#endif


// Function to insert a node at the beginning of linked list
/*std::unique_ptr<Node>*/ void insertBeg(std::unique_ptr<Node> llist, int data)
{
    auto newNode = std::make_unique<Node>(data); // create new node
        newNode->next = std::move(llist);
}

void deleteNode(std::unique_ptr<Node> node)
{
    while(node){
        auto newhead = std::move(node->next);
        node = std::move(newhead);
        std::cerr << "node deleted!";

    }
}
int main() {

    //std::unique_ptr<List> llist = std::make_unique<List>();
    std::unique_ptr<Node> head;
    insertBeg(std::move(head), 2);
    deleteNode(std::move(head));

}
// https://compiler-explorer.com/z/6335jPdYG
