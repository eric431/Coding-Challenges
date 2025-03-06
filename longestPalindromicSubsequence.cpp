// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

// Example 1:

// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
// Example 2:

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".
 

// Constraints:

// 1 <= s.length <= 1000
// s consists only of lowercase English letters.

class Solution {
    public:
        int longest_palindrome(int l, int r, string_view s, vector<vector<int>>& cache)
        {
            if(r < 0 || l >= s.size()) return 0;
    
            if(cache[l][r] != -1)
            {
                return cache[l][r];
            }
    
            if (l > r) 
            {
                return cache[l][r] = 0;
            }
            else if (s[l] == s[r])
            {
                return cache[l][r] = (l == r) * 1 + (l != r) * 2 + longest_palindrome(l + 1, r - 1, s, cache);
            }
            else
            {
                int cnt_1 = longest_palindrome(l, r - 1, s, cache);
                int cnt_2 = longest_palindrome(l + 1, r, s, cache);
                int cnt_3 = longest_palindrome(l + 1, r - 1, s, cache);
    
                return cache[l][r] = max({cnt_1, cnt_2, cnt_3});
            }
        }
    
        int longestPalindromeSubseq(string s) {
            vector<vector<int>> cache (s.size(), vector<int>(s.size(), -1));
    
            if(s.size() == 1) return 1;
    
            int l = 0;
            int r = s.size() - 1;
            return longest_palindrome(l, r, s, cache);
        }
    };