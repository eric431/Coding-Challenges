// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

 

// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

class Solution {
    public:
        vector<pair<int, int>> cells_to_visit {};
        vector<vector<char>> m_board {};
        int n;
        int **cols;
        int **rows;
        int **boxes;
        bool solved = false;
    
        bool check_validity(int i, int j, int num)
        {
            int idx = (i / 3) * 3 + j / 3;
            return (rows[i][num] + cols[j][num] + boxes[idx][num]) == 0;
        }
    
        void update_ds(int i, int j, int num)
        {
            int idx = (i / 3) * 3 + j / 3;
            ++rows[i][num];
            ++cols[j][num];
            ++boxes[idx][num];
            m_board[i][j] = num + '0';
        }
    
        void backtrack_ds(int i, int j, int num)
        {
            int idx = (i / 3) * 3 + j / 3;
            --rows[i][num];
            --cols[j][num];
            --boxes[idx][num];
            m_board[i][j] = '.';
        }
    
        void sudoku_solver (int i)
        {
            for (auto c {1}; c < 10; ++c)
            {
                auto cell = cells_to_visit[i];
    
                if (check_validity(cell.first, cell.second, c))
                {
                    update_ds(cell.first, cell.second, c);
    
                    if (i + 1 == cells_to_visit.size())
                    {
                        solved = true;
                        return;
                    }
                    else if (i + 1 < cells_to_visit.size()) sudoku_solver(i + 1);
    
                    if(!solved) 
                    {
                        backtrack_ds(cell.first, cell.second, c);
                    }
                }
            }
            return;
        }
    
        void solveSudoku(vector<vector<char>>& board) {
            m_board = board;
    
            rows = new int *[9];
            cols = new int *[9];
            boxes = new int *[9];
    
            n = board.size();
            for(auto i {0}; i < 9; ++i) 
            {
                cols[i] = new int[10]();
                rows[i] = new int[10]();
                boxes[i] = new int[10]();
            }
    
            for(auto i {0}; i < n; ++i)
            {
                for(auto j {0}; j < n; ++j)
                {
                    char num = m_board[i][j];
    
                    if (num == '.') cells_to_visit.push_back(make_pair(i, j));
                    else update_ds(i, j, num - '0');
                }
            }
    
            bool solved = false;
            sudoku_solver(0);
    
            board = m_board;
        }
    };