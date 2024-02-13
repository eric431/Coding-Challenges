// Given a string s, find the length of the longest substring without repeating characters.

 

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
        int max_substr_length = 0;        
        unordered_set<char> substr_set;
        
        string max_substr = "";
        
        vector<char> substr_vec;
        map<char, int> vec_tracker;
                
        int i = 1;
        int buffer = 0;
        for(auto& el : s)
        {
            if(vec_tracker.contains(el))
            {
                if(substr_vec.size()>max_substr_length)
                {
                    max_substr_length = substr_vec.size();   
                }

                auto itr = vec_tracker[el];
                itr-=buffer;
                
                for(auto iter=substr_vec.begin(); iter<substr_vec.begin()+itr; iter++)
                {
                    vec_tracker.erase(*iter);
                }
                substr_vec.erase(substr_vec.begin(), substr_vec.begin()+itr);
                
                buffer+=itr;
                
                substr_vec.push_back(el);
                vec_tracker[el]=i;
            }
            else 
            {
                substr_vec.push_back(el);
                vec_tracker[el]=i;
            }
            
            i++;
        }

        if(substr_vec.size() > max_substr_length)
        {
            return substr_vec.size();
        }
        return max_substr_length;
    }
};