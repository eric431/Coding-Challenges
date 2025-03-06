// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
// Example 2:

// Input: s = "aeiou", k = 2
// Output: 2
// Explanation: Any substring of length 2 contains 2 vowels.
// Example 3:

// Input: s = "leetcode", k = 3
// Output: 2
// Explanation: "lee", "eet" and "ode" contain 2 vowels.


class Solution {
    public:
        int maxVowels(string s, int k) {
            int window_start {0};
            int window_end {0};
            int max_num_vowels {0};
            int curr_num_vowels {0};
    
            unordered_set<char> set_of_vowels {'a', 'e', 'i', 'o', 'u'};
            vector<bool> vowels(s.size()); 
            for(; window_end < s.size(); ++window_end)
            {
                if(set_of_vowels.count(s[window_end]))
                {
                    vowels[window_end] = true;
                    ++curr_num_vowels;
                }
    
                if(window_end - window_start + 1 > k)
                {
                    curr_num_vowels -= vowels[window_start] * 1;
                    ++window_start;
                }
    
                max_num_vowels = max(max_num_vowels, curr_num_vowels);
            }
    
            return max_num_vowels;
        }
    };