class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if(x == root[x])
            return x;
        return root[x] = find(root, root[x]);
    }
    
    void UnionSet(vector<int>& root, vector<int>& rank, int x, int y)
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
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        vector<int> rank(n);
        for(auto i{0}; i < n; ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
        
        for(auto i{0}; i < edges.size(); ++i)
            UnionSet(root, rank, edges[i][0], edges[i][1]);
        
        unordered_set<int> roots{};
        for(auto el : root)
        {
            auto rootX = find(root, el);
            roots.insert(rootX);
        }
        
        return roots.size();
    }
};