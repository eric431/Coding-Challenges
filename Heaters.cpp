class Solution {
    public:
        int findRadius(vector<int>& houses, vector<int>& heaters) {
            sort(heaters.begin(), heaters.end());
            sort(houses.begin(), houses.end());
    
            auto min_rad = [&](int d, vector<int>& houses, vector<int>& heaters){
                int j = 0;
                for(auto i{0}; i < heaters.size(); ++i){
                    if ((heaters[i] - d) > houses[j]){
                        return false;
                    } else if((heaters[i] + d) >= houses.back()){
                        return true;
                    }
    
                    auto lb2 = upper_bound(houses.begin(), houses.end(), heaters[i] + d);
                    j = (lb2 - houses.begin()) + (*lb2 == (heaters[i] + d));
                }
    
                return false;
            };
    
            int lo = 0;
            int hi = 1e9;
            int mid = (lo + hi) / 2;
    
            while(lo < hi){
                if(min_rad(lo, houses, heaters)){
                    return lo;
                } else if(min_rad(mid, houses, heaters)){
                    lo += 1;
                    hi = mid;
                } else if(min_rad(hi, houses, heaters)){
                    lo = mid + 1;
                }
                mid = (lo + hi) / 2;
            }
    
            return lo;
        }
    };