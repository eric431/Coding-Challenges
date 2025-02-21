class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            vector<int> result;
            if(digits.back() == 9)
            {
                result.resize(digits.size() + 1);
                int carry{1};
                
                for(int i = digits.size() - 1; i > -1; --i)
                {
                    if(digits[i] == 9 && carry == 1)
                    {
                        result[i + 1] = 0;
                    }
                    else if(digits[i] < 9 && carry == 1)
                    {
                        carry = 0;
                        result[i + 1] = digits[i] + 1;
                    }
                    else
                    {
                        result[i + 1] = digits[i];
                    }
                }
                
                if(carry == 1) result[0] = 1;
                else result.erase(result.begin());
                
                return result;
            }
            else
            {
                result = digits;
                ++result.back();
                return result;
            }
        }
};