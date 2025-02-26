/*
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

Example 1:


Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]
Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> diagonal_traversal{};
        
        int m = mat.size();
        int n = mat[0].size();
        
        if (m == 1)
        {
            for(auto el : mat[0])
                diagonal_traversal.push_back(el);
            
            return diagonal_traversal;
        }
        else if(n == 1)
        {
            for(auto el : mat)
                diagonal_traversal.push_back(el[0]);
            
            return diagonal_traversal;
        }
        
        int i {0};
        int j {0};
        
        int d1 {-1};
        int d2 {1};
        while(true)
        {
            diagonal_traversal.push_back(mat[i][j]);
            
            if(i == m - 1 && j == n - 1) break;
            
            if(!i || (j == n - 1))
            {
                if(j == n - 1) ++i;
                else ++j;
                
                diagonal_traversal.push_back(mat[i][j]);
                
                d1 *= -1;
                d2 *= -1;
            }
            else if(!j || (i == m - 1))
            {
                if(i == m - 1) ++j;
                else ++i;
                
                diagonal_traversal.push_back(mat[i][j]);
                
                d1 *= -1;
                d2 *= -1;
            }

            if(i == m - 1 && j == n - 1) break;
            
            i += d1;
            j += d2;
        }
        
        return diagonal_traversal;
    }
};