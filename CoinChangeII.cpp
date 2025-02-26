// This needs to be revisited due to poor understanding of algorithm
// Try to implement with bottom up approach

class Solution {
public:
    int count_coins_rcs(int i, int amount, vector<int>& coins, vector<vector<int>>& memo)
    {
        if(!amount) return 1;
        else if(i == coins.size() || coins[i] > amount) return 0;
        else if(memo[i][amount] != -1) return memo[i][amount];

        return memo[i][amount] = count_coins_rcs(i, amount - coins[i], coins, memo) + count_coins_rcs(i + 1, amount, coins, memo);

    }

    int change(int amount, vector<int>& coins) {
        if(amount == 0) return 1;

        sort(coins.begin(), coins.end());

        vector<int> cols(amount + 1, -1);
        vector<vector<int>> memo(coins.size(), cols);

        return count_coins_rcs(0, amount, coins, memo);
    }
};