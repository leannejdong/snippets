// N voracious fish are moving along a river. Calculate how many fish are alive.

/* Strategy
Keep a stack s that represent the fish we've processes so far
(nb these fish can still be eaten by a larger fish flowinh upstream)
It also helps to see that the end of the process, there are only 3 
possibilities: either all fish are flowing downstream, all fish are flowing
upstream, some fish are flowing upstream which are followed by fish flowing
downstream. Fish flowing downstream followed by fish flowing upstream is not possible since
when they meet, the larger will eat the smaller fish. So we come up with the 
following

For every fish f
    if there is no fish on the stack, push f to s
    otherwise
        if f is going upstream, pop off fish from s, as long as f eat the fish
        from the top of s.
        if the stack is empty, push f to the top of s
        (the cnt increase when stack is empty)
By the end of this process, we are left with a stack of fish that survives, so the size 
of the stack is what we want
*/
#include <stack>
#include <vector>
#include <cassert>
#include <iostream>

using std::vector;
using std::stack;

int soln(vector<int>&A, vector<int>&B)
{
    const size_t size = A.size();
    stack<int> s;
    int cnt = 0;
    for (size_t i = 0; i < size; i++)
    {
        if(B[i])
        {
            s.push(A[i]);
        } else {
            while (s.size() != 0) {
                if (A[i] > s.top())
                {
                    s.pop();
                } else {
                    break;
                }
            }
            if (s.size() == 0) {
                cnt++;
            }
        }
    }
    return cnt + s.size();
}

int main()
{
    vector<int> A = {4, 3, 2, 1, 5};
    vector<int> B = {0, 1, 0, 0, 0};
    assert(soln(A, B) == 2);
    std::cerr << soln(A, B) << "\n";
}

/* 1. use the properties of the stack, FILO, pop when it is eaten
   2. use stack to store fishes. The count increase when the stack is empty */ 


