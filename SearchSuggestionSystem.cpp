class Solution {
public:
    struct Trie{
        map<char, Trie*> children;
        bool is_complete;

        Trie() : is_complete(false){}
    };

    Trie* root;

    void add_string(const string& word){
        auto node = root;
        for(auto& c : word){
            if(!node->children.contains(c)){
                node->children[c] = new Trie;
            }
            node = node->children[c];
        }
        node->is_complete = true;
    }

    void dfs_traversal(Trie* node, string &word, vector<string>& suggested_words){
        if(node->is_complete){
            suggested_words.push_back(word);
        }

        for(auto &[k, v] : node->children){
            if(suggested_words.size() == 3) break;

            word += k;
            dfs_traversal(v, word, suggested_words);
            word.pop_back();
        }
    }

    vector<vector<string>> get_suggested(const string &word){
        vector<vector<string>> prods;
        auto node = root;

        string prefix_word = "";
        bool no_suggestion = false;
        for(auto &c : word){
            if(!node->children.contains(c) || no_suggestion){
                if(!no_suggestion) no_suggestion = true;
                prods.push_back({});
                continue;
            }

            prefix_word += c;

            vector<string> rcmd {}; // recommended
            node = node->children[c];

            dfs_traversal(node, prefix_word, rcmd);
            prods.push_back(rcmd);
        }  

        return prods;      
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        this->root = new Trie;

        for(auto &prod : products){ add_string(prod); }
        return get_suggested(searchWord);
    }
};