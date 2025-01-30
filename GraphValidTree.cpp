class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root, root[x]);
    }
    
    void unionSet(vector<int>& root, vector<int>& rank, int x, int y)
    {
        int rootX = find(root, x);
        int rootY = find(root, y);
        if(rootX != rootY){
            if(rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            } 
            else if (rank[rootX] < rank[rootY])
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
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> root(n);
        vector<int> rank(n);
        for(auto i{0}; i < n; ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
        
        vector<vector<int>> ds(n);
        for(auto i{0}; i < edges.size(); ++i)
        {
            ds[edges[i][0]].push_back(edges[i][1]);
            ds[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(auto i{0}; i < ds.size(); ++i)
            for(auto el : ds[i])
                unionSet(root, rank, i, el);
        
        unordered_set<int> roots{};
        for(auto i{0}; i < root.size(); ++i)
            roots.insert(find(root, root[i]));
        
        if(roots.size() > 1 || (roots.size() == 1 && edges.size() != n - 1)) return false;
                
        vector<bool> visited(n, false);        
        int r = *roots.begin();
        stack<int> dfs_s{};
        dfs_s.push(r);
        visited[r] = true;
        while(!dfs_s.empty())
        {
            int node = dfs_s.top();
            dfs_s.pop();
            
            for(auto el : ds[node])
            {
                if(!visited[el])
                {
                    dfs_s.push(el);
                    visited[el] = true;                    
                }
            }
        }
                
        bool result{true};
        for(auto el : visited)
            result &= el;
                
        return result;

    }
};