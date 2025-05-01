#include <bits/stdc++.h>
#include <bitset>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'findConnectedComponents' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY d as parameter.
 */

void create_subsets(int i, vector<long>& d, vector<vector<long>>& subsets){
    if(i == d.size()) return;
    
    if(!subsets.empty()){
        auto tmp = subsets;
        for(auto &subset : subsets){
            auto new_subset = subset;
            new_subset.push_back(d[i]);

            tmp.push_back(new_subset);
        }
        swap(subsets, tmp);        
    }
    
    subsets.push_back({d[i]});
    create_subsets(i + 1, d, subsets);
}

int findConnectedComponents(vector<long> d) {
    vector<bitset<64>> d_bs(d.size());
    
    unordered_map<long, unordered_set<int>> components;
    for(auto &el : d){
        d_bs.push_back(bitset<64>(el));
        
        for(auto i{0}; i < 64; ++i){
            components[el].insert(i + 1);
        }
    }
    
    
    
    // create subsets
    vector<vector<long>> subsets{};
    create_subsets(0, d, subsets);
    
    int connected_c {64};
    for(auto &v : subsets){
        for(auto &el : v) {
            cout << el << " ";
        }
        cout << endl;
    }
    
    return connected_c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string d_count_temp;
    getline(cin, d_count_temp);

    int d_count = stoi(ltrim(rtrim(d_count_temp)));

    string d_temp_temp;
    getline(cin, d_temp_temp);

    vector<string> d_temp = split(rtrim(d_temp_temp));

    vector<long> d(d_count);

    for (int i = 0; i < d_count; i++) {
        long d_item = stol(d_temp[i]);

        d[i] = d_item;
    }

    int components = findConnectedComponents(d);

    fout << components << "\n";

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
