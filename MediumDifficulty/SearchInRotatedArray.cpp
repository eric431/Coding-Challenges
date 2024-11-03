/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104
*/

class Solution {
public:
    int binary_search(int i, int j, int target, const vector<int>& nums)
    {
        if((j - i + 1) == 2)
        {
            return (nums[i] == target) * i + (nums[j] == target) * j + (nums[i] != target && nums[j] != target) * (-1);
        }
        else if((j - i + 1) == 1)
        {
            return (nums[j] == target) * j + (nums[j] != target) * (-1);
        }

        int m = ceil((i + j) / 2);
        while(i < m && m < j)
        {
            if (target == nums[i] || target == nums[j])
            {
                if(target == nums[i]) return i;
                else if(target == nums[j]) return j; 
            }
            else if(nums[i] < target && target < nums[j])
            {
                if(target > nums[m])
                {
                    i = m;
                    m = ceil((i + j) / 2);
                }
                else if(target < nums[m])
                {
                    j = m;
                    m = ceil((i + j) / 2);
                }
                else if(target == nums[m])
                {
                    return m;
                }
            }
            else if(nums[i] > target)
            {
                return -1;
            }
            else if(target > nums[j])
            {
                return -1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int i = 0, k = nums.size() - 1, j = ceil((k) / 2);
        bool sorted;

        if(nums.size() > 1 && (nums[i] > nums[k]))
        {
            sorted = false;
        }
        else
        {
            sorted = true;
            if(nums.size() == 1)
            {
                if(nums[0] == target) return 0;
                else return -1;
            }
        }

        int pivot{0};
        while(!sorted && (i < j) && (j < k))
        {
            if(nums[j] < nums[pivot]) pivot = j;
            if(nums[j] > nums[k])
            {
                if(nums[k] < nums[pivot]) pivot = k;
                i = j;
                j = ceil((i + k) / 2);
            }
            else if(nums[j] < nums[k])
            {
                k = j;
                j = ceil((i + k) / 2);
            }
        }

        int idx;
        i = 0;
        k = nums.size() - 1;
        idx = binary_search(pivot, k, target, nums);
        if(idx == -1) idx = binary_search(i, pivot - 1, target, nums);

        return idx;
    }
};