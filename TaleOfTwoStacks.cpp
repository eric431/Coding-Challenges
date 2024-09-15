// HACKERRANK

// A queue is an abstract data type that maintains the order in which elements were added to it, allowing the oldest elements to be removed from the front and new elements to be added to the rear. This is called a First-In-First-Out (FIFO) data structure because the first element added to the queue (i.e., the one that has been waiting the longest) is always the first one to be removed.

// A basic queue has the following operations:

// Enqueue: add a new element to the end of the queue.
// Dequeue: remove the element from the front of the queue and return it.
// In this challenge, you must first implement a queue using two stacks. Then process  queries, where each query is one of the following  types:

// 1 x: Enqueue element  into the end of the queue.
// 2: Dequeue the element at the front of the queue.
// 3: Print the element at the front of the queue.
// For example, a series of queries might be as follows:

// image

// Function Description

// Complete the put, pop, and peek methods in the editor below. They must perform the actions as described above.

// Input Format

// The first line contains a single integer, , the number of queries.

// Each of the next  lines contains a single query in the form described in the problem statement above. All queries start with an integer denoting the query , but only query  is followed by an additional space-separated value, , denoting the value to be enqueued.

// Constraints

// It is guaranteed that a valid answer always exists for each query of types  and .
// Output Format

// For each query of type , return the value of the element at the front of the fifo queue on a new line.

// Sample Input

// 10
// 1 42
// 2
// 1 14
// 3
// 1 28
// 3
// 1 60
// 1 78
// 2
// 2
// Sample Output

// 14
// 14
// Explanation

// image


// SOLUTION

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
    public:
        void push(int x) {
            if(stack_newest_on_top.empty() && !stack_oldest_on_top.empty())
            {
                // reverse oldest stack but keep oldest stack
                pf_update(stack_oldest_on_top, stack_newest_on_top);
            }
            stack_newest_on_top.push(x);
        }
        void pop() {
            pop_cnt++;
            if(stack_oldest_on_top.empty() && !stack_newest_on_top.empty())
            {
                // if the oldest stack is empty and the newest one is not then reverse the new stack to get the oldest on top
                p_update(stack_newest_on_top, stack_oldest_on_top);
            }
            else if(!stack_oldest_on_top.empty())
            {
                stack_oldest_on_top.pop();
            }
        }
        int front() {
            if(stack_oldest_on_top.empty() && !stack_newest_on_top.empty())
            {
                pf_update(stack_newest_on_top, stack_oldest_on_top);
            }
            return stack_oldest_on_top.top();
        }
    private:
        stack<int> stack_newest_on_top, stack_oldest_on_top;
        int pop_cnt = 0;
        // pop update
        void p_update(stack<int>& a, stack<int>& b)
        {
            while(!a.empty() && a.size() > pop_cnt)
            {
                auto top = a.top();
                b.push(top);
                a.pop();
            }
            stack<int>().swap(a);
            pop_cnt = 0;         
        }
        // push front update
        void pf_update(stack<int>& a, stack<int>& b)
        {
            auto a_tmp = a;
            while(!a_tmp.empty() && a_tmp.size() > pop_cnt)
            {
                auto top = a_tmp.top();
                b.push(top);
                a_tmp.pop();
            }
            pop_cnt = 0;   
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    // for(int i = 0; i < q; i++) {
    //     cin >> type;
    //     if(type == 1) {
    //         cin >> x;
    //         q1.push(x);
    //     }
    //     else if(type == 2) {
    //         q1.pop();
    //     }
    //     else cout << q1.front() << endl;
    // }

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> op_codes;
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else 
        {
            op_codes.push_back(type);
        }
    }     
    
    for(int i = 0; i < op_codes.size(); i++)
    {
        if(op_codes[i] == 2)
        {
            q1.pop();
        }
        else if (op_codes[i] == 3) {
            cout << q1.front() << endl;
        }
    }
    
    return 0;
}
