/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rows(matrix[0].size());
        vector<vector<int>> dp(n, rows); 
        
        int max_square{0};
        for(auto i{0}; i < n; ++i)
        {
            for(auto j{0}; j < m; ++j)
            {
                if(matrix[i][j] == '0') continue;
                
                if(i == 0 || j == 0)
                {
                    if(i == 0 && j == 0) dp[i][j] = 1;
                    else if(i == 0) dp[i][j] = 1;
                    else if(j == 0) dp[i][j] = 1;
                }
                else
                {
                    if(dp[i - 1][j] && dp[i - 1][j - 1] && dp[i][j - 1])
                    {
                        int root = sqrt(min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]})) + 1;
                        dp[i][j] = root * root;
                    }
                    else dp[i][j] = 1;
                }
                
                max_square = max(dp[i][j], max_square);
            }
        }
        return max_square;
    }
};