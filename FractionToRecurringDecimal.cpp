// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
 

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if(numerator == 0) return "0";
    
            auto long_division = [&](long numerator, long denominator)
            {
                unordered_map<long, pair<int, int>> division_table;
    
                bool sign = (numerator < 0) ^ (denominator < 0);
                long rem {};
                string num = "";
                string fraction  = "";
    
                numerator = abs(numerator);
                denominator = abs(denominator);
    
                long integer = numerator / denominator;
    
                num = to_string(integer);
                rem = numerator % denominator;
    
                int i {0};
    
                while(rem)
                {
                    rem *= 10;
    
                    int f = rem / denominator;
                    fraction += f + '0';
    
                    if(division_table.count(rem) && (rem % denominator != 0))
                    {
                        auto first = division_table[rem].first;
                        division_table[rem].second = i;
    
                        fraction = fraction.substr(0, first) + "(" + fraction.substr(first, i - first) + ")";
                        break;
                    }
                    else
                    {
                        division_table[rem].first = i;
                    }
    
                    if(f) 
                        rem %= denominator;
    
                    ++i;
                }
    
                string result = "";
                if(sign) result += "-";
    
                result += num;
    
                if (fraction != "")
                    return result + "." + fraction;
                else
                    return result;
            };
    
            return long_division(numerator, denominator);
        }
    };