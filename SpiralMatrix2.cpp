/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/

class Solution {
public:
    void roll_right(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int& c, int& itr)
    {
        int n = matrix.size();

        ++c;
        for(; c < n && !visited[r][c]; ++c)
        {
            ++itr;
            matrix[r][c] = itr;
            visited[r][c] = true;
        }
        --c;
    }

    void roll_left(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int& c, int& itr)
    {
        int n = matrix.size();

        --c;
        for(; c > -1 && !visited[r][c]; --c)
        {
            ++itr;
            matrix[r][c] = itr;
            visited[r][c] = true;
        }
        ++c;
    }

    void roll_down(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int& r, int c, int& itr)
    {
        int n = matrix.size();

        ++r;
        for(; r < n && !visited[r][c]; ++r)
        {
            ++itr;
            matrix[r][c] = itr;
            visited[r][c] = true;
        }
        --r;
    }

    void roll_up(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int& r, int c, int& itr)
    {
        int n = matrix.size();

        --r;
        for(; r > -1 && !visited[r][c]; --r)
        {
            ++itr;
            matrix[r][c] = itr;
            visited[r][c] = true;
        }
        ++r;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<int> rows_i(n, 0);
        vector<bool> rows_b(n, false);
        vector<vector<int>> matrix(n, rows_i);
        vector<vector<bool>> visited(n, rows_b);

        int r {0};
        int c {0};
        int itr {1};
        matrix[r][c] = itr;
        visited[r][c] = true;
        while(true)
        {
            roll_right(matrix, visited, r, c, itr);

            roll_down(matrix, visited, r, c, itr);

            roll_left(matrix, visited, r, c, itr);

            roll_up(matrix, visited, r, c, itr);

            if(itr >= n * n) break;
        }

        return matrix;
    }
};