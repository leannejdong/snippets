#include <queue>
#include <iostream>

using std::cerr;
using std::queue;

template<typename T>
void showqueue(queue<T> q)
{
    while(!q.empty())
    {
        cerr << '\t' << q.front();
        q.pop();
    }
    cerr << '\n';
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(3);
    q.push(5);
    q.push(1);

    cerr << "The queue is: \n" ;
    showqueue(q);
    cerr << "The queue contains " << q.size() << " elements.\n";
    cerr << "The first element is " << q.front() << "\n";
    cerr << "The last element is " << q.back() << "\n";
    cerr << "q.pop() is ";
    q.pop();
    showqueue(q);

    return 0;
}
//https://godbolt.org/z/YWobcohbW
