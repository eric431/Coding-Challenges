// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

// Example 1:


// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4
// Example 2:

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
// Example 3:

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            queue<vector<int>> bfs{};
    
            vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
            int i {0};
            int j {0};
            int num_oranges {0};
            int num_rotten {0};
            for(auto &r : grid)
            {
                j = 0;
                for(auto &c : r)
                {
                    if(c != 0) ++num_oranges;
    
                    if(c == 2)
                    {
                        ++num_rotten;
                        visited[i][j] = true;
                        bfs.push({i, j, 0});
                    }
                    ++j;
                }
                ++i;
            }        
    
            if (num_oranges > 0 && num_rotten == 0) return -1;
            else if(num_rotten == num_oranges) return 0;
    
            int total_time {0};
    
            int m = grid.size();
            int n = grid[0].size();
    
            while(!bfs.empty())
            {
                auto front = bfs.front();
                bfs.pop();
    
                int r = front[0];
                int c = front[1];
                int t = front[2];
    
                total_time = max(total_time, t);
    
                if(r + 1 < m && !visited[r + 1][c] && grid[r + 1][c] == 1)
                {
                    bfs.push({r + 1, c, t + 1});
                    visited[r + 1][c] = true;
                    ++num_rotten;
                }
    
                if(r - 1 > -1 && !visited[r - 1][c] && grid[r - 1][c] == 1)
                {
                    bfs.push({r - 1, c, t + 1});
                    visited[r - 1][c] = true;
                    ++num_rotten;
                }
    
                if(c + 1 < n && !visited[r][c + 1] && grid[r][c + 1] == 1)
                {
                    bfs.push({r, c + 1, t + 1});
                    visited[r][c + 1] = true;
                    ++num_rotten;
                }
    
                if(c - 1 > -1 && !visited[r][c - 1] && grid[r][c - 1] == 1)
                {
                    bfs.push({r, c - 1, t + 1});
                    visited[r][c - 1] = true;
                    ++num_rotten;
                }
            }
    
            if(num_rotten == num_oranges) return total_time;
    
            return -1;
        }
    };