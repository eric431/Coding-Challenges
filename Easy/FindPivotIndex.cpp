class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>  prefix_sums (nums.size());
        
        // initiailise the prefix sums vector
        for(auto i{0}; i < nums.size(); ++i)
        {
            if(i == 0) prefix_sums[i] = nums[i];
            else prefix_sums[i] = nums[i] + prefix_sums[i - 1];
        }
        
        for(auto i{0}; i < nums.size(); ++i)
        {
            if(prefix_sums[i] - nums[i] == prefix_sums.back() - prefix_sums[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};