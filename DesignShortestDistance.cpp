class WordDistance {
    unordered_map<string, vector<int>> word_map;
public:
    WordDistance(vector<string>& wordsDict) {
        for(auto j{0}; j < wordsDict.size(); ++j){
            word_map[wordsDict[j]].push_back(j);
        }
    }
    
    int shortest(string word1, string word2) {
        auto w1_v = word_map[word1];
        auto w2_v = word_map[word2];

        int w1_sz = word_map[word1].size();
        int w2_sz = word_map[word2].size();
        int sz = w1_sz + w2_sz;

        vector<pair<string, int>> tmp;
        int i{0};
        int j{0};

        while(i < w1_sz && j < w2_sz){
            if(w1_v[i] < w2_v[j]){
                tmp.push_back({word1, w1_v[i]});
                ++i;
            } else if (w1_v[i] > w2_v[j]){
                tmp.push_back({word2, w2_v[j]});
                ++j;
            }
        }

        if(i == w1_sz){ 
            tmp.push_back({word2, w2_v[j]}); 
        } else if(j == w2_sz){ 
            tmp.push_back({word1, w1_v[i]}); 
        }

        pair<string, int> prev = tmp[0];
        int min_d = numeric_limits<int>::max();
        for (auto k{1}; k < tmp.size(); ++k){
            if (tmp[k].first != prev.first){
                min_d = min(abs(tmp[k].second - prev.second), min_d);
            }
            prev = tmp[k];
        }

        return min_d;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */