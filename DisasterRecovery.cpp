// #include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <functional>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

string ltrim(const string &);
string rtrim(const string &) ;

using Order = pair<uint64_t, uint64_t>;
using Repository = set<Order>;

class RecoverySystem{
    private:
        ofstream fout;
        unordered_map<string, string> m_root;
        unordered_map<string, int> m_rank;
        unordered_map<string, Repository> m_commit_recovery;
        unordered_map<string, unordered_set<string>> m_ambiguity_map; 
        unordered_map<string, bool> m_repo_ambiguity; 

        string find_root(const string &k){
            if(k == m_root[k]){
                return k;
            }
            return m_root[k] = find_root(m_root[k]);
        }

        void union_find(const string &k1, const string &k2){
            auto root_k1 = find_root(k1);
            auto root_k2 = find_root(k2);
            if(root_k1 != root_k2){
                if(m_rank[root_k1] > m_rank[root_k2]){
                    m_root[root_k2] = m_root[root_k1];
                } else if (m_rank[root_k1] < m_rank[root_k2]){
                    m_root[root_k1] = m_root[root_k2];
                } else {
                    m_root[root_k2] = m_root[root_k1];
                    ++m_rank[root_k1];
                }
            }
        }

        // uint64_t hash_key(const string &str){}

    public:
        RecoverySystem(const string &env){
            if(!fout.is_open()){
                fout.open(env);
            }
        }

        RecoverySystem(){}

        void parse_input(const string &str){
            istringstream input_stream(str);
            int i{0};
            uint64_t commit_id{};
            uint64_t timestamp{};
            string words;
            string set_key{};
            vector<string> file_paths;
            vector<string> opaque_ids;
            vector<string> set_keys;
            vector<Order> timestamp_id;

            {
                auto tmp_root = m_root;
                auto tmp_rank = m_rank;
                while(input_stream >> words){
                    if((i == 0 && words != "id") || (i == 2 && words != "timestamp")){
                        return;
                    } else if(i == 1) {
                        commit_id = stoi(words);
                    } else if(i == 3) {
                        timestamp = stoi(words);
                        timestamp_id.push_back(make_pair(timestamp, commit_id));
                    } else if(i > 3 && !(i % 2)){
                        set_key = words;
                        file_paths.push_back(words);
                    } else if (i > 3 && i % 2){
                        opaque_ids.push_back(words);
                        set_key += words;
                        set_keys.push_back(set_key);
                        if(!m_root.count(set_key)){
                            m_root[set_key] = set_key;
                            m_rank[set_key] = 1;
                        }
                    }
                    ++i;
                }

                if(i < 4 || i % 2){
                    m_root = tmp_root;
                    m_rank = tmp_rank;

                    return;
                }
            }

            for(auto i{1}; i < set_keys.size(); ++i){
                union_find(set_keys[0], set_keys[i]);
            }

            auto repo = find_root(set_keys[0]);
            for(auto &el : timestamp_id){
                m_commit_recovery[repo].insert(el);
            }

            for(auto i{0}; i < set_keys.size(); ++i){
                auto ambiguity_key = file_paths[i] + repo; 
                if(!m_ambiguity_map[ambiguity_key].count(opaque_ids[i])) {
                    m_ambiguity_map[ambiguity_key].insert(opaque_ids[i]);
                    m_repo_ambiguity[repo] = (m_ambiguity_map[ambiguity_key].size() > 1);
                }
                
            }
        }

        void update_roots(){
            for(auto &[k, v] : m_root){
                v = find_root(k);
            }
        }

        void retrieve_commit_ids(const string &str){
            // if(!fout.is_open()) {
            //     throw runtime_error("File handler is not open");
            // }

            istringstream input_stream(str);

            string words;
            int i{0};

            uint64_t start_time{};
            uint64_t end_time{};
            string file_path{};
            string key{};
            while(input_stream >> words){
                if(i == 0){
                    start_time = stoi(words);
                } else if (i == 1){
                    end_time = stoi(words);
                } else if (i == 4) {
                    return;
                } else {
                    if(words == "empty_response"){
                        return;
                    } else if (i == 2){
                        file_path = words;
                    }
                    key += words;
                }
                ++i;
            }

            auto repo = find_root(key);
            auto ambiguity_key = file_path + repo;
            if(m_repo_ambiguity[repo]){
                // fout << "AMBIGUOUS INPUT!";
                cout << "AMBIGUOUS INPUT!";
                return;
            }

            auto itr = m_commit_recovery[repo].lower_bound({start_time, 0});
            auto end = m_commit_recovery[repo].end();

            while(itr != end){
                if(itr->first > end_time) break;
                // fout << itr->second << " ";
                cout << itr->second << " ";
                ++itr;
            }
        }

        ~RecoverySystem(){
            if(fout.is_open()){
                fout.close();
            }
        }
};

int main(){

    RecoverySystem rs;

    // ofstream fout(getenv("PATH"));
    ifstream file("disaster_recovery_input.txt");

    string q_tmp;
    getline(file, q_tmp);
    int q = stoi(ltrim(rtrim(q_tmp)));
    for(auto i{0}; i < q; ++i){
        string input;
        getline(file, input);

        rs.parse_input(input);
    }

    rs.update_roots();

    string n_tmp;
    getline(file, n_tmp);
    int n = stoi(ltrim(rtrim(n_tmp)));
    for(auto i{0}; i < n; ++i){
        string input;
        getline(file, input);

        rs.retrieve_commit_ids(input);
        cout << "\n";
    }   

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](unsigned char ch) { return !isspace(ch); })
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !isspace(ch); }).base(),
        s.end()
    );

    return s;
}