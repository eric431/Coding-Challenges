/*
Given an integer array nums, find a 
subarray
 that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 

Constraints:

1 <= nums.length <= 2 * 104
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> prefix_products(nums.size());
        int contiguous_prod{1};
        int largest_prod{-11};

        int num_neg = 0;
        int j{0}, i{0};
        for(; i < nums.size(); ++i)
        {
            largest_prod = max(largest_prod, nums[i]);

            if(nums[i] == 0)
            {
                if(num_neg > 1 && prefix_products[i - 1] < 0)
                {
                    int tmp = prefix_products[i - 1] / prefix_products[j];
                    largest_prod = max(largest_prod, tmp);
                }
                else if(num_neg == 1 && j != i - 1)
                {
                    int tmp = prefix_products[i - 1] / prefix_products[j];
                    largest_prod = max(largest_prod, tmp);                    
                }

                num_neg = 0;
                prefix_products[i] = 0;
                contiguous_prod = 1;
            }
            else
            {
                contiguous_prod *= nums[i];
                prefix_products[i] = contiguous_prod;

                if(nums[i] < 0) 
                {
                    ++num_neg;
                    if(num_neg == 1) j = i;
                }
            }
            largest_prod = max(largest_prod, prefix_products[i]);
        }

        if(j != i - 1 && prefix_products[i - 1] < 0)
        {
            int tmp = prefix_products[i - 1] / prefix_products[j];
            largest_prod = max(largest_prod, tmp);
        }
        return largest_prod;
    }
};