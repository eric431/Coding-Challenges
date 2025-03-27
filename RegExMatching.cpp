// Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

// '.' Matches any single character.​​​​
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).

 

// Example 1:

// Input: s = "aa", p = "a"
// Output: false
// Explanation: "a" does not match the entire string "aa".
// Example 2:

// Input: s = "aa", p = "a*"
// Output: true
// Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
// Example 3:

// Input: s = "ab", p = ".*"
// Output: true
// Explanation: ".*" means "zero or more (*) of any character (.)".
 

// Constraints:

// 1 <= s.length <= 20
// 1 <= p.length <= 20
// s contains only lowercase English letters.
// p contains only lowercase English letters, '.', and '*'.
// It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

class Solution {
    public:
        string s_;
        string p_;
    
        vector<vector<pair<bool, bool>>> memo;
    
        bool regex_match(int i, int j)
        {
            if (i >= s_.size() && j >= p_.size()) return true;
            else if (j >= p_.size()) return false;
    
            if(i < s_.size() && memo[i][j].first) return memo[i][j].second;
    
            auto match = (i < s_.size() && (s_[i] == p_[j] || p_[j] == '.'));
            bool ans;
            if(j + 1 < p_.size() && p_[j + 1] == '*')
            {
                ans = (match && regex_match(i + 1, j)) || regex_match(i, j + 2);
            }
            else
            {
                ans = match && regex_match(i + 1, j + 1);
            }
    
            if(i < s_.size())
            {
                memo[i][j] = make_pair(true, ans);
                return memo[i][j].second;
            }
            return ans;
        }
    
        bool isMatch(string s, string p) {
            this->s_ = s;
            this->p_ = p;
    
            memo.resize(s.size(), vector<pair<bool, bool>>(p.size(), {false, false}));
    
            return regex_match(0, 0);
        }
    };