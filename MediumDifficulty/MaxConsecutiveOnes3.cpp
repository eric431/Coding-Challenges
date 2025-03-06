// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int window_start {0};
            int window_end {0};
            int num_flipped {0};
            int consecutive_ones {0};
            int max_consecutive_ones {0};
    
            vector<bool> visited(nums.size());
            for(; window_end < nums.size(); ++window_end)
            {
                if(!nums[window_end] && num_flipped < k)
                {
                    ++num_flipped;
    
                    visited[window_end] = 1;
    
                    nums[window_end] = 1;
                }
                else if(!nums[window_end] && num_flipped == k)
                {
                    int i = window_start;
                    for(; window_start < window_end; ++window_start)
                    {
                        consecutive_ones = max(--consecutive_ones, 0);
                        if(visited[window_start])
                        {
                            num_flipped = max(--num_flipped, 0);
                            ++window_start;
                            break;
                        }
                    }
    
                    if(num_flipped < k)
                    {
                        nums[window_end] = 1;
                        visited[window_end] = 1;
                        ++num_flipped;
                    }
                }
    
                if(nums[window_end])
                    ++consecutive_ones;
    
                max_consecutive_ones = max(consecutive_ones, max_consecutive_ones);
            }
    
            return max_consecutive_ones;
        }
    };