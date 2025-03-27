// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

// Example 1:


// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        int maxLevelSum(TreeNode* root) {
            queue<pair<TreeNode*, int>> level_q {};
    
            unordered_map<int, int> level_sum {};
    
            level_q.push(make_pair(root, 1));
    
            while(!level_q.empty())
            {
                auto front = level_q.front();
                level_q.pop();
    
                if(level_sum.contains(front.second))
                {
                    level_sum[front.second] += front.first->val;
                }
                else
                {
                    level_sum[front.second] = front.first->val;
                }
    
                if(front.first->left)
                {
                    level_q.push(make_pair(front.first->left, front.second + 1));
                }
    
                if(front.first->right)
                {
                    level_q.push(make_pair(front.first->right, front.second + 1));
                }
    
            }
    
            int max_sum = numeric_limits<int>::min();
            int result_idx {-1};
            for(auto &[k, v] : level_sum)
            {
                if(v > max_sum)
                {
                    max_sum = v;
                    result_idx = k;
                }
                else if (v == max_sum && k < result_idx)
                {
                    result_idx = k;
                }
            }
    
            return result_idx;
        }
    };