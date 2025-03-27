// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

class Solution {
    public:
        vector<vector<int>> m_grid;
        vector<vector<int>> memo;
    
        int m, n;
    
        int bfs_path_traversal(pair<int, int> curr, pair<int, int> end)
        {
            if(memo[curr.first][curr.second] != -1) return memo[curr.first][curr.second];
    
            if(curr == end) return memo[curr.first][curr.second] = m_grid[curr.first][curr.second];
    
            int right = m_grid[curr.first][curr.second];
            int down = right;
    
            // move right
            if(curr.first + 1 < m)
            {
                auto new_curr = make_pair(curr.first + 1, curr.second);
                right += bfs_path_traversal(new_curr, end);
            }
    
            // move down
            if(curr.second + 1 < n)
            {
                auto new_curr = make_pair(curr.first, curr.second + 1);
                down += bfs_path_traversal(new_curr, end);
            }
    
            // cout << right << " " << left << endl;
            if(curr.second + 1 < n && curr.first + 1 < m)
            {
                return memo[curr.first][curr.second] = min(right, down);
            }
            else if(curr.first + 1 < m)
            {
                return memo[curr.first][curr.second] = right;
            }
            else
            {
                return memo[curr.first][curr.second] = down;
            }
        }
    
        int minPathSum(vector<vector<int>>& grid) {
            pair<int, int> start = {0, 0};
    
            m = grid.size();
            n = grid[0].size();
            pair<int, int> end = {m - 1, n - 1};
    
            this->m_grid = grid;
            this->memo.resize(m, vector<int>(n, -1));
    
            return bfs_path_traversal(start, end);
        }
    };