/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    void foo(vector<int>& range, const vector<int>& nums, int i, int j, int target)
    {
        while(nums[i] == target || nums[j] == target)
        {
            if(i > 0)
            {
                if(nums[i] == target) range[0] = i;
                --i;
            }
            else if (i == 0 && nums[i] == target)
            {
                range[0] = i;
            }

            if(j < nums.size() - 1)
            {
                if(nums[j] == target) range[1] = j;
                ++j;
            }
            else if (j == nums.size() - 1 && nums[j] == target)
            {
                range[1] = j;
            }

            if(i == 0 && j == nums.size() - 1) break;
        }
    }

    vector<int> binary_search(const vector<int>& nums, int target)
    {
        vector<int> first_last(2, -1);

        if(nums.size() == 0 || (nums.size() == 1 && nums[0] != target))
        {
            return first_last;
        }
        else if(nums.size() == 1 && nums[0] == target)
        {
            first_last.assign(2, 0);
            return first_last;
        }
        else if(nums.size() == 2)
        {
            if(nums[0] == target && nums[1] == target)
            {
                first_last[0] = 0;
                first_last[1] = 1;
                return first_last;                
            }
            else if(nums[0] != target && nums[1] != target)
            {
                return first_last;                
            }
            else if(nums[0] == target)
            {
                first_last.assign(2, 0);
                return first_last;                
            }
            else if(nums[1] == target)
            {
                first_last.assign(2, 1);
                return first_last;                
            }
        }

        int i{0}, j = nums.size() - 1, m = ceil(j / 2);
        while(i < m && m < j)
        {
            if(nums[i] == target || nums[j] == target)
            {
                if(nums[i] == target && nums[j] == target)
                {
                    foo(first_last, nums, i, j, target);
                    return first_last;
                }
                else if(nums[i] == target)
                {
                    j = i;
                    foo(first_last, nums, i, j, target);
                    return first_last;
                }
                else if(nums[j] == target)
                {
                    i = j;
                    foo(first_last, nums, i, j, target);
                    return first_last;                    
                }
            }
            else if(nums[i] < target && target < nums[j])
            {
                if(target < nums[m])
                {
                    j = m;
                    m = ceil((i + j) / 2);
                }
                else if (target > nums[m])
                {
                    i = m;
                    m = ceil((i + j) / 2);
                }
                else if(target == nums[m])
                {
                    i  = m;
                    j = m;
                    foo(first_last, nums, i, j, target);
                    return first_last;
                }
            }
            else if(target > nums[j] || target < nums[i]) break;
        }
        return first_last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        auto result = binary_search(nums, target);
        return result;
    }
};