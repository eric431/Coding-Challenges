// Leetcode
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

// Constraints:

// -231 <= x <= 231 - 1

// Medium

class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        if(x > 0)
        {
            int last_digit = numeric_limits<int>::max() % 10;
            int max_excluding_last_digit = numeric_limits<int>::max() / 10;
            int reversed_x = 0, rem;
            while(x > 9)
            {
                rem = x % 10;
                x /= 10;
                reversed_x *= 10;
                reversed_x += rem;
            }
            if (reversed_x < max_excluding_last_digit || (reversed_x == max_excluding_last_digit && x <= last_digit))
            {
                return ((reversed_x *= 10) + x);
            }
            return 0;
        }
        else
        {
            int min = numeric_limits<int>::min();
            int last_digit = min % 10;
            int min_excluding_last_digit = min / 10;
            int reversed_x = 0, rem;
            while(x < -9)
            {
                rem = x % 10;
                x /= 10;
                reversed_x *= 10;
                reversed_x += rem;
            }
            if (reversed_x > min_excluding_last_digit || (reversed_x == min_excluding_last_digit && x >= last_digit))
            {
                return (reversed_x *= 10) + x;
            }
            return 0;
        }
    }
};