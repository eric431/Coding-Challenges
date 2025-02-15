/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/

class Solution {
public:
    pair<int, int> map_pos(pair<int, int> p, int n)
    {
        p.first = n - 1 - p.first;
        return {p.second, p.first};
    }

    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();

        int j_init {0};
        for(auto i{0}; i < n - 1; ++i)
        {
            for(auto j{j_init}; j < n - 1 - j_init; ++j)
            {
                auto p0 = make_pair(i, j);
                auto p1 = map_pos(p0, n);
                auto p2 = map_pos(p1, n);
                auto p3 = map_pos(p2, n);

                int tmp = matrix[p3.first][p3.second];
                matrix[p3.first][p3.second] = matrix[p2.first][p2.second];
                matrix[p2.first][p2.second] = matrix[p1.first][p1.second];
                matrix[p1.first][p1.second] = matrix[p0.first][p0.second];
                matrix[p0.first][p0.second] = tmp;
            }
            ++j_init;
        }
    }
};