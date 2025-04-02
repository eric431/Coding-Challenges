// Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 

// Example 1:

// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.
// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.
// Example 3:

// Input: n = 0
// Output: 0
 

// Constraints:

// 0 <= n <= 104
 

class Solution {
    public:
        void find_num_times_divisible(int n, int x, unordered_map<int, int>& prime_map) {
            while(n > 0) {
                if (n % x == 0) {
                    ++prime_map[x];
                    n /= x;
                } else {
                    break;
                }
            }
        }
    
        int trailingZeroes(int n) {
            unordered_map<int, int> prime_map;
    
            while(n > 0){
                if (n % 2 == 0) {
                    find_num_times_divisible(n, 2, prime_map);
                } 
                
                if (n % 5 == 0) {
                    find_num_times_divisible(n, 5, prime_map);
                }
    
                --n;
            }
    
            return min(prime_map[5], prime_map[2]);
        }
    };