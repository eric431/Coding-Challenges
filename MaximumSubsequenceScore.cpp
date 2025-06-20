// You are given two 0-indexed integer arrays nums1 and nums2 of equal length n and a positive integer k. You must choose a subsequence of indices from nums1 of length k.

// For chosen indices i0, i1, ..., ik - 1, your score is defined as:

// The sum of the selected elements from nums1 multiplied with the minimum of the selected elements from nums2.
// It can defined simply as: (nums1[i0] + nums1[i1] +...+ nums1[ik - 1]) * min(nums2[i0] , nums2[i1], ... ,nums2[ik - 1]).
// Return the maximum possible score.

// A subsequence of indices of an array is a set that can be derived from the set {0, 1, ..., n-1} by deleting some or no elements.

 

// Example 1:

// Input: nums1 = [1,3,3,2], nums2 = [2,1,3,4], k = 3
// Output: 12
// Explanation: 
// The four possible subsequence scores are:
// - We choose the indices 0, 1, and 2 with score = (1+3+3) * min(2,1,3) = 7.
// - We choose the indices 0, 1, and 3 with score = (1+3+2) * min(2,1,4) = 6. 
// - We choose the indices 0, 2, and 3 with score = (1+3+2) * min(2,3,4) = 12. 
// - We choose the indices 1, 2, and 3 with score = (3+3+2) * min(1,3,4) = 8.
// Therefore, we return the max score, which is 12.
// Example 2:

// Input: nums1 = [4,2,3,1,1], nums2 = [7,5,10,9,6], k = 1
// Output: 30
// Explanation: 
// Choosing index 2 is optimal: nums1[2] * nums2[2] = 3 * 10 = 30 is the maximum possible score.
 

// Constraints:

// n == nums1.length == nums2.length
// 1 <= n <= 105
// 0 <= nums1[i], nums2[j] <= 105
// 1 <= k <= n

class Solution {
    public:
        struct LesserThan
        {
            bool operator()(int a, int b)
            {
                if (a > b) return true;
                return false;
            }
        };
    
        long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<pair<int, int>> nums3(nums1.size());
    
            for (auto i {0}; i < nums1.size(); ++i)
            {
                nums3[i] = make_pair(nums2[i], nums1[i]);
            }
    
            sort(nums3.begin(), nums3.end(), greater<pair<int, int>>());
    
            priority_queue<int, vector<int>, LesserThan> min_k_heap;
    
            long long curr_sum = 0;
            long long max_sum = 0;
            for (auto i{0}; i < k; ++i)
            {
                curr_sum += nums3[i].second;
    
                min_k_heap.push(nums3[i].second);
            }
    
            max_sum = max(curr_sum * nums3[k - 1].first, max_sum);
    
            for (auto i = k; i < nums3.size(); ++i)
            {
                if (nums3[i].second > min_k_heap.top())
                {
                    min_k_heap.push(nums3[i].second);
    
                    curr_sum += nums3[i].second - min_k_heap.top();
                    min_k_heap.pop();
    
                    max_sum = max(curr_sum * nums3[i].first, max_sum);
                }
            }
    
            return max_sum;
        }
    };