class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = numeric_limits<int>::max();
        int best_sell = numeric_limits<int>::min();
        int max_profit{0};
        int curr_profit{0};
        for(auto i{0}; i < prices.size(); ++i)
        {
            best_buy = min(prices[i], best_buy);
            if(best_buy == prices[i])
            {
                best_sell = 0;
                continue;
            }
            
            best_sell = max(prices[i], best_sell);
            curr_profit = max(best_sell - best_buy, 0);
            max_profit = max(curr_profit, max_profit);
        }

        return max_profit;
    }
};