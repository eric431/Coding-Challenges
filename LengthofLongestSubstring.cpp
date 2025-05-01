// Given a string s, find the length of the longest substring without duplicate characters.

 

// Example 1:

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.
// Example 2:

// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

// Constraints:

// 0 <= s.length <= 5 * 104
// s consists of English letters, digits, symbols and spaces.

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            int max_len = 0;
            int ws{0}, we{0}; // window start and window end
            unordered_map<char, int> uniq_chars;
    
            int l = s.size();
            for (; we < l; ++we) {
                if(uniq_chars.contains(s[we])) {
                    ws = max(uniq_chars[s[we]] + 1, ws);
                }
                max_len = max(max_len, we - ws + 1);
                uniq_chars[s[we]] = we;
            }
    
            return max_len;
        }
    };