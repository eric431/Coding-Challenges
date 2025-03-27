// Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

// Example 1:

// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".
// Example 2:

// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".
// Example 3:

// Input: s = ""
// Output: 0
 

// Constraints:

// 0 <= s.length <= 3 * 104
// s[i] is '(', or ')'.

class Solution {
    public:
        int longestValidParentheses(string s) {
            stack<int> stack;
    
            stack.push(-1);
            int max_len{0};
            for(auto i{0}; i < s.size(); ++i)
            {
                if(s[i] == '(')
                {
                    stack.push(i);
                }
                else
                {
                    stack.pop();
                    if(stack.empty()) stack.push(i);
                    else max_len = max(i - stack.top(), max_len);
                }
            }
    
            return max_len;
        }
    };