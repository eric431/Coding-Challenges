class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if(x == root[x])
            return x;
        return root[x] = find(root, root[x]);
    }
    
    void update_graph_rcs(vector<int>& root, vector<int>& rank, int old_root_well, int well_to_be_updated, int new_root)
    {
        int old_root = root[old_root_well];
        
        if(old_root == old_root_well)
            if(rank[old_root] > rank[well_to_be_updated])
                rank[old_root] = rank[well_to_be_updated];
        else
            update_graph_rcs(root, rank, old_root, old_root_well, new_root);
        
        root[well_to_be_updated] = new_root;
    }
    
    void union_set(vector<int>& root, vector<int>& rank, vector<int>& p)
    {
        int well_1 = p[0] - 1;
        int well_2 = p[1] - 1;
        int cost_of_pipe = p[2];
        
        int rootX = find(root, well_1);
        int rootY = find(root, well_2);
        if(rootX != rootY)
        {
            if(rank[rootX] < rank[rootY] && cost_of_pipe < rank[well_2])
            {
                int old_root_well = root[well_2];
                update_graph_rcs(root, rank, old_root_well, well_2, rootX);
                rank[well_2] = cost_of_pipe;
            }
            // else if(rank[rootY] < rank[rootX] && cost_of_pipe < rank[well_2])
            // {
            //     // int old_root_well = root[well_1];
            //     // update_graph_rcs(root, rank, old_root_well, well_1, rootY);
            //     // rank[well_1] = cost_of_pipe;
            //     if(rank[well_2] + cost_of_pipe > rank[well_1] + cost_of_pipe)
            //     {
            //         rank[well_2] = cost_of_pipe;
            //         root[well_1] = rootY;
            //     }
            // }
            else if(rank[rootY] < rank[rootX] && cost_of_pipe < rank[well_1])
            {
                int old_root_well = root[well_1];
                update_graph_rcs(root, rank, old_root_well, well_1, rootY);
                rank[well_1] = cost_of_pipe;
            }
            else if(rank[rootX] < rank[rootY] && cost_of_pipe < rank[well_1])
            {
                int old_root_well = root[well_1];
                update_graph_rcs(root, rank, old_root_well, well_1, rootX);
                rank[well_1] = cost_of_pipe;                
            }
            else if(cost_of_pipe < rank[well_2])
            {
                rank[well_2] = cost_of_pipe;
                root[well_2] = rootX;
            }
        }
    }
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {      
        vector<int> root(n);
        iota(root.begin(), root.end(), 0);
        
        vector<int> rank(n);
        for(auto i{0}; i < n; ++i) rank[i] = wells[i];
              
        for(auto &p : pipes) 
        {
            union_set(root, rank, p);
            for(auto &el : root) cout << el << " ";
            cout << endl;
        }
        
        int min_cost {0};
        for(auto el : rank) min_cost += el;
        
        return min_cost;
    }
};