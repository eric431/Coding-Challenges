// You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

// Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
// Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.

 

// Example 1:


// Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
// Output: 4
// Explanation: 
// In the beginning, you start at square 1 (at row 5, column 0).
// You decide to move to square 2 and must take the ladder to square 15.
// You then decide to move to square 17 and must take the snake to square 13.
// You then decide to move to square 14 and must take the ladder to square 35.
// You then decide to move to square 36, ending the game.
// This is the lowest possible number of moves to reach the last square, so return 4.
// Example 2:

// Input: board = [[-1,-1],[-1,3]]
// Output: 1
 

// Constraints:

// n == board.length == board[i].length
// 2 <= n <= 20
// board[i][j] is either -1 or in the range [1, n2].
// The squares labeled 1 and n2 are not the starting points of any snake or ladder.

class Solution {
    public:
        int n;
        int sentinel = numeric_limits<int>::max();
        vector<vector<int>> m_board;
    
        pair<int, int> convert_to_cell(int c) {
            int r = (n - 1 ) - ((c - 1) / n);
            int col;
    
            if (((c - 1) / n) % 2 == 0) {
                col = (c - 1) % n;
            } else {
                col = (n - 1) - (c - 1) % n;
            }
    
            return {r, col};
        }
    
        int board_traversal (vector<int>& p){
            vector<int> visited(n * n, sentinel);
            priority_queue<vector<int>> bfs;
            bfs.push({p[0], p[1]});
    
            bool game_finished = false;
    
            int min_rolls = numeric_limits<int>::max();
            while(!bfs.empty()) {
                auto c = bfs.top();
                bfs.pop();
    
                if (c[0] == n * n) {
                    auto [r_n, c_n] = convert_to_cell(c[0]);
                    game_finished = true;
                    min_rolls = min(min_rolls, c[1]);
                    visited[n * n - 1] = min_rolls;
                    continue;
                }
    
                // choose next
                // roll dice
                for (auto i{1}; i <= 6; ++i) {
                    auto next = c[0] + i;
                    auto [r_n, c_n] = convert_to_cell(next);
                    auto next_pos = m_board[r_n][c_n];
    
                    if (next_pos != -1 && c[1] + 1 < visited[next_pos - 1]) {
                        bfs.push({m_board[r_n][c_n], c[1] + 1});
                        visited[next_pos - 1] = c[1] + 1;
                    } else if (next_pos == -1 && c[1] + 1 < visited[c[0] + i - 1]) {
                        bfs.push({c[0] + i, c[1] + 1});
                        visited[c[0] + i - 1] = c[1] + 1;
                    }
    
                    if (c[0] + i == n * n) break;
                }
            }
    
            if (!game_finished) return -1;
    
            return min_rolls;
        }
    
        int snakesAndLadders(vector<vector<int>>& board) {
            m_board = board;
            n = board.size();
    
            vector<int> p = {1, 0};
            auto min_rolls = board_traversal(p);
    
            return min_rolls;
        }
    };