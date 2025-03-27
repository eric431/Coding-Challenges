// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

 

// Example 1:


// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1
// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
// Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.
// Example 2:


// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
// Output: 2
// Explanation: There is 1 exit in this maze at [1,2].
// [1,0] does not count as an exit since it is the entrance cell.
// Initially, you are at the entrance cell [1,0].
// - You can reach [1,2] by moving 2 steps right.
// Thus, the nearest exit is [1,2], which is 2 steps away.
// Example 3:


// Input: maze = [[".","+"]], entrance = [0,0]
// Output: -1
// Explanation: There are no exits in this maze.
 

// Constraints:

// maze.length == m
// maze[i].length == n
// 1 <= m, n <= 100
// maze[i][j] is either '.' or '+'.
// entrance.length == 2
// 0 <= entrancerow < m
// 0 <= entrancecol < n
// entrance will always be an empty cell.

class Solution {
    public:
        vector<vector<char>> maze_;
    
        int nearest_exit_bfs(vector<int>& cell)
        {
            int m = maze_.size();
            int n = maze_[0].size();
    
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<vector<int>> bfs_q;
    
            int r = cell[0];
            int c = cell[1];
            int s = 0;
    
            visited[r][c] = true;
    
            bfs_q.push({r, c, s});
    
            while(!bfs_q.empty())
            {
                auto curr = bfs_q.front();
                bfs_q.pop();
    
                r = curr[0];
                c = curr[1];
                s = curr[2];
    
                vector<int> curr_ = {r, c};
    
                if(r + 1 < m && !visited[r + 1][c] && maze_[r + 1][c] != '+')
                {
                    visited[r + 1][c] = true;
    
                    bfs_q.push({r + 1, c, s + 1});
                }
                else if(r + 1 == m && curr_ != cell) 
                    return s;
    
                if(r - 1 > -1 && !visited[r - 1][c] && maze_[r - 1][c] != '+')
                {
                    visited[r - 1][c] = true;
    
                    bfs_q.push({r - 1, c, s + 1});
                }
                else if(r - 1 == -1 && curr_ != cell)
                    return s;
    
                if(c + 1 < n && !visited[r][c + 1] && maze_[r][c + 1] != '+')
                {
                    visited[r][c + 1] = true;
    
                    bfs_q.push({r, c + 1, s + 1});
                }
                else if(c + 1 == n && curr_ != cell) 
                    return s;
    
                if(c - 1 > -1 && !visited[r][c - 1] && maze_[r][c - 1] != '+')
                {
                    visited[r][c - 1] = true;
    
                    bfs_q.push({r, c - 1, s + 1});
                }
                else if(c - 1 == -1 && curr_ != cell)
                    return s;
            }
    
            return -1;
        }
    
        int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            maze_ = maze;
            return nearest_exit_bfs(entrance);
        }
    };