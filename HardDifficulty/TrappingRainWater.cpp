/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int max_trap = 0;

        int n = height.size();
        vector<int> left(n, -1);
        vector<int> right(n, -1);

        left[0] = height[0];
        right[n - 1] = height[n - 1];
        for (auto h {1}; h < n; ++h){
            left[h] = max(height[h], left[h - 1]);
            right[n - h - 1] = max(height[n - h - 1], right[n - h]);
        }

        for (int i{0}; i < n; ++i){
            max_trap += min(left[i], right[i]) - height[i];
        }

        return max_trap;
    }
};