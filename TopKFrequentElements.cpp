// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.
 

// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> tracker_left;
        map<int, vector<int>> tracker_right;
        set<int, greater<int>> value_vec;
        
        vector<int> output;
        
        for(auto& el : nums)
        {
            tracker_left[el]++;
        }  
        for(auto& [key, value] : tracker_left)
        {
            tracker_right[value].push_back(key);
            value_vec.insert(value);
        }

        int i = 0;
        for(auto& el : value_vec)
        {
            if(i==k)
            {
                break;
            }
            
            if(tracker_right[el].size()>1)
            {
                for(auto& el2 : tracker_right[el])
                {
                    if(i==k)
                    {
                        break;
                    }
                    output.push_back(el2);
                    i++;
                }
            }
            else
            {
                output.push_back(tracker_right[el][0]);
                i++;
            }
        }
        
        return output;
    }
};