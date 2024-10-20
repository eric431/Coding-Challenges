// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> three_sum;
        map<int, int> pos_map, neg_map;

        set<int> tmp;
        set<set<int>> unique_sums;

        for(auto el : nums)
        {
            if(el >= 0) ++pos_map[el];
            else ++neg_map[el];
        }

        if(pos_map.count(0) != 0 && pos_map[0] >= 3)
        {
            vector<int> sum = {0, 0, 0};
            three_sum.emplace_back(sum);
        } 

        for(auto itr1 = neg_map.begin(); itr1 != neg_map.end(); ++itr1)
        {
            for(auto itr2 = pos_map.begin(); itr2 != pos_map.end(); ++itr2)
            {
                int two_sum_c = -1 * (itr1->first + itr2->first);
                bool cond = (two_sum_c == itr1->first && itr1->second > 1) || (two_sum_c == itr2->first && itr2->second > 1) || (two_sum_c != itr1->first && two_sum_c != itr2->first) && (neg_map.count(two_sum_c) != 0 || pos_map.count(two_sum_c) != 0);

                if(cond)
                {
                    tmp = {itr1->first, itr2->first, two_sum_c};
                    if(unique_sums.count(tmp) != 0) continue;

                    vector<int> triplet = {itr1->first, itr2->first, two_sum_c};
                    three_sum.emplace_back(move(triplet));

                    unique_sums.insert(move(tmp));
                }  
            }            
        }

        return three_sum;
    }
};