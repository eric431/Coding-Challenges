// There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by an n x k cost matrix costs.

// For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
// Return the minimum cost to paint all houses.

 

// Example 1:

// Input: costs = [[1,5,3],[2,9,4]]
// Output: 5
// Explanation:
// Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
// Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.
// Example 2:

// Input: costs = [[1,3],[2,4]]
// Output: 5
 

// Constraints:

// costs.length == n
// costs[i].length == k
// 1 <= n <= 100
// 2 <= k <= 20
// 1 <= costs[i][j] <= 20
 

// Follow up: Could you solve it in O(nk) runtime?

class Solution {
    public:
        int size;
        int k;
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
            for(auto i{0}; i < k; ++i)
            {
                if(c != i){
                    local_min_cost = min(local_min_cost, costs_[h][i] + min_cost_rcs(h + 1, i));    
                }
            }
    
            return memo[h][c] = local_min_cost;
        }    
        
        int minCostII(vector<vector<int>>& costs) {
            this->size = costs.size();
            this->k = costs[0].size();
            this->costs_ = costs;
    
            this->memo.resize(size, vector<int>(k, -1));
    
            int min_cost = numeric_limits<int>::max();
            for(auto i{0}; i < k; ++i)
            {
                min_cost = min(min_cost, costs[0][i] + min_cost_rcs(1, i));
            }
    
            return min_cost;
        }
    };