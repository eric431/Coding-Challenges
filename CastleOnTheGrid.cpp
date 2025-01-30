/*
You are given a square grid with some cells open (.) and some blocked (X). Your playing piece can move along any row or column until it reaches the edge of the grid or a blocked cell. Given a grid, a start and a goal, determine the minmum number of moves to get to the goal.

Example.






The grid is shown below:

...
.X.
...
The starting position  so start in the top left corner. The goal is . The path is . It takes  moves to reach the goal.

Function Description
Complete the minimumMoves function in the editor.

minimumMoves has the following parameter(s):

string grid[n]: an array of strings that represent the rows of the grid
int startX: starting X coordinate
int startY: starting Y coordinate
int goalX: ending X coordinate
int goalY: ending Y coordinate
Returns

int: the minimum moves to reach the goal
Input Format

The first line contains an integer , the size of the array grid.
Each of the next  lines contains a string of length .
The last line contains four space-separated integers, 

Constraints

Sample Input

STDIN       FUNCTION
-----       --------
3           grid[] size n = 3
.X.         grid = ['.X.','.X.', '...']
.X.
...
0 0 0 2     startX = 0, startY = 0, goalX = 0, goalY = 2
Sample Output

3
Explanation

Here is a path that one could follow in order to reach the destination in  steps:

.
*/


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

using cell = pair<int, int>;

void update_queue(vector<string>& grid, vector<vector<int>>& path_cache, cell curr_cell, queue<cell>& q, set<cell>& v)
{
    if(curr_cell.first - 1 > -1 && grid[curr_cell.first - 1][curr_cell.second] != 'X')
    {
        cell north = make_pair(curr_cell.first - 1, curr_cell.second);
        if(!v.count(north)) q.push(north);
    }
    if(curr_cell.first + 1 < grid.size() && grid[curr_cell.first + 1][curr_cell.second] != 'X')
    {
        cell south = make_pair(curr_cell.first + 1, curr_cell.second);
        if(!v.count(south)) q.push(south);
    }
    if(curr_cell.second - 1 > -1 && grid[curr_cell.first][curr_cell.second - 1] != 'X')
    {
        cell west = make_pair(curr_cell.first, curr_cell.second - 1);
        if(!v.count(west)) q.push(west);
    }
    if(curr_cell.second + 1 < grid[0].size() && grid[curr_cell.first][curr_cell.second + 1] != 'X')
    {
        cell east = make_pair(curr_cell.first, curr_cell.second + 1);
        if(!v.count(east)) q.push(east);
    }
}

void castle_bfs(vector<string>& grid, vector<vector<int>>& path_cache, cell curr_, cell goal, queue<cell>& q, set<cell>& v)
{
    if(curr_ == goal) return;
    else if(v.count(curr_)) return;
    else if(grid[curr_.first][curr_.second] == 'X')
    {
        v.insert(curr_);
        return;
    }
    
    v.insert(curr_);
    update_queue(grid, path_cache, curr_, q, v);

    int n = path_cache[curr_.first][curr_.second] + 1;  

    // horizontal row movement
    for(int j{curr_.second}; j < grid[0].size(); ++j)
    {
        if(grid[curr_.first][j] == 'X') break;

        if(path_cache[curr_.first][j] == 0) path_cache[curr_.first][j] = n;
        else if(path_cache[curr_.first][j] > 0) path_cache[curr_.first][j] = min(path_cache[curr_.first][j], n);
    }
    for(int j{curr_.second}; j > -1; --j)
    {
        if(grid[curr_.first][j] == 'X') break;
        
        if(path_cache[curr_.first][j] == 0) path_cache[curr_.first][j] = n;
        else if(path_cache[curr_.first][j] > 0) path_cache[curr_.first][j] = min(path_cache[curr_.first][j], n);
    }

    // vertical column movement
    for(int i{curr_.first}; i < grid.size(); ++i)
    {
        if(grid[i][curr_.second] == 'X') break;
        
        if(path_cache[i][curr_.second] == 0) path_cache[i][curr_.second] = n;
        else if(path_cache[i][curr_.second] > 0) path_cache[i][curr_.second] = min(path_cache[i][curr_.second], n);
        
    }
    for(int i{curr_.first}; i > -1; --i)
    {
        if(grid[i][curr_.second] == 'X') break;
        
        if(path_cache[i][curr_.second] == 0) path_cache[i][curr_.second] = n;
        else if(path_cache[i][curr_.second] > 0) path_cache[i][curr_.second] = min(path_cache[i][curr_.second], n);
    }
}

void bfs_handler(vector<string>& grid, vector<vector<int>>& path_cache, int startX, int startY, int goalX, int goalY)
{
    queue<cell> q; // queue of cells to visit
    cell curr_cell = make_pair(startX, startY);
    cell goal = make_pair(goalX, goalY);
    set<cell> v{}; // visited cells 
    q.push(curr_cell);
    while(!q.empty())
    {
        cell curr = q.front();
        q.pop();
        castle_bfs(grid, path_cache, curr, goal, q, v);
    }
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    vector<vector<int>> path_cache(grid.size());
    for(auto i{0}; i < grid.size(); ++i)
    {
        for(auto j{0}; j < grid[0].size(); ++j)
        {
            if(grid[i][j] == 'X') path_cache[i].push_back(-2);
            else path_cache[i].push_back(0);
        }
    }
    
    bfs_handler(grid, path_cache, startX, startY, goalX, goalY);

    return path_cache[goalX][goalY];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

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
