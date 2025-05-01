// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

// Example 1:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true
// Example 2:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true
// Example 3:


// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false
 

// Constraints:

// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase and uppercase English letters.
 

// Follow up: Could you use search pruning to make your solution faster with a larger board?

// Seen this question in a real interview before?
// 1/5
// Yes
// No

class Solution {
    public:
        vector<vector<char>> m_board;
        vector<vector<bool>> visited;
        int m;
        int n;
        int s;
        string searched_word;
        string ref_word;
    
        bool rcs_search(int i, int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || searched_word.size() > s || ref_word[i] != m_board[r][c])
                return false;
    
    
            searched_word += m_board[r][c];
            visited[r][c] = true;
            if (searched_word == ref_word) {
                return true;
            } else if (searched_word.size() > s) {
                searched_word.pop_back();
                visited[r][c] = false;
    
                return false;
            }
    
            if (r + 1 < m && !visited[r + 1][c] && rcs_search(i + 1, r + 1, c)) { 
                return true; 
            }
            if (r - 1 > -1 && !visited[r - 1][c] && rcs_search(i + 1, r - 1, c)) { 
                return true;
            }
            if (c + 1 < n && !visited[r][c + 1] && rcs_search(i + 1, r, c + 1)) { 
                return true; 
            }
            if (c - 1 > -1 && !visited[r][c - 1] && rcs_search(i + 1, r, c - 1)) { 
                return true; 
            }
    
            searched_word.pop_back();
            visited[r][c] = false;
    
            return false;
        }
    
        bool word_search() {
            for (auto i{0}; i < m; ++i) {
                for (auto j{0}; j < n; ++j) {
                    auto found = rcs_search(0, i, j);
    
                    if (found) return found;
                }
            }
    
            return false;
        }
    
        bool exist(vector<vector<char>>& board, string word) {
            m_board = board;
    
            m = board.size();
            n = board[0].size();
            s = word.size();
    
            ref_word = word;
    
            visited.resize(m, vector<bool>(n, false));
    
            return word_search();
        }
    };