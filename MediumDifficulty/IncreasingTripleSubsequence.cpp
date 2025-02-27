// Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 

// Example 1:

// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.
// Example 2:

// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.
// Example 3:

// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because nums[3] == 0 < nums[4] == 4 < nums[5] == 6.
 

// Constraints:

// 1 <= nums.length <= 5 * 105
// -231 <= nums[i] <= 231 - 1
 

class Solution {
    public:
        bool increasingTriplet(vector<int>& nums) {
            if(nums.size() < 3)
                return false;
    
            int k {1};
    
            int sentinel_val = -1;
            long l = numeric_limits<long>::max();
            long m = numeric_limits<long>::max();
            long h = numeric_limits<long>::max();
            for(int k {0}; k < nums.size(); ++k)
            {
                if(nums[k] > m && m > l) return true;
                l = min(l, static_cast<long>(nums[k]));
                if(nums[k] > l)
                {
                    m = min(static_cast<long>(nums[k]), m);
                }
            }
    
    
            return false;
    
        }
    };