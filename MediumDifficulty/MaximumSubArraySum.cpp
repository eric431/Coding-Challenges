/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int windowStart = 0;
        int windowEnd = 0;
        int max_contiguous_sum{0};
        int max_sum{0};
        vector<int> prefix_sums(nums.size());

        {
            int cum_sum{0};
            for(auto i{0}; i < nums.size(); ++i)
            {
                cum_sum += nums[i];
                prefix_sums[i] = cum_sum;
            }            
        }

        max_sum = prefix_sums[0];
        int min_sum = prefix_sums[0];
        ++windowEnd;
        while(windowEnd < nums.size())
        {
            max_sum = max(max(max_sum, prefix_sums[windowEnd]), prefix_sums[windowEnd] - prefix_sums[windowStart]);

            if(prefix_sums[windowEnd] < min_sum)
            {
                windowStart = windowEnd;
                min_sum = prefix_sums[windowEnd];
            }
            ++windowEnd;
        }

        return max_sum;
    }
};