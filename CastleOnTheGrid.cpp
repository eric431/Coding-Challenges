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

struct pos
{
    int X;
    int Y;
};

struct m_hist
{
    pos prev, curr;
    bool x_move, y_move;
    int cnt;
    set<pair<int, int>> path

    
    m_hist(pos prev, pos curr) : prev(prev), curr(curr)
    {
        x_move = abs(curr.X - prev.X) > 0;
        y_move = abs(curr.Y - prev.Y) > 0;
    }
};

// void DFS_move(set<set<pair<int, int>>>& visited_paths, map<set<pair<int, int>>, int>& cache, 
// vector<string>& grid, m_hist m, pos goal, int cnt, set<pair<int, int>> path, stack<m_hist>& to_be_visited)
void DFS_move(set<m_hist>& visited_paths, map<set<pair<int, int>>, int>& cache, 
vector<string>& grid, m_hist m, pos goal, stack<m_hist>& to_be_visited)
{
    cout << "( " << m.curr.X << " , " << m.curr.Y << " )" << endl;
    if(visited_paths.count(m) > 0) 
    {
        return;
    }
    else 
    {
        // visited_paths.insert(path);
        visited_paths.insert(m);
    }
    
    if (grid[m.curr.X][m.curr.Y] == 'X')
    {
        cache[m.path] = numeric_limits<int>::max();
        return;
    }
    
    if(m.curr.X == goal.X && m.curr.Y == goal.Y)
    {
        // cout << cnt << endl;
        // visited_paths.insert(m);
        cache[m.path] = m.cnt;
        return;
    }

    if(m.curr.X < (int)grid[0].size() - 1)
    {
        pos right_i;
        right_i.X = m.curr.X + 1;
        right_i.Y = m.curr.Y;   
        m_hist move_right(m.curr, right_i);
        auto cnt_r = m.cnt;
        if(m.x_move != move_right.x_move && m.y_move != move_right.y_move || m.x_move == false && m.y_move == false)
        {
            ++cnt_r;
            // cout << "73: " << cnt_r << endl;
            m.path.insert(make_pair(right_i.X, right_i.Y));
        }
        move_right.cnt = cnt_r;
        move_right.path = m.path;
        // DFS_move(visited_paths, cache, grid, move_right, goal, cnt_r, path); 
        to_be_visited.push(move_right);
        if(m.path.count(make_pair(right_i.X, right_i.Y)) == 1) m.path.erase(make_pair(right_i.X, right_i.Y));  
    }

    if(m.curr.X > 0)
    {
        pos left_i;
        left_i.X = m.curr.X - 1;
        left_i.Y = m.curr.Y;
        m_hist move_left(m.curr, left_i);
        auto cnt_l = m.cnt;
        if(m.x_move != move_left.x_move && m.y_move != move_left.y_move || m.x_move == false && m.y_move == false)
        {
            ++cnt_l;
            m.path.insert(make_pair(left_i.X, left_i.Y));
        } 
        move_left.cnt = cnt_l;
        move_left.path = m.path;
        // DFS_move(visited_paths, cache, grid, move_left, goal, cnt_l, path);  
        to_be_visited.push(move_left); 
        if(m.path.count(make_pair(left_i.X, left_i.Y)) == 1) m.path.erase(make_pair(left_i.X, left_i.Y));  
    }

    if(m.curr.Y < (int) grid.size() - 1)
    {
        pos south_i;
        south_i.X = m.curr.X;
        south_i.Y = m.curr.Y + 1;
        m_hist move_south(m.curr, south_i);
        auto cnt_s = m.cnt;
        if(m.x_move != move_south.x_move && m.y_move != move_south.y_move || m.x_move == false && m.y_move == false)
        {
            ++cnt_s;
            m.path.insert(make_pair(south_i.X, south_i.Y));
        } 
        move_south.cnt = cnt_s;
        move_south.path = m.path;
        // DFS_move(visited_paths, cache, grid, move_south, goal, cnt_s, path); 
        to_be_visited.push(move_south);  
        if(m.path.count(make_pair(south_i.X, south_i.Y)) == 1) m.path.erase(make_pair(south_i.X, south_i.Y));  
    }  

    if(m.curr.Y > 0)
    {
        pos north_i;
        north_i.X = m.curr.X;
        north_i.Y = m.curr.Y - 1;
        m_hist move_north(m.curr, north_i);
        auto cnt_n = m.cnt;
        if(m.x_move != move_north.x_move && m.y_move != move_north.y_move || m.x_move == false && m.y_move == false)
        {
            ++cnt_n;
            m.path.insert(make_pair(north_i.X, north_i.Y));
        }
        move_north.cnt = cnt_n;
        move_north.path = m.path;
        // DFS_move(visited_paths, cache, grid, move_north, goal, cnt_n, path); 
        to_be_visited.push(move_north);
        if(m.path.count(make_pair(north_i.X, north_i.Y)) == 1) m.path.erase(make_pair(north_i.X, north_i.Y));  
    }

    while(!to_be_visited.empty())
    {
        auto path_i = to_be_visited.top();
        to_be_visited.pop();
        DFS_move(visited_paths, cache, grid, path_i, goal);
    }

    return;   
}

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    pos goal, start;
    goal.X = goalX;
    goal.Y = goalY;
    start.X = startX;
    start.Y = startY;

    // set<set<pair<int, int>>> visited_paths;
    set<m> visited_paths; 
    map<set<pair<int, int>>, int> cache;

    pair<int, int> pos = make_pair(start.X, start.Y);
    set<pair<int, int>> path{pos};
    m_hist init_move(start, start);
    init_move.cnt = 0;

    stack<m_hist> to_be_visited;
    
    DFS_move(visited_paths, cache, grid, init_move, goal, to_be_visited);
    
    for(auto& [k, v] : cache)
    {
        cout << v << endl;
    }
    return 0;
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
