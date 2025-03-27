// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// You must do it in place.

 

// Example 1:


// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:


// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -231 <= matrix[i][j] <= 231 - 1

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            unordered_set<int> zero_rows {};
            unordered_set<int> zero_cols {};
    
            int m = matrix.size();
            int n = matrix[0].size();
    
            for( auto i{0}; i < m; ++i){
                for (auto j{0}; j < n; ++j){
                    if (matrix[i][j] == 0) {
                        zero_rows.insert(i);
                        zero_cols.insert(j);
                    }
                }
            }
    
            for(auto &r : zero_rows){
                for(auto c{0}; c < matrix[r].size(); ++c){
                    matrix[r][c] = 0;
                }
            }
    
            for(auto &c : zero_cols){
                for(auto r{0}; r < matrix.size(); ++r){
                    matrix[r][c] = 0;
                }
            }        
        }
    };