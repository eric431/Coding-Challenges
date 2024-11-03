class Solution {
public:
    int divide(int dividend, int divisor) {
        int max{numeric_limits<int>::max()};
        int min{numeric_limits<int>::min()};
        bool neg = (dividend < 0) ^ (divisor < 0);

        int abs_dividend{}, abs_divisor{};
        if(dividend == min) abs_dividend = max;
        else abs_dividend = abs(dividend);

        if(divisor == min) abs_divisor = max;
        else abs_divisor = abs(divisor);

        if(abs_divisor == 1)
        {
            // if(!neg && abs_dividend == max) return max;
            if(neg && dividend == min) return min;
            else return neg ? -abs_dividend : abs_dividend;
        }

        if(abs_divisor > abs_dividend)
        {
            return 0;
        }
        else if (abs_divisor < abs_dividend) 
        {
            int prod{abs_divisor};
            int quotient{0};
            while(prod < abs_dividend)
            {
                if(max - abs_divisor >= prod)
                {
                    prod += abs_divisor;
                }
                else 
                {
                    prod = max;
                }

                if(quotient < max)
                {
                    ++quotient;
                }
                else if(quotient == max)
                {
                    if(neg) return min;
                    else if(!neg) return max;
                }
            }
            return neg ? -1 * quotient : quotient;
        }
        else
        {
            return neg ? -1 : 1;
        }
    }
};