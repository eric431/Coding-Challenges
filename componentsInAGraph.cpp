#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */

int find(int x, vector<int>& root){
    if (x == root[x]){
        return x;
    }
    return root[x] = find(root[x], root);
}

void union_set(int x, int y, vector<int>& root, vector<int>& rank){
    auto rootX = find(x, root);
    auto rootY = find(y, root);
    
    if(rootX != rootY){
        if (rank[rootX] > rank[rootY]){
            root[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]){
            root[rootX] = rootY;
        }else {
            root[rootY] = rootX;
            ++rank[rootX];
        }
    }
}

vector<int> componentsInGraph(vector<vector<int>> gb) {
    vector<int> root(2 * gb.size() + 1);
    vector<int> rank(2 * gb.size() + 1);
    
    iota(root.begin(), root.end(), 0);
    fill(rank.begin(), rank.end(), 1);
    rank[0] = 0;
    
    unordered_map<int, int> sets;
    for(auto &v : gb){
        union_set(v[0], v[1], root, rank);
    }
    
    for(auto i{1}; i < root.size(); ++i){
        auto curr_root = find(i, root);
        ++sets[curr_root];
    }
    
    int min_c{numeric_limits<int>::max()};
    int max_c{numeric_limits<int>::min()};
    
    for(auto &k_v : sets){
        if(k_v.second > 1){
            min_c = min(min_c, k_v.second);
            max_c = max(max_c, k_v.second);            
        }
    }
    
    return {min_c, max_c};
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
