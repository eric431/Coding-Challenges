class WordDictionary {
    struct Tree{
        char val;
        unordered_map<char, shared_ptr<Tree>> children;

        Tree() {}
        Tree(char c) : val(c) {}
    };

    shared_ptr<Tree> root;

    bool match_word(const string &word, int i, shared_ptr<Tree> node){
        if (i == word.size()) {
            return node->children.contains('\0');
        }

        if (word[i] == '.'){
            bool matched = false;
            for(auto &[k, v] : node->children){
                if (k == '\0') continue;
                matched = match_word(word, i + 1, v);
                if(matched) return matched;
            }

            return matched;
        } else if (node->children.empty() || !node->children.contains(word[i])){
            return false;
        } else {
            return match_word(word, i + 1, node->children[word[i]]);
        }
    }

public:
    WordDictionary() {
        root = make_shared<Tree>();
    }
    
    void addWord(string word) {
        auto node = root;

        for(auto i{0}; i < word.size(); ++i){
            if (!node->children.contains(word[i])){
                node->children[word[i]] = make_shared<Tree>(word[i]);
            }
            node = node->children[word[i]];
        }

        node->children['\0'] = nullptr;
    }
    
    bool search(string word) {
        return match_word(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */