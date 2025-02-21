/*
Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

As the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
Output: 20
Explanation: 
Enumerating by the values (arr[i], arr[j], arr[k]):
(1, 2, 5) occurs 8 times;
(1, 3, 4) occurs 8 times;
(2, 2, 4) occurs 2 times;
(2, 3, 3) occurs 2 times.
Example 2:

Input: arr = [1,1,2,2,2,2], target = 5
Output: 12
Explanation: 
arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
We choose one 1 from [1,1] in 2 ways,
and two 2s from [2,2,2,2] in 6 ways.
Example 3:

Input: arr = [2,1,3], target = 6
Output: 1
Explanation: (1, 2, 3) occured one time in the array so we return 1.
 

Constraints:

3 <= arr.length <= 3000
0 <= arr[i] <= 100
0 <= target <= 300
*/

class Solution {
    public:
        const static int mod = 1e9 + 7;
    
        int threeSumMulti(vector<int>& arr, int target) {
            auto choose = [](int n, int r)
            {
                long nom {1};
                for(auto i{n - r + 1}; i <= n; ++i)
                    nom *= i;
    
                long denom {1};
                for(auto i{1}; i <= r; ++i)
                    denom *= i;
    
                int ans = (nom / denom) % mod;
                return static_cast<int>(ans);
            };
    
            // initialise target map
            unordered_map<int, int> target_map{};
            vector<int> arr_ {};
            for(auto i{0}; i < arr.size(); ++i)
            {
                if(!target_map.contains(arr[i])) arr_.push_back(arr[i]);
                ++target_map[arr[i]];
            }
    
            sort(arr_.begin(), arr_.end());
    
            if(arr_.size() == 1 && 3 * arr_[0] == target) return choose(target_map[arr_[0]], 3);
    
            int i {0};
            int k = arr_.size() - 1;
            int cnt {0};
            while(i <= k)
            {
                for(int j = k; j >= i; --j)
                {
                    int third_number = target - (arr_[i] + arr_[j]);
    
                    if(target_map[arr_[j]] > 2 && third_number == arr_[j] && third_number == arr_[i]) 
                    {
                        cnt += choose(target_map[arr_[j]], 3);
                    }
                    else if(target_map.contains(third_number) && third_number >= arr_[i] && third_number <= arr_[j] && i != j)
                    {
                        if(third_number == arr_[i])
                        {
                            cnt += choose(target_map[arr_[i]], 2) * target_map[arr_[j]];
                        }
                        else if(third_number == arr_[j])
                        {
                            cnt += choose(target_map[arr_[j]], 2) * target_map[arr_[i]];
                        }
                        else
                        {
                            cnt += (target_map[third_number] * target_map[arr_[i]] * target_map[arr_[j]]);
                        }
                    }
                    cnt %= mod;
                }
                ++i;
            }
    
            return cnt;
        }
    };