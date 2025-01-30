/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount + 1, numeric_limits<int>::max());
        dp[amount] = 0;
        
        for(int a = amount; a > -1; --a)
        {
            for(int c = coins.size() - 1; c > -1; --c)
            {
                if(dp[a] == numeric_limits<int>::max()) continue;
                int a_ = a - coins[c];

                if(a_ >= 0)
                    dp[a_] = min(dp[a_], 1 + dp[a]);
            }  
        }
      
        if(dp[0] == numeric_limits<int>::max()) return -1;
        return dp[0];
    }
};