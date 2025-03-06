// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

// Example 1:


// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]
// Example 2:


// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]
 

// Constraints:

// n == grid.length == grid[i].length
// 1 <= n <= 200
// 1 <= grid[i][j] <= 105


class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            map<vector<int>, int> row_f {}; // frequency of array occurrence
            map<vector<int>, int> col_f {}; // frequency of array occurrence
    
            vector<vector<int>> column_mat(grid.size());
    
            for(auto i{0}; i < grid.size(); ++i)
            {
                ++row_f[grid[i]];
                for(auto j{0}; j < grid[i].size(); ++j)
                {
                    column_mat[j].push_back(grid[i][j]);
                }
            }
    
            for(auto i{0}; i < column_mat.size(); ++i)
            {
                ++col_f[column_mat[i]];
            }
    
            int cnt{0};
    
            for(auto &[k, v] : row_f)
            {
                if(col_f.count(k)) cnt += (v * col_f[k]);
            }
    
            return cnt;
        }
    };