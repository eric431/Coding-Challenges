/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/

class Solution {
public:
    inline void two_sum(const vector<int>& nums, int target, int j, int k, vector<vector<int>>& four_sum, set<vector<int>>& visited)
    {
        int i = j - 1, l = k + 1;
        while(j < k)
        {
            if(nums[j] + nums[k] == target)
            {
                vector<int> sum_v{nums[i], nums[j], nums[k], nums[l]};
                if(visited.count(sum_v) == 0)
                {
                    four_sum.emplace_back(sum_v);
                    visited.insert(move(sum_v));
                }
                --k;
                ++j;
            }            
            else if(nums[j] + nums[k] > target)
            {
                --k;
            }
            else if(nums[j] + nums[k] < target)
            {
                ++j;
            }
        }
    }

    inline void two_sum_init(const vector<int>& nums, int target, int i, int l, vector<vector<int>>& four_sum, set<vector<int>>& visited)
    {
        long new_target_tmp = static_cast<long>(target) - static_cast<long>(nums[i] + nums[l]);

        if(new_target_tmp > numeric_limits<int>::max() || new_target_tmp < numeric_limits<int>::min())
            return;

        int new_target = static_cast<int>(new_target_tmp);

        two_sum(nums, new_target, i + 1, l - 1, four_sum, visited);
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if(nums.size() < 4) return {};

        sort(nums.begin(), nums.end());

        int i{0}, l{(int)nums.size() - 1};
        vector<vector<int>> four_sums{};
        set<vector<int>> visited;

        while(i < l - 2)
        {
            for(auto x = i; x < l - 2; ++x)
            {
                if(x == i || (x > i && nums[x] != nums[x - 1]))
                    two_sum_init(nums, target, x, l, four_sums, visited);
            }
        
            for(auto x = l; x > i + 2; --x)
            {
                if(x == l || (x < l && nums[x] != nums[x + 1]))
                    two_sum_init(nums, target, i, x, four_sums, visited);
            }  

            ++i;
            --l;
        }
        return four_sums;
    }
};