class Solution {
    public:
        vector<int> houses;
        vector<vector<int>> cost;
        vector<vector<vector<int>>> memo;
    
        int m;
        int n;
        int target;
        int tmp_cost = 0;
        int max_cost = 1000001;
        
        int create_neighborhood(int h, int n_target, int prev_color)
        {
            if (h == m && n_target == target) {
                return 0;
            } else if (h >= m || n_target > target) {
                return max_cost;
            } 
            
            if (memo[h][n_target - 1][prev_color] != -1) {
                return memo[h][n_target - 1][prev_color];
            }
            
            int min_cost = max_cost;
    
            if (!houses[h]) {
                for (auto i{0}; i < n; ++i) {
                    int new_n_cnt = n_target + (h > 0 && i + 1 != prev_color +  1);
                    min_cost = min(cost[h][i] + create_neighborhood(h + 1, new_n_cnt, i), min_cost);
                }
            } else if (houses[h]) {
                int new_n_cnt = n_target + (h > 0 && houses[h] != prev_color + 1);
                min_cost = create_neighborhood(h + 1, new_n_cnt, houses[h] - 1); 
            }
    
            return memo[h][n_target - 1][prev_color] = min_cost;
        }
        
        int minCost(vector<int>& houses, vector<vector<int>>& cost_i, int m, int n, int target) {
            this->houses = houses;
            this->cost = cost_i;
            this->m = m;
            this->n = n;
            this->target = target;
            
            memo.resize(m, vector<vector<int>>(m, vector<int>(n, -1)));
            
            int min_cost = create_neighborhood(0, 1, 0);
            
            return min_cost != max_cost ? min_cost : -1;
        }
    };