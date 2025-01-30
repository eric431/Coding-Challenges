/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

Note: The variables that do not occur in the list of equations are undefined, so the answer cannot be determined for them.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
note: x is undefined => -1.0
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
Example 3:

Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
 

Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj consist of lower case English letters and digits.
*/

class Solution {
public:
    using edge = pair<string, string>;
    double dfs(map<string, vector<string>>& roots, string node, string end_node, map<edge, double>& multiplier)
    {
        using string_mult = pair<double, string>;
        stack<string_mult> dfs_stack{};
        for(auto el : roots[node])
        {
            edge e = make_pair(node, el);
            
            double m = multiplier[e];
            dfs_stack.push(make_pair(m, el));
        }
        
        unordered_set<string> visited{};
        while(!dfs_stack.empty())
        {
            auto top = dfs_stack.top();
            dfs_stack.pop();
            
            visited.insert(top.second);
            for(auto nodes_ : roots[top.second])
            {
                if(nodes_ == end_node)
                {
                    edge e = make_pair(top.second, end_node);
                    return top.first * multiplier[e];
                }
                else if(!visited.count(nodes_))
                {
                    edge e = make_pair(top.second, nodes_);
                    double new_m = top.first * multiplier[e];
                    
                    edge k = make_pair(node, nodes_);
                    multiplier[k] = new_m;
                    
                    edge inv_k = make_pair(nodes_, node);
                    multiplier[inv_k] = 1.0 / new_m;
                    
                    string_mult new_node = make_pair(new_m, nodes_);
                    dfs_stack.push(new_node);
                }
                
                visited.insert(nodes_);
            }
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, string> root{};
        map<string, vector<string>> roots{};
        map<string, int> rank{};
        map<edge, double> multiplier{};
        for(auto i{0}; i < equations.size(); ++i)
        {
            auto v = equations[i];
            
            roots[v[0]].push_back(v[1]);
            roots[v[1]].push_back(v[0]);
                        
            edge key = make_pair(v[0], v[1]);
            multiplier[key] = values[i];
            
            edge inv_key = make_pair(v[1], v[0]);
            multiplier[inv_key] = 1.0 / values[i];
        }
        
        vector<double> results{};
        for(auto& q : queries)
        {
            edge key = make_pair(q[0], q[1]);
            edge inv_key = make_pair(q[1], q[0]);

            double ans{};
            if(multiplier.count(key)) 
                ans = multiplier[key];
            else 
            {
                ans = dfs(roots, q[0], q[1], multiplier);
                multiplier[key] = ans;

                edge inv_key = make_pair(q[1], q[0]);
                multiplier[inv_key] = 1.0 / ans;
            }
            results.push_back(ans);
        }
        
        return results;
    }
};