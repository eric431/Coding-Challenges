// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
 

// Constraints:

// 1 <= piles.length <= 104
// piles.length <= h <= 109
// 1 <= piles[i] <= 109

class Solution {
    public:
        int num_hrs(int k, vector<int> piles_)
        {
            long h {0};
    
            for(auto &pile : piles_)
            {
                h += pile / k + ((pile % k) != 0);
            }
    
            return h;
        }
    
        int minEatingSpeed(vector<int>& piles, int h) {
            long k_lo = 1;
            long k_hi = *(max_element(piles.begin(), piles.end()));
            long k_mid = {};
    
            if(num_hrs(k_lo, piles) == h) return k_lo;
    
            while(k_lo < k_hi)
            {
                k_mid = k_lo + (k_hi - k_lo) / 2;
    
                int h_mid = num_hrs(k_mid, piles);
    
                if(h_mid <= h)
                {
                    k_hi = k_mid;
                }
                else if(h_mid > h)
                {
                    k_lo = k_mid + 1;
                }
            }
    
            return k_hi;
        }
    };