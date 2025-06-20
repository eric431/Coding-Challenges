// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length


class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            int window_start {0};
            int window_end {0};
    
            int curr_num {numeric_limits<int>::min()};
    
            priority_queue<pair<int, int>> heap {};
    
            vector<int> sliding_window_max {};
    
            for(; window_end < nums.size(); ++window_end)
            {
                heap.push(make_pair(nums[window_end], window_end));
    
                if (window_end - window_start + 1 == k)
                {
                    while(heap.top().second < window_start)
                    {
                        heap.pop();
                    }
    
                    sliding_window_max.push_back(heap.top().first);
    
                    ++window_start;
                }
            }
    
            return sliding_window_max;
        }
    };