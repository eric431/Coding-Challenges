// Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

// Example 1:

// Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// Output: 2
// Explanation:
// The two tuples are:
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
// Example 2:

// Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// Output: 1
 

// Constraints:

// n == nums1.length
// n == nums2.length
// n == nums3.length
// n == nums4.length
// 1 <= n <= 200
// -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

class Solution {
public:   
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> AB_sum;
        map<int, int> CD_sum;
        
        for(auto i = 0; i<nums1.size(); i++)
        {
            for(auto j = 0; j<nums3.size(); j++)
            {
                AB_sum[nums1[i] + nums2[j]]++;
                CD_sum[nums3[i] + nums4[j]]++;
            }
        }
        
        int cnt = 0;
        
        for(auto& [key, val] : AB_sum)
        {
            if(CD_sum.contains(-1*key))
            {
                cnt+=val * (CD_sum[-1*key]);
            }
        }
        return cnt;
    }
};