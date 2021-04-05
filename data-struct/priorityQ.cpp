#include <queue>
#include <iostream>

using std::cerr;
using std::priority_queue;

template<typename T>
void showPriorityQ(priority_queue<T> q)
{
    while(!q.empty())
    {
        cerr << '\t' << q.top();
        q.pop();
    }
    cerr << '\n';
}

int main()
{
    priority_queue<int> q;
    q.push(4);
    q.push(3);
    q.push(5);
    q.push(1);

    cerr << "The queue is: \n" ;
    showPriorityQ(q);
    cerr << "The queue contains " << q.size() << " elements.\n";
    cerr << "The first element is " << q.top() << "\n";
    cerr << "q.pop() is ";
    q.pop();
    showPriorityQ(q);

    return 0;
}
//https://godbolt.org/z/b9h9da7Mf
