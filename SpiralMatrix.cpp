/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/


class Solution {
public:
    void roll_right(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& spiral, int& r, int& i)
    {
        int n = matrix[r].size();

        ++i;
        for(; i < n && !visited[r][i]; ++i)
        {
            spiral.push_back(matrix[r][i]);
            visited[r][i] = true;
        }
        --i;

    }

    void roll_down(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& spiral, int& i, int c)
    {
        int n = matrix.size();

        ++i;
        for(; i < n && !visited[i][c]; ++i)
        {
            spiral.push_back(matrix[i][c]);
            visited[i][c] = true;
        }
        --i;
    }

    void roll_left(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& spiral, int& r, int& i)
    {
        --i;
        for(; i > -1 && !visited[r][i]; --i)
        {
            spiral.push_back(matrix[r][i]);
            visited[r][i] = true;
        }
        ++i;     
    }

    void roll_up(vector<vector<int>>& matrix, vector<vector<bool>>& visited, vector<int>& spiral, int& i, int c)
    {
        --i;
        for(; i > -1 && !visited[i][c]; --i)
        {
            spiral.push_back(matrix[i][c]);
            visited[i][c] = true;
        }
        ++i;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n_r = matrix[0].size();
        int n_c = matrix.size();
        vector<bool> rows(n_r, false);
        vector<vector<bool>> visited(n_c, rows);

        int r = 0;
        int c = 0;
        vector<int> spiral {matrix[r][c]};
        visited[r][c] = true;
        while(true)
        {
            roll_right(matrix, visited, spiral, r, c);

            roll_down(matrix, visited, spiral, r, c);

            roll_left(matrix, visited, spiral, r, c);

            roll_up(matrix, visited, spiral, r, c);

            if(n_r * n_c == spiral.size()) break;
        }


        return spiral;
    }
};