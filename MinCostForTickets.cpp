class Solution {
    public:
        int min_cost;
        vector<int> days;
        vector<int> costs;
        vector<int> memo;
        unordered_map<int, int> pass_allowance;
        
        int find_min_tickets(int d){
            if (d > days.back()) { return 0; }
            
            d = *(lower_bound(days.begin(), days.end(), d));
            
            if(memo[d] != -1){ return memo[d]; }
            
            int min_tickets = numeric_limits<int>::max();
            for (auto i{0}; i < 3; ++i) {
                int next_d = d + pass_allowance[i];
                min_tickets = min(min_tickets, costs[i] + find_min_tickets(next_d));
            }
            
            return memo[d] = min_tickets;
        }
        
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            this->min_cost = numeric_limits<int>::max();
            this->days = days;
            this->costs = costs;
            this->memo.resize(366, -1);
            this->pass_allowance = {{0, 1}, {1, 7}, {2, 30}};
            
            return find_min_tickets(days[0]);
        }
    };