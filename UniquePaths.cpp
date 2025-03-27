// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:


// Input: m = 3, n = 7
// Output: 28
// Example 2:

// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down
 

// Constraints:

// 1 <= m, n <= 100

class Solution {
    public:
        int m_;
        int n_;
    
        vector<vector<int>> memo;
    
        int unique_paths(int c_r, int c_c)
        {
            if (c_r == m_ && c_c == n_)
            {
                return 1;
            }
            else if(c_r > m_ || c_c > n_)
            {
                return 0;
            }
    
            if(memo[c_r][c_c] != -1) return memo[c_r][c_c];
    
            return memo[c_r][c_c] = unique_paths(c_r + 1, c_c) + unique_paths(c_r, c_c + 1);
        }
    
        int uniquePaths(int m, int n) {
            this->m_ = m - 1;
            this->n_ = n - 1;
    
            this->memo.resize(m, vector<int>(n, -1));
    
            return unique_paths(0, 0);
        }
    };