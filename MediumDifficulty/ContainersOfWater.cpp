// LeetCode

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104


// Solution

class Solution {
public:
    int area(vector<int>& height, int i, int j)
    {
        return height[i] * abs(j - i);
    }

    int maxArea(vector<int>& height) {
        int max_area = 0;
        int i = 0, j = height.size() - 1;
        
        for(i = 0; i < height.size(); ++i)
        {
            if(i == j) break;
            while(j != i && height[j] < height[i])
            {
                --j;
            }
            max_area = max(max_area, area(height, i , j));
            j = height.size() - 1;
        }

        i = 0;
        for(j = height.size() - 1; j > 0; --j)
        {
            if(i == j) break;
            while(j != i && height[i] < height[j])
            {
                ++i;
            }
            max_area = max(max_area, area(height, j , i));
            i = 0;
        }

        return max_area;
    }
};