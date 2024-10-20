// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];
        
        int i = 0, j = 1;
        string common_sub = "", com_sub_tmp = "";
        for(; j < strs.size(); ++i, ++j)
        {
            if(i == 0)
            {
                for(auto k = 0; k < min(strs[i].size(), strs[j].size()); ++k)
                {
                    if(strs[i][k] == strs[j][k])
                    {
                        common_sub += strs[i][k];
                    }
                    else 
                    {
                        break;
                    }
                }
            }
            else if(i > 0 && common_sub != "")
            {
                for(auto k = 0; k < common_sub.size(); ++k)
                {
                    if(strs[i][k] == strs[j][k])
                    {
                        com_sub_tmp += strs[i][k];
                    }
                    else 
                    {
                        break;
                    }
                }
                if(com_sub_tmp.size() < common_sub.size())
                {
                    common_sub = com_sub_tmp;
                }
                com_sub_tmp = "";
            }

            if(common_sub == "") break;
        }

        return common_sub;
    }
};