class Solution {
    public:
        vector<int> houses_;
        // vector<int> memo;
        
        // vector<vector<int>> memo;
        // vector<vector<int>> cost_;
        vector<vector<pair<int, int>>> cost_;
    
        int m_;
        int n_;
        
        bool target_reached{false};
        
        int create_neighborhood(int h, int target)
        {
            if(h >= m_){
                target_reached = (target == 1);
                return target == 1 ? 0 : 1000001;   
            }
            
            // if(target_reached && memo[h] != -1) return memo[h];
            // if(memo[h][target - 1] != -1) return memo[h];
            
            if(houses_[h] != 0)
            {
                // if(h > 0 && houses_[h - 1] == houses_[h]) return memo[h] = create_neighborhood(h + 1, target);
                // else return memo[h] = create_neighborhood(h + 1, target - 1 * (h > 0));
                
                int ans{};
                if(h > 0 && houses_[h - 1] == houses_[h]) ans = create_neighborhood(h + 1, target);
                else ans = create_neighborhood(h + 1, target - 1 * (h > 0));
                
                // if(target_reached){
                //     memo[h][target - 1] = ans;
                //     // target_reached = false;
                // }
                
                return ans;
            }
            else
            {
                int chosen_c {numeric_limits<int>::max()};
                for(auto c{0}; c < n_; ++c)
                {
                    houses_[h] = c + 1;
                    
                    if(h > 0 && c + 1 == houses_[h - 1]){
                        chosen_c = min(chosen_c, cost_[h][c] + create_neighborhood(h + 1, target));
                    }
                    else {
                        chosen_c = min(chosen_c, cost_[h][c] + create_neighborhood(h + 1, target - 1 * (h > 0)));
                    }
                }
                
                houses_[h] = 0; // backtrack
                
                // int ans{};
                // if(target_reached){
                //     memo[h][target - 1] = chosen_c;   
                // }
                
                return chosen_c;
            }
        }
        
        int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
            this->houses_ = houses;
            // this->memo.resize(houses.size(), -1);
            // this->memo.resize(houses.size(), vector<int>(target, -1));
    
            
            this->cost_ = cost;
            
            for(auto &v : cost)
            {
                vector<pair<int, int>> tmp(v.size());
                for(auto i{0}; i < v.size(); ++i)
                {
                    tmp[i] = make_pair(v[i], i + 1);
                }
                sort(tmp.begin(), tmp.end());
                this->cost_.push_back(tmp);
            }
            
            this->m_ = m;
            this->n_ = n;
            
            auto min_cost = create_neighborhood(0, target);
            
            return min_cost < 1000000 ? min_cost : -1;
        }
    };