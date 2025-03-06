// Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

// The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

// Example 1:


// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
// Example 2:

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3
 

// Constraints:

// The number of nodes in the tree is in the range [0, 1000].
// -109 <= Node.val <= 109
// -1000 <= targetSum <= 1000


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
        int pathSum(TreeNode* root, int targetSum) {
            if(!root) return 0;
    
            stack<pair<TreeNode*, vector<long>>> dfs_stack;
            vector<vector<long>> paths {};
    
            vector<long> v {root->val};
            pair<TreeNode*, vector<long>> root_pair = make_pair(root, v);
            dfs_stack.push(root_pair);
    
            int cnt {0};
            if(root->val == targetSum) ++cnt;
    
            while(!dfs_stack.empty())
            {
                auto top = dfs_stack.top();
                auto& root = top.first;
                auto path = top.second;
    
                dfs_stack.pop();
    
                if(!root->left && !root->right)
                {
                    paths.push_back(path);
                }
    
                if(root->left)
                {
                    auto path = top.second;
    
                    if(root->left->val == targetSum) ++cnt;
    
                    for(auto &el : path)
                    {
                        el += root->left->val;
                        if(el == targetSum) ++cnt;
                    }
                    path.push_back(root->left->val);
    
                    dfs_stack.push(make_pair(root->left, path));
                }
    
                if(root->right)
                {
                    auto path = top.second;
                    if(root->right->val == targetSum) ++cnt;
    
                    for(auto &el : path)
                    {
                        el += root->right->val;
                        if(el == targetSum) ++cnt;
                    }
                    path.push_back(root->right->val);
    
                    dfs_stack.push(make_pair(root->right, path));
                }           
            }
    
            return cnt;
        }
    };