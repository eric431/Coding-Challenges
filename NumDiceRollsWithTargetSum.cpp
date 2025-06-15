class Solution {
    public:
        int mod;
        int num_rolls;
        int k;
        int n;
        vector<vector<int>> memo;
        
        int dp(int i, int target) {
            if (i == n) {
                return (target == 0);
            } else if (target < 0) {
                return 0;
            }
            
            if(memo[i][target] != -1) return memo[i][target];
                    
            long cnt{0};
            for(int k_i {1}; k_i <= k; ++k_i) {
                cnt += dp(i + 1, target - k_i);
                cnt %= mod;
            }
            
            return memo[i][target] = static_cast<int>(cnt);
        }
        
        int numRollsToTarget(int n, int k, int target) {
            this->mod = 1e9 + 7;
            this->k = k;
            this->n = n;
            this->memo.resize(n, vector<int>(target + 1, -1));
            
            return dp(0, target);
        }
    };