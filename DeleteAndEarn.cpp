/*
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.
Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] <= 104
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> freq_map{};
        vector<vector<int>> nums_freq{};
        
        for(auto el : nums)
        {
            ++freq_map[el];
        }
        
        for(auto& [k, v] : freq_map)
        {
            nums_freq.push_back({k * v, k});
        }
        if(nums_freq.size() == 1) return nums_freq[0][0];
        
        vector<int> dp(nums_freq.size());
        
        dp[0] = nums_freq[0][0];
        
        if(nums_freq[1][1] - nums_freq[0][1] > 1) dp[1] = nums_freq[0][0] + nums_freq[1][0];
        else if(nums_freq[1][1] - nums_freq[0][1] == 1) dp[1] = max(nums_freq[1][0], nums_freq[0][0]);
        
        int max_points = max(dp[0], dp[1]);
        for(auto i{2}; i < nums_freq.size(); ++i)
        {
            if(nums_freq[i][1] - nums_freq[i - 1][1] > 1)
            {
                dp[i] = nums_freq[i][0] + dp[i - 1];
            }
            else if (nums_freq[i][1] - nums_freq[i - 1][1] == 1)
            {
                dp[i] = max(nums_freq[i][0] + dp[i - 2], dp[i - 1]);
            }
            max_points = max(dp[i], max_points);
        }

        return max_points;
    }
};