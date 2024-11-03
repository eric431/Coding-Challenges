/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency
 of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []
 

Constraints:

1 <= candidates.length <= 30
2 <= candidates[i] <= 40
All elements of candidates are distinct.
1 <= target <= 40
*/

class Solution {
public:
    vector<vector<int>> subCombinationSum(const vector<int>& candidates, int target)
    {
        vector<vector<int>> solution{};

        vector<int> combination{};
        vector<int> valid_subvector{};

        set<vector<int>> visited_combinations{};
        for(auto i = 0; i < candidates.size(); ++i)
        {
            if(candidates[i] == target)
            {
                combination.push_back(candidates[i]);
                if(visited_combinations.count(combination) == 0)
                {
                    visited_combinations.insert(combination);
                    solution.emplace_back(move(combination));
                }
                combination.clear();

                break;
            }
            else if(candidates[i] < target)
            {
                valid_subvector.push_back(move(candidates[i]));
            }
        }

        int new_target{0};
        vector<vector<int>> sub_combinations{};
        for(int i = 0; i < valid_subvector.size(); ++i)
        {
            new_target = target - valid_subvector[i];
            sub_combinations = subCombinationSum(valid_subvector, new_target);

            for(auto el : sub_combinations)
            {
                if(el.size() > 0)
                {
                    el.emplace_back(valid_subvector[i]);
                    sort(el.begin(), el.end());
                    if(visited_combinations.count(el) == 0)
                    {
                        visited_combinations.insert(el);
                        solution.emplace_back(move(el));
                    }
                }
            }
        }

        return solution;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> solution{};
        if(target < candidates[0])
        {
            return solution;
        }
        solution = subCombinationSum(candidates, target);
        
        return solution;
    }
};