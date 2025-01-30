/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]
Example 2:

Input: prices = [1]
Output: 0
 

Constraints:

1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<int> cooldown(2);
        vector<vector<int>> holding(2, cooldown);
        vector<vector<vector<int>>> dp(n + 1, holding);
        
        int doNothing{0};
        int doSomething{0};
        for(int i{n - 1}; i > -1; --i)
        {
            for(auto h{0}; h < 2; ++h)
            {
                for(auto c{0}; c < 2; ++c)
                {
                    doNothing = dp[i + 1][h][0];
                    if(h == 0 && c == 0)
                    {
                        // you can buy stocks
                        doSomething = dp[i + 1][1][0] - prices[i];
                    }
                    else if(h == 1 && c == 0)
                    {
                        // you can sell stocks
                        doSomething = dp[i + 1][0][1] + prices[i];
                    }
                    else if(c == 1)
                    {
                        // you have to do nothing
                        doSomething = dp[i + 1][h][0];
                    }
                    
                    dp[i][h][c] = max(doNothing, doSomething);
                }
            }
        }
        
        return dp[0][0][0];
    }
};