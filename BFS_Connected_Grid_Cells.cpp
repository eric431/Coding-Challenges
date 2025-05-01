/*
Consider a matrix where each cell contains either a  or a  and any cell containing a  is called a filled cell. Two cells are said to be connected if they are adjacent to each other horizontally, vertically, or diagonally. In the diagram below, the two colored regions show cells connected to the filled cells. Black on white are not connected.

Cells adjacent to filled cells: image

If one or more filled cells are also connected, they form a region. Note that each cell in a region is connected to at least one other cell in the region but is not necessarily directly connected to all the other cells in the region.

Regions: image

Given an  matrix, find and print the number of cells in the largest region in the matrix.

Function Description

Complete the function maxRegion in the editor below. It must return an integer value, the size of the largest region.

maxRegion has the following parameter(s):

grid: a two dimensional array of integers
Input Format

The first line contains an integer, , the number of rows in the matrix, .
The second line contains an integer, , the number of columns in the matrix.

Each of the following  lines contains a row of  space-separated integers, .

Constraints

Output Format

Print the number of cells in the largest region in the given matrix.

Sample Input

4
4
1 1 0 0
0 1 1 0
0 0 1 0
1 0 0 0
Sample Output

5
Explanation

The diagram below depicts two regions of the matrix:

image
The first region has five cells and the second region has one cell. We choose the larger region.
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxRegion' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY grid as parameter.
 */

int region_search(int r_, int c_, vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int, int>> bfs_q;
    bfs_q.push({r_, c_});
    
    grid[r_][c_] = 0;
    
    int cnt = 0;
    while(!bfs_q.empty()) {
        auto [r, c] = bfs_q.front();
        bfs_q.pop();
        
        ++cnt;
        
        for (auto c_i{c - 1}; c_i <= c + 1; ++c_i) {
            for(auto r_i {r - 1}; r_i <= r + 1; ++r_i) {
                if ((r_i > -1 && r_i < n) && (c_i > -1 && c_i < m)) {
                    if (grid[r_i][c_i]) {
                        bfs_q.push({r_i, c_i});
                        grid[r_i][c_i] = 0;
                    }
                }
            }            
        }
    }
    
    return cnt;
}

int maxRegion(vector<vector<int>> grid) {
    int max_cnt {0};
    
    for (auto r {0}; r < grid.size(); ++r) {
        for (auto c{0}; c < grid[r].size(); ++c) {
            if (grid[r][c]) {max_cnt = max(max_cnt, region_search(r, c, grid)); }
        }
    }
    
    return max_cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
