#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'balancedForest' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY c
 *  2. 2D_INTEGER_ARRAY edges
 */

int DFS_rcs(vector<vector<int>> &adj, vector<bool>& visited, int idx, unordered_map<int, int>& forest_map, int v1, int explored_node)
{
    visited[idx - 1] = true;
    for(int i : adj[idx - 1])
    {
        if(i != explored_node && !visited[i - 1])
        {
            int s1 = forest_map[1] - (v1 + forest_map[i]); // subtree 1
            int s2 = forest_map[i]; // sum of nodes of subtree 2
            if(v1 == s1 && s2 < v1)
            {
                return v1 - s2;
            }
            else if(v1 == s2 && s1 < v1)
            {
                return v1 - s1;
            }
            else if(s1 == s2 && v1 < s1)
            {
                return s1 - v1;
            }
            else
            {
                int v = DFS_rcs(adj, visited, i, forest_map, v1, explored_node);
                if(v != -1) return v;                
            }
        }
    }

    return -1;
}

int DFS_search(vector<vector<int>> &adj, int s, unordered_map<int, int>& forest_map, int val_1, int detached_node)
{
    vector<bool> visited(adj.size(), false);
    return DFS_rcs(adj, visited, s, forest_map, val_1, detached_node);
}

int forest_search(vector<vector<int>> &adj, vector<bool>& visited, int sum, unordered_map<int, int>& forest_map, int idx)
{
    visited[idx - 1] = true;
    int detached_node{};
    int val_1{}; // first value to search
    int r{}; // result of the search
    
    for(int i : adj[idx - 1])
    {
        if(!visited[i - 1])
        {
            detached_node = i;
            val_1 = forest_map[i];
                        
            int r = DFS_search(adj, 1, forest_map, val_1, detached_node);
            if(r != -1) return r;
            else {
                r = forest_search(adj, visited, sum, forest_map, i);
                if(r != -1) return r;
            }
        }
    }

    return -1;
}


int balance_forest(vector<vector<int>> &adj, unordered_map<int, int>& forest_map, int idx)
{
    vector<bool> visited(adj.size(), false);
    int forest_sum = forest_map[idx];
    
    return forest_search(adj, visited, forest_sum, forest_map,  idx);
}

int balancedForest(vector<int> c, vector<vector<int>> edges) {
    auto add_edge = [&](vector<vector<int>> &adj, int s, int t)
    {
        adj[s - 1].push_back(t);
        adj[t - 1].push_back(s);
    };
    
    unordered_map<int, vector<vector<int>>> edge_map{};
    map<int, vector<int>> freq_map{};
    
    unordered_map<int, int> forest_map{};
    for(auto el : edges)
    {
        edge_map[el[0]].push_back(el);
        if(!forest_map.count(el[0])) forest_map[el[0]] = c[el[0] - 1];
        if(!forest_map.count(el[1])) forest_map[el[1]] = c[el[1] - 1];
    }
    for(auto [k, v] : edge_map)
        freq_map[v.size()].push_back(k);

    for(auto& [k, v] : freq_map)
        for(auto& el_k : v)
            for(auto& el_ : edge_map[el_k]) forest_map[el_k] += forest_map[el_[1]];
    
    for(auto& [k, v] : forest_map)
    {
        cout << k << " " << v << endl;
    }
    cout << endl;
    
    // add edges
    int n = c.size();
    vector<vector<int>> adj(n);
    for(auto &e : edges) add_edge(adj, e[0], e[1]);
    
    int s = 1;  
    return balance_forest(adj, forest_map, s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string c_temp_temp;
        getline(cin, c_temp_temp);

        vector<string> c_temp = split(rtrim(c_temp_temp));

        vector<int> c(n);

        for (int i = 0; i < n; i++) {
            int c_item = stoi(c_temp[i]);

            c[i] = c_item;
        }

        vector<vector<int>> edges(n - 1);

        for (int i = 0; i < n - 1; i++) {
            edges[i].resize(2);

            string edges_row_temp_temp;
            getline(cin, edges_row_temp_temp);

            vector<string> edges_row_temp = split(rtrim(edges_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int edges_row_item = stoi(edges_row_temp[j]);

                edges[i][j] = edges_row_item;
            }
        }

        int result = balancedForest(c, edges);

        fout << result << "\n";
    }

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
