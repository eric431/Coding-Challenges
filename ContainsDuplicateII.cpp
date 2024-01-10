/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 

Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> i_map;
        unordered_map<int, int> j_map;
        
        auto logic = [&](int i, int j)
        {
            if(nums[i]==nums[j] && abs(i-j) <= k)
            {
                return true;
            }
            else
            {
                return false;
            }
        };
        
        for(auto x=0; x<nums.size(); x++)
        {
            i_map[nums[x]].push_back(x); 
        }
            
        for(auto& [key, value] : i_map)
        {
            if(value.size()==1)
            {
                continue;
            }
            else
            {
                for(size_t i=0; i<value.size()-1; i++)
                {
                    if(logic(value[i], value[i+1]))
                    {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};