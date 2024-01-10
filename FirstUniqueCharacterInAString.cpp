/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1
 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_count;
        unordered_map<char, int> ind_count;
        map<int, int> index_loc;
        
        uint ind = 0;
        for(auto& c : s)
        {
            char_count[c]++;
            ind_count[c] = ind;
            ind++;
        }

        for (auto& [key, value] : char_count)
        {
            if(value!=1)
            {
                ind_count.erase(key);
            }
        }
        
        for(auto& [key, value] : ind_count)
        {
            index_loc[value] = char_count[key];
        }
        
        if (index_loc.size()==0)
        {
            return -1;
        }
        else
        {
            return index_loc.begin()->first;
        }
    }
};