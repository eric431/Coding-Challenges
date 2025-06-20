/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
 

Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/

class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if(x == root[x])
        {
            return x;
        }
        return root[x] = find(root, root[x]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> root(isConnected.size());
        vector<int> rank(isConnected.size());
        
        // initialise root and rank
        for(int i{0}; i < isConnected.size(); ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
        
        auto union_set = [&](int x, int y)
        {
            int rootX = find(root, x);
            int rootY = find(root, y);
            if(rootX != rootY)
            {
                if(rank[rootX] > rank[rootY])
                {
                    root[rootY] = rootX;
                }
                else if(rank[rootX] < rank[rootY])
                {
                    root[rootX] = rootY;
                }
                else
                {
                    root[rootY] = rootX;
                    rank[rootX] += 1;
                }
            }
        };
            
        for(auto i{0}; i < isConnected.size(); ++i)
        {
            for(auto j{0}; j < isConnected.size(); ++j)
            {
                if(isConnected[i][j] == 1) union_set(i, j);
            }
        }
        
        unordered_set<int> provinces{};
        int capital{};
        for(auto el : root)
        {
            capital = find(root, el);
            provinces.insert(capital);
        }
        
        return provinces.size();
    }
};