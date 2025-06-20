/*
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.
Example 3:

Input: nums = [-3,-2,-3]
Output: -2
Explanation: Subarray [-2] has maximum sum -2.
 

Constraints:

n == nums.length
1 <= n <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
*/


class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        
        int max_sum {nums[0]};
        int curr_sum {0};
        int cum_sum {0};
        for(auto el : nums)
        {
            curr_sum = max(curr_sum + el, el);
            max_sum = max(curr_sum, max_sum);
            
            cum_sum += el;
        }
        
        curr_sum = 0;
        for(auto i{0}; i < nums.size(); ++i)
        {
            curr_sum = cum_sum - nums[i];
            max_sum = max(curr_sum, max_sum);
            
            for(int j{i + 1}; j < nums.size() && curr_sum > cum_sum; ++j)
            {
                curr_sum -= nums[j];
                if(!(curr_sum == 0 && max_sum != 0))
                    max_sum = max(curr_sum, max_sum);
            }
        }
        
        return max_sum;
    }
};