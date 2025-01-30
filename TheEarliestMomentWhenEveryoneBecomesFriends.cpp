class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if(x == root[x])
            return x;
        return root[x] = find(root, root[x]);
    }
    
    void union_set(vector<int>& root, vector<int>& rank, int x, int y)
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
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(), logs.end());
        
        vector<int> root(n);
        vector<int> rank(n);
        
        for(auto i{0}; i < n; ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
        
        for(auto log : logs)
        {
            union_set(root, rank, log[1], log[2]);
            root[0] = find(root, root[0]);
            for(auto i{1}; i < n; ++i)
            {
                root[i] = find(root, i);

                if(root[i] != root[i - 1]) break;
                else if(i == (n - 1) && root[i] == root[i - 1]) return log[0];
            }
        }
        
        return -1;
    }
};