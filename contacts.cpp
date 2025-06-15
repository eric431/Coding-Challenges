#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'contacts' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_STRING_ARRAY queries as parameter.
 */

class book{
    private:
        struct Trie{
            unordered_map<char, pair<Trie*, int>> children;
            unordered_set<string> words;
        };
        
        Trie* root;
    public:
        book(){
            root = new Trie;
        }
        
        void add_name(const string& name){            
            Trie* node = root;
            
            if(node->words.count(name)){
                return;
            }
            node->words.insert(name);
            
            for(auto &c : name){
                if(!node->children.count(c)){
                    auto new_trie = new Trie;
                    
                    node->children[c] = {new_trie, 0};
                }
                ++node->children[c].second;
                node = node->children[c].first;
            }
            
            if(!node->children.count('\0')){
                auto end = new Trie;
                node->children['\0'] = {end, 1};
            }
        }
        
        int find_partial(const string& partial_name){
            Trie* node = root;
            
            int cnt;
            for(auto &c : partial_name){
                if(!node->children.count(c)){
                    return 0;
                }
                
                cnt = node->children[c].second;
                node = node->children[c].first;
            }
            
            return cnt;
        }
};


vector<int> contacts(vector<vector<string>> queries) {
    book contact_book;
    vector<int> ans;
    
    for(auto &q : queries){
        if(q[0] == "add"){
            contact_book.add_name(q[1]);
        } else if(q[0] == "find"){
            ans.push_back(contact_book.find_partial(q[1]));
        }
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string queries_rows_temp;
    getline(cin, queries_rows_temp);

    int queries_rows = stoi(ltrim(rtrim(queries_rows_temp)));

    vector<vector<string>> queries(queries_rows);

    for (int i = 0; i < queries_rows; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            string queries_row_item = queries_row_temp[j];

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = contacts(queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
