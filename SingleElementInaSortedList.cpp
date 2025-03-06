// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105


class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
    
            int n = nums.size() - 1;
    
            if (nums[0] != nums[1]) return nums[0];
            else if (nums[n] != nums[n - 1]) 
            {
                return nums[n];
            }
    
            for(auto i{2}; i < nums.size(); i += 2)
            {
                if(nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) return nums[i];
            }
    
            return 1;
        }
    };