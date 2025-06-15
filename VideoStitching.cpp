class Solution {
    public:
        unordered_map<int, int> memo;
        unordered_map<int, set<vector<int>>> clip_map;
        int time;
    
        int dp(int c_start){
            if(memo.contains(c_start)){
                return memo[c_start];
            }
    
            auto r_itr = clip_map[c_start].rbegin();
            auto curr_clip = *r_itr;
    
            if(curr_clip[2] >= time){
                return 1;
            }
    
            int curr_min = 100;
            for(auto curr = curr_clip[2]; curr > curr_clip[1]; --curr){
                if(clip_map.contains(curr)){ curr_min = min(dp(curr), curr_min); }
            }
    
            return memo[c_start] = 1 + curr_min;       
        }
    
        int videoStitching(vector<vector<int>>& clips, int time) {
            bool solvable = false;
    
            this->time = time;
            for (auto &clip : clips){
                if(clip[1] >= time){ solvable = true; }
                clip_map[clip[0]].insert({clip[1] - clip[0], clip[0], clip[1]});
            }
    
            if(!clip_map.contains(0) || !solvable){
                return -1;
            }
    
            auto result = dp(0);
    
            return result < 100 ? result : -1;
        }
    };