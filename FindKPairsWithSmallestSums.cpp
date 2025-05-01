/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 

Constraints:

1 <= nums1.length, nums2.length <= 105
-109 <= nums1[i], nums2[i] <= 109
nums1 and nums2 both are sorted in non-decreasing order.
1 <= k <= 104
k <= nums1.length * nums2.length

*/

class Solution {
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<vector<int>> k_smallest_pairs;
            // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    
            int i{0};
            int j{0};
    
            int m = nums1.size();
            int n = nums2.size();
    
            set<pair<int, int>> visited;
            priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > k_heap;
    
            k_heap.push({nums1[i] + nums2[j], {i, j}});
            while(!k_heap.empty()){
                auto top = k_heap.top();
                k_heap.pop();
    
                i = top.second.first;
                j = top.second.second;
    
                k_smallest_pairs.push_back({nums1[i], nums2[j]});
                if (k_smallest_pairs.size() == k) break;
    
                if (i + 1 < m && !visited.contains({i + 1, j})) {
                    k_heap.push({nums1[i + 1] +  nums2[j], {i + 1, j}});
                    visited.insert({i + 1, j});
                }
    
                if (j + 1 < n && !visited.contains({i, j + 1})) {
                    k_heap.push({nums1[i] +  nums2[j + 1], {i, j + 1}});
                    visited.insert({i, j + 1});
                }        
            }
    
            return k_smallest_pairs;
        }
    };