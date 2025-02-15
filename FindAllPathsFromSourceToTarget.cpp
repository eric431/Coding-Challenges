/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Example 2:


Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
 

Constraints:

n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i (i.e., there will be no self-loops).
All the elements of graph[i] are unique.
The input graph is guaranteed to be a DAG.
*/

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths{};
        
        stack<vector<int>> dfs_stack{};
        set<vector<int>> visited;
        
        vector<int> path{};
        
        path.push_back(0);
        dfs_stack.push(path);
        while(!dfs_stack.empty())
        {
            auto top = dfs_stack.top();
            dfs_stack.pop();

            if(visited.contains(top)) continue;

            if(top.back() == graph.size() - 1)
            {
                visited.insert(top);

                paths.push_back(top);
                continue;
            }

            for(auto el : graph[top.back()])
            {
                auto tmp = top;
                tmp.push_back(el);
                dfs_stack.push(tmp);
            }
        }
        
        return paths;
    }
};