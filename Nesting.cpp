// you can use includes, for example:
// #include <algorithm>
#include <stack> 
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(string &S) {
    // Implement your solution here
    stack<char> nested_stack;

    for (auto& el : S)
    {
        if(!nested_stack.empty())
        {
            char t = nested_stack.top();
            int check = (el - '0') - (t - '0');
            if(check == 1)
            {
                nested_stack.pop();
                continue;
            }
        }
        nested_stack.push(el);
    }

    if (nested_stack.empty())
    {
        return 1;
    }
    return 0;
}