/*
A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
*/
#include <string>
#include <cassert>
#include <iostream>
#include <stack>

using std::stack;
using std::string;

bool validate(stack<char> &s, char input)
{
    if (input == '{' || input == '(' || input =='[')
    {
        s.push(input);
        return true;  
    }
    else {
    // store the top element in c
        char c = s.top();
        if ((c == '{' && input == '}') ||
            (c == '(' && input == ')') ||
            (c == '[' && input == ']')){
            s.pop();
            return true;
        }
    }
    return false;
}

int soln(string &S)
{
    size_t size = S.size();// avoid cast by using type size_t for the size variable instead of using int
    stack<char> tmp;

    for(size_t i = 0; i < size; ++i)
    {
        bool validate_result = validate(tmp, S[i]);
        std::cerr << "validate_result=" << validate_result << "\n";
        if(!validate_result)
        {
            std::cout << "invalid!" << "\n";
            return false;
        }
    }
  //  std::cerr << S << "\n";
  //  std::cerr << size << "\n";
    return tmp.size() == 0;
}


int main()
{
    string string1 = "[{{()}]";
    std::cerr << soln(string1) << "\n";
}
