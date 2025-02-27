class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> product_vec (nums.size());
    
            int num_zero {0};
            int prod {1};
            for(auto i {0}; i < nums.size(); ++i)
            {
                if(nums[i] != 0) prod *= nums[i];
                else if(nums[i] == 0)
                {
                    if (num_zero) 
                    {
                        return product_vec;
                    }
                    ++num_zero;
                }
            }
    
            for(auto i{0}; i < nums.size(); ++i)
            {
                if(nums[i] && num_zero)
                    product_vec[i] = 0;
                else if(nums[i] && !num_zero)
                    product_vec[i] = prod / nums[i];
                else if(!nums[i])
                    product_vec[i] = prod;
            }
    
            return product_vec;
        }
    };