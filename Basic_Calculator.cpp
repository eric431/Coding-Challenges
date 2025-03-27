// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "1 + 1"
// Output: 2
// Example 2:

// Input: s = " 2-1 + 2 "
// Output: 3
// Example 3:

// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

class Solution {
    public:
        int evaluate(stack<string>& stk){
            int rst {0};
            while(!stk.empty()){
                auto t = stk.top();
                stk.pop();
    
                if (t == ")") { 
                    rst += evaluate(stk);
                }
                else if (t == "(") {
                    if (!stk.empty() && stk.top() == "-")
                    {
                        rst *= -1;
                        stk.pop();
    
                        return rst;
                    }
                    else return rst;
                }
                else if (t == "+") ;
                else if (t == "-") rst *= -1;
                else {
                    if (!stk.empty() && stk.top() == "-"){
                        rst += -1 * stoi(t);
                        stk.pop();
                    }
                    else
                        rst += stoi(t);
                }
            }
    
            return rst;
        }
    
        int calculate(string s) {
            stack<string> stk {};
    
            auto extract_digit = [&](int& i, int &j, string& s, stack<string>& stk){
                i = j;
    
                while (s[j] >= '0' && s[j] <= '9'){ ++j; }
    
                auto num = s.substr(i, j - i);
                stk.push(num);
    
                --j;
            };
    
            int i {0};
            int j {0};
            for (; j < s.size(); ++j){
                if (s[j] >= '0' && s[j] <= '9'){ extract_digit(i, j, s, stk); }
                else if (s[j] == '+' || s[j] == '-' || s[j] == '(' || s[j] == ')'){
                    string el = "";
                    el += s[j];
                    stk.push(el);
                }
            }
    
            return evaluate(stk);
        }
    };