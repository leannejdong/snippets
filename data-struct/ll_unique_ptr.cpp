#include <iostream>
#include <memory>
using namespace std;

// Creating Node Structure
struct Node{
    int data;
    std::unique_ptr<Node> next;

    Node(int node_data) : data{node_data}, next{nullptr} {}
};
// Create List structure
struct List{
    std::unique_ptr<Node> head;
    std::unique_ptr<Node> tail;

    List() : head{nullptr}, tail{nullptr}{}
};

// Function to insert a node at the beginning of linked list
std::unique_ptr<Node> insertBeg(std::unique_ptr<Node> llist, int data)
{
    auto newNode = std::make_unique<Node>(data); // create new node
        newNode = std::make_unique<Node>(data);
        newNode->next = std::move(llist);
        return newNode;
    //}
}

int main() {

    std::unique_ptr<List> llist = std::make_unique<List>();
    std::unique_ptr<Node> llist_head = insertBeg(std::move(llist->head), 2);
    llist->head = std::move(llist_head);

}
// https://compiler-explorer.com/z/YcK8jPj5e
