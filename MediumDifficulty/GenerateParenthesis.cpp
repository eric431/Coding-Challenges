/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8
*/

class Solution {
public:

    void addOpenBracket(int g_n, int lb_n, int rb_n, string str, vector<string>& vec, set<string>& cache)
    {
        if(lb_n < g_n)
        {
            str += '(';
            ++lb_n;

            generateParenthesisRecursive(g_n, lb_n, rb_n, str, vec, cache);
        }
    }

    void addCloseBracket(int g_n, int lb_n, int rb_n, string str, vector<string>& vec, set<string>& cache)
    {
        if(rb_n < lb_n && rb_n < g_n)
        {
            str += ')';
            ++rb_n;

            generateParenthesisRecursive(g_n, lb_n, rb_n, str, vec, cache);
        }
        else if(rb_n == lb_n && rb_n == g_n)
        {
            if(cache.count(str) == 0)
            {
                cache.insert(str);
                vec.emplace_back(move(str));
            }
        }
    }

    void generateParenthesisRecursive(int g_n, int lb_n, int rb_n, string& str, vector<string>& vec, set<string>& cache)
    {
        addOpenBracket(g_n, lb_n, rb_n, str, vec, cache);
        addCloseBracket(g_n, lb_n, rb_n, str, vec, cache);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> vec{};
        set<string> cache{};

        string str = "";
        int lb_n = 0, rb_n = 0;
        generateParenthesisRecursive(n, lb_n, rb_n, str, vec, cache);

        return vec;
    }
};