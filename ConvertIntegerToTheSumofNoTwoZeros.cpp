/*
No-Zero integer is a positive integer that does not contain any 0 in its decimal representation.

Given an integer n, return a list of two integers [a, b] where:

a and b are No-Zero integers.
a + b = n
The test cases are generated so that there is at least one valid solution. If there are many valid solutions, you can return any of them.

 

Example 1:

Input: n = 2
Output: [1,1]
Explanation: Let a = 1 and b = 1.
Both a and b are no-zero integers, and a + b = 2 = n.
Example 2:

Input: n = 11
Output: [2,9]
Explanation: Let a = 2 and b = 9.
Both a and b are no-zero integers, and a + b = 11 = n.
Note that there are other valid answers as [8, 3] that can be accepted.
 

Constraints:

2 <= n <= 104
*/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto convert_to_vector = [](int n_)
        {
            vector<int> n_vec{};
            int rem = n_;
            while(n_ > 0 || rem > 0)
            {
                rem = n_ % 10;
                n_ /= 10;
                if(rem > 0 || n_ > 0) n_vec.push_back(rem);
            }
            return n_vec;
        };

        auto convert_to_num = [&](vector<int>& num_vec)
        {
            int result{0};
            for(auto i{0}; i < num_vec.size(); ++i)
            {
                result *= 10;
                result += num_vec[i];
            }
            return result;
        };

        auto num = convert_to_vector(n);

        vector<int> summand1{};
        vector<int> summand2{};
        int digit{};
        for(auto i{0}; i < num.size(); ++i)
        {
            if(num[i] == 0 && i + 1 < num.size())
            {
                digit = 10;
                --num[i + 1];
            }
            else digit = num[i];

            if(digit == 0) break;

            for(int el{1}; el < 10; ++el)
            {
                if(digit - el > 0)
                {
                    summand1.push_back(digit - el);
                    summand2.push_back(el);
                    break;
                }
                else if(el == 1 && digit - el <= 0)
                {
                    digit += 10;
                    if(i + 1 < num.size()) --num[i + 1];
                    else if (i + 1 == num.size())
                    {
                        summand1.back() += 10;
                        break;
                    }
                }
            }
            digit = 0;
        }

        ranges::reverse(summand1);
        int x1 = convert_to_num(summand1);

        ranges::reverse(summand2);
        int x2 = convert_to_num(summand2);

        vector<int> sum{x1, x2};

        return sum;
    }
};