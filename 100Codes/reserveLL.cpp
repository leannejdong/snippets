#include <iostream>
#include <fstream>

struct node
{
    node(int v, node* p):val(v), next(p){}   
    int val;
    node* next;  
    node(): val(0), next(nullptr) {}
    node(int x) : val(x), next(nullptr) {}
};

node* reverse( node* head )
{
    // Return a COPY of the list in REVERSE ORDER
    if(head==0 || head->next==0)
    {
        return head;
    }
    node* prev = head;
    head = head->next;
    prev->next = 0;
    while(head!=0){
        node* ne = head->next;
        head->next = prev;
        prev = head;
        head = ne;
    }
    return prev;
}

void free(node* head)
{
    while (head)
    {
        node* next = head->next;
        delete head;
        head = next;
    }
}

void print(node* head)
{
    while (head)
    {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

int main() 
{
    int i;
    node* head = nullptr;
    node* tail = nullptr;
    
    while (std::cin.good() && !std::cin.eof())
	{
		std::cin >> i;
        if (!std::cin.fail())
		{
           node* n = new node (i,nullptr);
           if (head==nullptr)
           {
                head = n;
                tail = n;
           }
           else
           {
                tail->next = n;
                tail = n;
           }
        }
    }
    
    node* copy = reverse(head);

    
 //   free(head);
    
    print(copy);
    
    free(copy);
    
    return 0;
}

// reversing a singlely linked list
// try to generalize to unique_ptr
// https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/
