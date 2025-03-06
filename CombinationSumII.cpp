/*

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

*/


class Solution {
    public:
        vector<vector<int>> combination_rcs(int i, int target, vector<int>& candidates)
        {
            if(target - candidates[i] == 0)
            {
                return {{candidates[i]}};
            }
            else if(target - candidates[i] > 0) 
            {
                vector<vector<int>> result {};
                unordered_set<int> visited {};
                for(auto j{i + 1}; j < candidates.size(); ++j)
                {
                    if(!visited.contains(candidates[j]))
                    {
                        visited.insert(candidates[j]);
                        auto v = combination_rcs(j, target - candidates[i], candidates);
                        if(v.size())
                        {
                            for(auto e : v)
                            {
                                e.push_back(candidates[i]);
                                result.push_back(e);
                            }
                        }
                    }
                }
    
                return result;
            }
    
            return {};
        }
    
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> combinations {};
            
            unordered_set<int> visited {};
            for(auto i{0}; i < candidates.size(); ++i)
            {
                if(!visited.contains(candidates[i]))
                {
                    auto tmp = combination_rcs(i, target, candidates);
                    combinations.insert(combinations.end(), tmp.begin(), tmp.end());
                    visited.insert(candidates[i]);
                }
            }
    
            for(auto &v_ : combinations)
            {
                sort(v_.begin(), v_.end());
            }
    
            return combinations;
        }
    };