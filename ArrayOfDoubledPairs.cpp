/*
Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

Example 1:

Input: arr = [3,1,3,6]
Output: false
Example 2:

Input: arr = [2,1,2,6]
Output: false
Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
 

Constraints:

2 <= arr.length <= 3 * 104
arr.length is even.
-105 <= arr[i] <= 105
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> arr_map{};
        for(auto i{0}; i < arr.size(); ++i)
            ++arr_map[arr[i]];

        for(auto& [k, v] : arr_map)
        {
            if(k != 0 && arr_map.contains(2 * k))
            {
                if(v >= arr_map[2 * k])
                {
                    v -= arr_map[2 * k];
                    arr_map[2 * k] = 0;
                }
                else
                {
                    arr_map[2 * k] -= v;
                    v = 0;
                }
            }
            else if(k == 0 && v % 2 == 0) v = 0;
        }

        for(auto& [k, v] : arr_map)
            if(v != 0) return false;

        return true;
    }
};