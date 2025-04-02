// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0
 

// Constraints:

// 0 <= left <= right <= 231 - 1

class Solution {
    public:
        int rangeBitwiseAnd(int left, int right) {
            if (left == right) return left;
    
            bitset<32> left_b(left);
            bitset<32> right_b(right);
            
            int result {0};
    
            int msb {0};
            for (auto i{32}; i >= 0; --i) {
                if ((left_b[i] && right_b[i]) == 1) {
                    while (left_b[i] == right_b[i]){
                        result += ((1 << i) * right_b[i]);
                        --i;
                    }
                    break;
                }
                else if ( (left_b[i] ^ right_b[i]) == 1) {
                    return 0;
                }
            }
    
            return result;
        }
    };