// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100

class Solution {
    public:
        vector<vector<int>> grid;
        vector<vector<int>> memo;
        int n;
        
        int min_fall_sum(int r, int c)
        {
            if(r >= n) return 0;
            else if(c < 0 || c >= n) return numeric_limits<int>::max();
            
            if(memo[r][c] !=  numeric_limits<int>::max()) return memo[r][c];    
                    
            return memo[r][c] = grid[r][c] + min({min_fall_sum(r + 1, c - 1), min_fall_sum(r + 1, c), min_fall_sum(r + 1, c + 1)});
        }
        
        int minFallingPathSum(vector<vector<int>>& matrix) {
            this->grid = matrix;
            this->n = matrix.size();
            
            int int_max = numeric_limits<int>::max();
            this->memo.resize(n, vector<int>(n, int_max));
            
            int min_path_sum = numeric_limits<int>::max();
            for(auto i{0}; i < n; ++i)
            {
                min_path_sum = min(min_path_sum, min_fall_sum(0, i));
            }
            
            return min_path_sum;
        }
    };