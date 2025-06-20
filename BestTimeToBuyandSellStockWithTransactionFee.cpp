// You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

// Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

// Note:

// You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
// The transaction fee is only charged once for each stock purchase and sale.
 

// Example 1:

// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
// Example 2:

// Input: prices = [1,3,7,5,10,3], fee = 3
// Output: 6
 

// Constraints:

// 1 <= prices.length <= 5 * 104
// 1 <= prices[i] < 5 * 104
// 0 <= fee < 5 * 104

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
    
            vector<vector<int>> dp(n + 1, vector<int>(2));
    
            int do_something{0};
            int do_nothing{0};
            for(auto i = n - 1; i > -1; --i)
            {
                for(auto h{0}; h < 2; ++h)
                {
                    // do nothing
                    auto do_nothing = dp[i + 1][h];
                    
                    // do something
                    if(!h)
                    {
                        do_something = dp[i + 1][1] - (prices[i] + fee);
                    }
                    else
                    {
                        do_something = dp[i + 1][0] + prices[i];
                    }
    
                    dp[i][h] = max(do_nothing, do_something);
                }
            }
    
            return dp[0][0];
        }
    };