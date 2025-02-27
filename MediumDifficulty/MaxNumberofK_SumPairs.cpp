// You are given an integer array nums and an integer k.

// In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

// Return the maximum number of operations you can perform on the array.

 

// Example 1:

// Input: nums = [1,2,3,4], k = 5
// Output: 2
// Explanation: Starting with nums = [1,2,3,4]:
// - Remove numbers 1 and 4, then nums = [2,3]
// - Remove numbers 2 and 3, then nums = []
// There are no more pairs that sum up to 5, hence a total of 2 operations.
// Example 2:

// Input: nums = [3,1,3,4,3], k = 6
// Output: 1
// Explanation: Starting with nums = [3,1,3,4,3]:
// - Remove the first two 3's, then nums = [1,4,3]
// There are no more pairs that sum up to 6, hence a total of 1 operation.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 1 <= k <= 109


class Solution {
    public:
        int maxOperations(vector<int>& nums, int k) {
            int cnt {0};
            unordered_map<int, int> sum_tracker {};
    
            for(auto& el : nums)
            {
                ++sum_tracker[el];
            }
    
            for(auto& el : nums)
            {
                int target = k - el;
                if(target != el && sum_tracker.count(target))
                {
                    int m = min(sum_tracker[target], sum_tracker[el]);
                    cnt += m;
    
                    sum_tracker[target] -= m;
                    sum_tracker[el] -= m;
    
                    if(sum_tracker[target] == 0)
                    {
                        sum_tracker.erase(target);
                    }
                    
                    if (sum_tracker[el] == 0)
                    {
                        sum_tracker.erase(el);
                    }
                }
                else if(target == el && sum_tracker.count(target))
                {
                    if(sum_tracker[target] > 1)
                    {
                        cnt += sum_tracker[target] / 2;
                    }
                    sum_tracker.erase(target);
                }
            }
    
            return cnt;
        }
};