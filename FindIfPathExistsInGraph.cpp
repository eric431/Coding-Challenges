/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

 

Example 1:


Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
Example 2:


Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.
 

Constraints:

1 <= n <= 2 * 105
0 <= edges.length <= 2 * 105
edges[i].length == 2
0 <= ui, vi <= n - 1
ui != vi
0 <= source, destination <= n - 1
There are no duplicate edges.
There are no self edges.
*/

class Solution {
public:
    bool dfs(vector<bool>& visited, vector<set<int>>& adj, int source, int destination)
    {
        stack<int> dfs_stack{};
        dfs_stack.push(source);
        
        while(!dfs_stack.empty())
        {
            auto t = dfs_stack.top();
            dfs_stack.pop();
            visited[t] = true;
            
            for(auto el : adj[t])
            {
                if(el == destination) return true;
                else if(!visited[el])
                {
                    dfs_stack.push(el);
                    continue;
                }
            }
        }
        
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        
        vector<bool> visited(n, false);
        vector<set<int>> adj(n);
        
        // initialise adjacency list
        for(auto& e : edges)
        {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        
        
        return dfs(visited, adj, source, destination);
    }
};