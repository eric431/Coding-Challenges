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
        if(height.size() <= 2) return 0;

        deque<pair<int, int>> local_maxima;
        vector<int> maxima;
        int max_n = 0, num_trap = 0;

        for(auto i = 0; i < height.size(); ++i)
        {
            if(i == 0)
            {
                local_maxima.push_back(move(make_pair(height[i], i)));
            }
            else if((height[i] > height[i - 1]))
            {
                // While loop is important so remember
                while(height[i] > local_maxima.back().first)
                {
                    if(local_maxima.back().first == max_n || local_maxima.empty()) break;
                    local_maxima.pop_back();
                }
                local_maxima.push_back(move(make_pair(height[i], i)));
            }
            max_n = max(max_n, height[i]);
        }

        maxima.resize(local_maxima.size());
        for(int i = local_maxima.size() - 1; i >= 0; --i)
        {
            maxima[i] = move(local_maxima[i].second);
        }

        for(int i = 0, j = 1; j < maxima.size(); ++i, ++j)
        {
            int local_two = height[maxima[j]], local_one = height[maxima[i]];
            int local_max = min(local_one, local_two);
            for(int k = maxima[i]; k < maxima[j]; ++k)
            {
                num_trap += max(local_max - height[k], 0);
            }
        }
        return num_trap;
    }
};