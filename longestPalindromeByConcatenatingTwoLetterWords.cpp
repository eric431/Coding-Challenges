/*
You are given an array of strings words. Each element of words consists of two lowercase English letters.

Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.

Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.

A palindrome is a string that reads the same forward and backward.

 

Example 1:

Input: words = ["lc","cl","gg"]
Output: 6
Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
Note that "clgglc" is another longest palindrome that can be created.
Example 2:

Input: words = ["ab","ty","yt","lc","cl","ab"]
Output: 8
Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" = "tylcclyt", of length 8.
Note that "lcyttycl" is another longest palindrome that can be created.
Example 3:

Input: words = ["cc","ll","xx"]
Output: 2
Explanation: One longest palindrome is "cc", of length 2.
Note that "ll" is another longest palindrome that can be created, and so is "xx".
 

Constraints:

1 <= words.length <= 105
words[i].length == 2
words[i] consists of lowercase English letters.
*/

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> word_map {};

        int palindrome_len {0};
        bool add_two {false};
        int doubles {0};
        for(auto i{0}; i < words.size(); ++i)
        {
            string tmp = words[i];
            swap(tmp[0], tmp[1]);

            if(word_map.contains(tmp) && tmp[0] != tmp[1])
            {
                palindrome_len += 4;
                --word_map[tmp];

                if(!word_map[tmp]) word_map.erase(tmp);
                continue;
            }

            ++word_map[words[i]];
        }

        for(auto& [k, v] : word_map)
        {
            if(k[0] == k[1])
            {
                doubles += v - (v % 2) * 1;
                if(v % 2) add_two = true;
            }
        }

        palindrome_len += (2 * doubles) + (add_two) * 2;

        return palindrome_len;
    }
};