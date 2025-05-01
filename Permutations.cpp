// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

class Solution {
    public:
        int n;
        unordered_set<int> visited;
        vector<int> m_nums;
        vector<vector<int>> permutations;
    
        void permutations_rcs(vector<int>& vec) {
            if (visited.size() == m_nums.size()) {
                permutations.push_back(vec);
                return;
            }
    
            for (auto i{0}; i < n; ++i) {
    
                if (!visited.contains(i)) {
                    visited.insert(i);
                    vec.push_back(m_nums[i]);
    
                    permutations_rcs(vec);
    
                    vec.pop_back();
                    visited.erase(i);
                }
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            n = nums.size();
            m_nums = nums;
    
            vector<int> vec {};
    
            permutations_rcs(vec);
    
            return permutations;
        }
    };