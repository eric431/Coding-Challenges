// Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".

// The testcases will be generated such that the answer is unique.

 

// Example 1:

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
// Example 2:

// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.
// Example 3:

// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be included in the window.
// Since the largest window of s only has one 'a', return empty string.
 

// Constraints:

// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.


class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char, int> freq_cnt {};
            unordered_map<char, int> w_cnt {};
            pair<int, int> sub_slice = {-1, -1};
            int w_start{0};
            int w_end{0};
            int str_len = numeric_limits<int>::max();
    
            auto valid = [&](unordered_map<char, int>& w_cnt, unordered_map<char, int>& f_cnt){
                for (auto &[k, v] : f_cnt) { if(w_cnt[k] < v){ return false; } }
                return true;
            };
    
            for (auto &c : t) {
                ++freq_cnt[c];
                w_cnt[c] = 0;
            }
    
            string ans = "";
            for(; w_end < s.size(); ++w_end){
                if(freq_cnt.contains(s[w_end])) {
                    ++w_cnt[s[w_end]];
    
                    while (valid(w_cnt, freq_cnt)) {
                        if (w_end - w_start + 1 < str_len) {
                            str_len = w_end - w_start + 1;
                            sub_slice = {w_start, w_end};
                        }
    
                        --w_cnt[s[w_start]];
                        ++w_start;
    
                        while (w_start < s.size() && !freq_cnt.contains(s[w_start])) { ++w_start; }
                    }
                }
            }
    
            if (sub_slice.first != -1 && sub_slice.second != -1) {
                int s_ = sub_slice.first;
                int e_ = sub_slice.second;
    
                ans = s.substr(s_, e_ - s_ + 1);
            }
    
            return ans;
        }
    };