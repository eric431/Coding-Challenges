/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
 

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104
*/

class Solution {
public:
    struct pointers
    {
        int i, j, k;
        pointers(int a, int b, int c) : i(a), j(b), k(c) {}
    };

    void update_cs(int& cval, int& sum, int& target, pointers &ptr)
    {
        if(abs(sum - target) < abs(cval - target)) cval = sum;
    }

    // function called when the sum is less than the target value 
    void cond_1(vector<int>& nums, int& target, pointers &ptr, int& cval, int &sum)
    {
        sum = nums[ptr.i] + nums[ptr.j] + nums[ptr.k];
        update_cs(cval, sum, target, ptr);
        while(sum < target && ptr.i < ptr.j - 1)
        {
            ++ptr.i;
            sum = nums[ptr.i] + nums[ptr.j] + nums[ptr.k];
            update_cs(cval, sum, target, ptr);
        }

        if(ptr.i == ptr.j - 1)
        {
            ++ptr.j;
            if(ptr.i < ptr.j && ptr.j < ptr.k)
            {
                for(auto j2 = ptr.j; j2 < ptr.k; ++j2)
                {
                    sum = nums[ptr.i] + nums[j2] + nums[ptr.k];
                    if(sum > target) break;
                    update_cs(cval, sum, target, ptr);
                }
            }
        }
    }

    // function called when the sum is greater than the target value 
    void cond_2(vector<int>& nums, int& target, pointers &ptr, int& cval, int &sum)
    {
        sum = nums[ptr.i] + nums[ptr.j] + nums[ptr.k];
        update_cs(cval, sum, target, ptr);
        while(sum > target && ptr.j > ptr.i + 1)
        {
            --ptr.j;
            sum = nums[ptr.i] + nums[ptr.j] + nums[ptr.k];
            update_cs(cval, sum, target, ptr);
        }

        if(ptr.j == ptr.i + 1)
        { 
            --ptr.k;
            if(ptr.i < ptr.j && ptr.j < ptr.k)
            {
                sum = nums[ptr.i] + nums[ptr.j] + nums[ptr.k];
                update_cs(cval, sum, target, ptr);
            }
        }
    }

    int closest_sum(vector<int>& nums, int& target)
    {
        // intialise pointers
        int i = 0, j = nums.size() / 2, k = nums.size() - 1;
        int sum{nums[i] + nums[j] + nums[k]};
        int cval = sum;
        pointers ptr(i, j, k);

        while(ptr.i < ptr.j && ptr.j < ptr.k)
        {
            if(sum < target)
            {
                cond_1(nums, target, ptr, cval, sum);
            }
            else if(sum > target)
            {
                cond_2(nums, target, ptr, cval, sum);
            }

            if(cval == target) break;
        }
        return cval;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());
        return closest_sum(nums, target);
    }
};