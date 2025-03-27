// There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

// For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
// Return the minimum cost to paint all houses.

 

// Example 1:

// Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
// Output: 10
// Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
// Minimum cost: 2 + 5 + 3 = 10.
// Example 2:

// Input: costs = [[7,6,2]]
// Output: 2
 

// Constraints:

// costs.length == n
// costs[i].length == 3
// 1 <= n <= 100
// 1 <= costs[i][j] <= 20


class Solution {
    public:
        int size;
        vector<vector<int>> costs_;
        vector<vector<int>> memo;
    
        
        int min_cost_rcs(int h, int c)
        {
            if (h >= size){
                return 0;
            }
            
            if(memo[h][c] != -1) return memo[h][c];
            
            int local_min_cost = numeric_limits<int>::max();
            int min_ = local_min_cost;
            for(auto i{0}; i < 3; ++i)
            {
                if(c != i){
                    local_min_cost = min(local_min_cost, costs_[h][i] + min_cost_rcs(h + 1, i));    
                }
            }
            
            return memo[h][c] = local_min_cost;
    
        }
        
        int minCost(vector<vector<int>>& costs) {
            this->size = costs.size();
            this->costs_ = costs;
            
            this->memo.resize(size, vector<int>(3, -1));
            
            int min_cost = numeric_limits<int>::max();
            for(auto i{0}; i < 3; ++i)
            {
                min_cost = min(min_cost, costs[0][i] + min_cost_rcs(1, i));
            }
            
            return min_cost;
        }
    };