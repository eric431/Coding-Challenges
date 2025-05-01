// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n


class Solution {
    public:
        vector<vector<int>> combinations;
    
        // void combine_rcs(int i, int n, int k, vector<int>& combination) {
        void combine_rcs(int i, int n, int k) {
            if (i > n) {
                vector<vector<int>> swap_tmp;
                for (auto &v : combinations) {
                    if (v.size() == k) { swap_tmp.push_back(move(v)); }
                } 
                swap(combinations, swap_tmp);
                return;
            }
    
            vector<vector<int>> swap_tmp;
            for (auto &v : combinations) {
                if (v.size() + 1 <= k) {
                    auto tmp = v;
                    tmp.push_back(i);
    
                    swap_tmp.push_back(move(tmp));
                }
                swap_tmp.push_back(move(v));
            }
            swap_tmp.push_back({i});
    
            swap(combinations, swap_tmp);
    
            combine_rcs(i + 1, n, k);
        }
    
        vector<vector<int>> combine(int n, int k) {
            combinations = {};
    
            vector<int> combination{};
            combine_rcs(1, n, k);
    
            return combinations;
        }
    };