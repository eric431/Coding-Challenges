class Solution {
    public:
        string word2;
        unordered_map<string, int> memo;
    
        int dp(int i, const string& word1){
            if (memo.contains(word1)){
                return memo[word1];
            } else if(word1 == word2){
                return 0;
            } else if (i >= word2.size() && i < word1.size()){
                auto str2 = word1;
                str2.erase(i, 1);
                return memo[word1] = 1 + dp(i, str2);
            }
    
            if (i >= word1.size() && i < word2.size()){
                // insert a character
                string str3 = word1;
                string el = ""; 
                el += word2[i];
                str3.insert(i, el); 
    
                return memo[word1] = 1 + dp(i + 1, str3);           
            }
    
            auto tmp1 = word1.substr(0, i);
            auto tmp2 = word2.substr(0, i);
            if(tmp1 != tmp2){ return 1301; }
    
            if(i < min(word1.size(), word2.size()) && word1[i] == word2[i]){ return memo[word1] = dp(i + 1, word1); }
    
            // replace character
            auto str1 = word1;
            str1[i] = word2[i];
    
            // delete character
            auto str2 = word1;
            str2.erase(i, 1);
    
            // insert a character
            auto str3 = word1;
            string el = ""; 
            el += word2[i];
            str3.insert(i, el);
    
            return memo[word1] = min({1 + dp(i + 1, str1), 1 + dp(i, str2), 1 + dp(i + 1, str3)});
        }
    
        int minDistance(string word1, string word2) {
            if(word1 == word2){ return 0; }
    
            this->word2 = word2;
    
            return dp(0, word1);
        }
    };