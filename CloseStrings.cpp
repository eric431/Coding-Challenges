/*
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"
Example 2:

Input: word1 = "a", word2 = "aa"
Output: false
Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
Example 3:

Input: word1 = "cabbba", word2 = "abbccc"
Output: true
Explanation: You can attain word2 from word1 in 3 operations.
Apply Operation 1: "cabbba" -> "caabbb"
Apply Operation 2: "caabbb" -> "baaccc"
Apply Operation 2: "baaccc" -> "abbccc"
 

Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/

class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            if (word1.size() != word2.size()) return false;
    
            map<char, int> freq_map_1 {};
            map<char, int> freq_map_2 {};
    
            for(auto &el : word1) ++freq_map_1[el];
            for(auto &el : word2) ++freq_map_2[el];
    
            if(freq_map_1 == freq_map_2) return true;
    
            vector<int> r_freq_v1 {};
            vector<int> r_freq_v2 {};
            vector<char> char_v1 {}; 
            vector<char> char_v2 {}; 
    
            for(auto &el : freq_map_1)
            {
                r_freq_v1.push_back(el.first);
                char_v1.push_back(el.second);
            }
            sort(r_freq_v1.begin(), r_freq_v1.end());
            sort(char_v1.begin(), char_v1.end());
    
            for(auto &el : freq_map_2)
            {
                r_freq_v2.push_back(el.first);
                char_v2.push_back(el.second);
            }
            sort(r_freq_v2.begin(), r_freq_v2.end());
            sort(char_v2.begin(), char_v2.end());
    
            return (r_freq_v1 == r_freq_v2) && (char_v1 == char_v2); 
        }
    };