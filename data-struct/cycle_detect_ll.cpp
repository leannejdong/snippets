#include <set>
#include <vector>
#include <cassert>


namespace {
struct Node {
   Node *next_ptr;
};
}


static bool hasCycle(Node *node_ptr)
{
    std::set<Node *> visited_node_set;

    while (node_ptr) {//if node_ptr is in the visited_node_set
        if (visited_node_set.count(node_ptr)) {
            return true;
        }

        visited_node_set.insert(node_ptr);
        node_ptr = node_ptr->next_ptr; // we makes node_ptr point to the next node
    }

    return false;
}


static void testWithAnEmptyList()
{
   Node *node_ptr = nullptr;
   assert(!hasCycle(node_ptr));
}


static void testWithNoCycle()
{
    std::vector<Node> nodes(3);
    nodes[0].next_ptr = &nodes[1];
    nodes[1].next_ptr = &nodes[2];
    nodes[2].next_ptr = nullptr;
    assert(!hasCycle(&nodes[0]));
}


static void testWithCycle()
{
   std::vector<Node> nodes(3);
   nodes[0].next_ptr = &nodes[1];
   nodes[1].next_ptr = &nodes[2];
   nodes[2].next_ptr = &nodes[0];
   assert(hasCycle(&nodes[0]));
}


int main()
{
    testWithAnEmptyList();
    testWithNoCycle();
    testWithCycle();
}
