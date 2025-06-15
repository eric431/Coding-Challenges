class Solution {
    public:
        vector<vector<int>> grid;
        int n;
        
        int min_paths(int s_r, int s_c){
            queue<vector<int>> bfs_q;
            bfs_q.push({s_r, s_c, 0});
            
            while(!bfs_q.empty()){
                auto v = bfs_q.front();
                int r = v[0];
                int c = v[1];
                int cnt = v[2];
    
                bfs_q.pop();
                
                if (r == (n - 1) && c == (n - 1)){
                    return cnt + 1;
                }
                
                for(auto r_i{r - 1 }; r_i <= r + 1; ++r_i){
                    for (auto c_i {c - 1}; c_i <= c + 1; ++c_i){
                        if (r_i == r && c_i == c) continue;
                        
                        if ((r_i > -1 && r_i < n) && (c_i > -1 && c_i < n) && (!grid[r_i][c_i])){
                            
                            bfs_q.push({r_i, c_i, cnt + 1});
                            grid[r_i][c_i] = 1;                            
                        }
                    }
                }
            }
            
            return -1;
            
        }
        
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            this->grid = grid;
            this->n = grid.size();
            
            if(grid[n - 1][n - 1] || grid[0][0]) return -1;
                    
            return min_paths(0, 0);
        }
    };