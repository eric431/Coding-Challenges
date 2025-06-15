#include <cmath>
#include <cstdio>
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

class Cache 
{
    protected:
        struct Node{
            int key;
            int val;
            shared_ptr<Node> prev;
            shared_ptr<Node> next;
            
            Node(int key, int value) 
            : key(key)
            , val(value){}
        };
    
        unordered_map<int, shared_ptr<Node>> mp;
        size_t cp;
        shared_ptr<Node> head;
        shared_ptr<Node> tail;
    
    public:
        Cache(int c) 
        : cp(c){}
        
        virtual void set(int key, int value) = 0;
        
        virtual int get(int key) = 0;
};

class LRUCache : public Cache{
    public:
        LRUCache(int c) : Cache(c) {}

        void set(int key, int value) override {
            if(mp.size() == cp){
                mp.erase(tail->key);
                
                if(tail->prev){
                    tail = tail->prev;
                    tail->next = nullptr;                    
                }
            }
            
            shared_ptr<Node> node = make_shared<Node>(key, value);

            if(head != nullptr){ 
                head->prev = node; 
                node->next = head;
            }
            
            head = node;
            if(mp.empty()){ tail = node; }
            
            mp[key] = node;
        }
        
        int get(int key) override {
            if(mp.count(key)){ return mp[key]->val; }
            return -1;
        } 
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    fstream fout(getenv("OUTPUT_PATH"));
    
    string n_tmp;
    getline(cin, n_tmp);
    auto str_vec = split(ltrim(rtrim(n_tmp)));
    int n = stoi(str_vec[0]);
    int capacity = stoi(str_vec[1]);
    
    unique_ptr<LRUCache> lru_cache(new LRUCache(capacity));
    
    string line;
    for(auto i{0}; i < n; ++i){
        getline(cin, line);
        
        str_vec = split(ltrim(rtrim(line)));
        int k = stoi(str_vec[1]);
        if(str_vec[0] == "set"){
            int v = stoi(str_vec[2]);
            lru_cache->set(k, v);
        } else if(str_vec[0] == "get"){            
            cout << lru_cache->get(k) << "\n";
        }
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

