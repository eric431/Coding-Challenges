// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000
// It's guaranteed that you can reach nums[n - 1].


class Solution {
    public:
        int jump(vector<int>& nums) {
            int n = nums.size();
            int i{0};
            priority_queue<vector<int>> jump_q{};
    
            jump_q.push({nums[0], 0, 0});
            vector<bool> visited(nums.size(), false);
    
            visited[0] = true;
            while(!jump_q.empty()) {
                auto top = jump_q.top();
                jump_q.pop();
    
                int j = top[0];
                int i = top[1];
    
                for(; i <= j; ++i)
                {
                    if (i == n - 1) 
                        return top[2] + 1 * (i > top[1]);
    
                    if (visited[i]) 
                        continue;
                    else {
                        visited[i] = true;
                        jump_q.push({i + nums[i], i, top[2] + 1});
                    }
                }
            }
    
            return -1;
        }
    };