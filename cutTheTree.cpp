#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'cutTheTree' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY data
 *  2. 2D_INTEGER_ARRAY edges
 */

int subtree_sum(int n, vector<int>& data, vector<bool>& visited, unordered_map<int, int>& tree_sums, vector<vector<int>>& tree){
    if(!tree[n].size()) return tree_sums[n] = data[n - 1];
    
    visited[n] = true;
    
    int sub_tree_sum{data[n - 1]};
    for(auto &s_t : tree[n]){ 
        if(!visited[s_t]) {
            sub_tree_sum += subtree_sum(s_t, data, visited, tree_sums, tree);
        } 
    }
    
    return tree_sums[n] = sub_tree_sum;
}

int cutTheTree(vector<int> data, vector<vector<int>> edges) {
    vector<vector<int>> tree(data.size() + 1);
    for(auto &edge : edges){
        tree[edge[0]].push_back(edge[1]);
        tree[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(tree.size(), false);
    unordered_map<int, int> tree_sums;
    int tree_sum = subtree_sum(1, data, visited, tree_sums, tree);
    
    int min_diff = numeric_limits<int>::max();
    
    for(auto &edge : edges){
        int tree_1 = tree_sum - min(tree_sums[edge[1]], tree_sums[edge[0]]);
        int tree_2 = tree_sum - tree_1;
        
        min_diff = min(min_diff, abs(tree_1 - tree_2));
    }
    
    return min_diff;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string data_temp_temp;
    getline(cin, data_temp_temp);

    vector<string> data_temp = split(rtrim(data_temp_temp));

    vector<int> data(n);

    for (int i = 0; i < n; i++) {
        int data_item = stoi(data_temp[i]);

        data[i] = data_item;
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

    int result = cutTheTree(data, edges);

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
