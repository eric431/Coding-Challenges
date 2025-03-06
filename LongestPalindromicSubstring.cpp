// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.


class Solution {
    public:
        string longestPalindrome(string s) {
            if(s.size() == 1) return s;
    
            string new_str = "";
            for(auto &el : s)
            {
                new_str += '#';
                new_str += el;
            }
            new_str += '#';
    
            vector<int> lps (new_str.size());
    
            int c {0};
            int r {0};
            int max_len = 0;
            int max_palindrome_centre = 0;
    
            string max_palindrome = "";
            for (auto i{0}; i < new_str.size(); ++i)
            {
                int i_mirror = (2 * c) - i;
    
                if (i < r)
                {
                    lps[i] = min(r - i, lps[i_mirror]);
                }
    
                int a = i + (1 + lps[i]);
                int b = i - (1 + lps[i]);
                while(a < new_str.size() && b >= 0 && new_str[a] == new_str[b])
                {
                    ++lps[i];
                    ++a;
                    --b;
                }
    
                if(i + lps[i] > r)
                {
                    c = i;
                    r = i + lps[i];
    
                    if(lps[i] > max_len)
                    {
                        max_len = lps[i];
                        max_palindrome_centre = i;
                    }
                }
            }
    
            int start = max_palindrome_centre - max_len;
            int end = max_palindrome_centre + max_len;
    
            string result = "";
            for(auto i {start}; i <= end; ++i)
            {
                if(new_str[i] != '#')
                {
                    result += new_str[i];
                }
            }
    
            return result;
        }
    };