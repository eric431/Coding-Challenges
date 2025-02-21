class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int, int>> nums_pair(nums.size());
            
        for(auto i {0}; i < nums.size(); ++i)
        {
            nums_pair[i] = make_pair(nums[i], i);
        }
        
        sort(nums_pair.begin(), nums_pair.end());
        
        int max = nums_pair.back().first;
        for(int i = nums.size() - 1; i > -1; --i)
        {
            if(nums_pair[i].first != max && 2 * nums_pair[i].first <= max)
            {
                int tmp = nums_pair[i].first;
                for(; i > -1 && nums_pair[i].first == tmp; --i) ;
                return nums_pair.back().second;
            }
            else if(nums_pair[i].first != max && 2 * nums_pair[i].first > max)
            {
                return -1;
            }
        }
        
        return nums_pair.back().second;
    }
};