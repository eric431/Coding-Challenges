// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

// Example 1:

// Input: root = [1,2,3,null,5,null,4]

// Output: [1,3,4]

// Explanation:



// Example 2:

// Input: root = [1,2,3,4,null,null,null,5]

// Output: [1,3,4,5]

// Explanation:



// Example 3:

// Input: root = [1,null,3]

// Output: [1,3]

// Example 4:

// Input: root = []

// Output: []

 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100

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
        vector<int> rightSideView(TreeNode* root) {
            if(!root) return {};
    
            stack<pair<TreeNode*, int>> dfs_stack {};
    
            vector<int> observed_nodes {};
            // observed_nodes.push_back(root->val);
            // observed_nodes[0] = root->val;
    
            vector<int> level_stack(100, -101);
            level_stack[0] = root->val;
    
            dfs_stack.push(make_pair(root, 0));
            while(!dfs_stack.empty())
            {
                auto top = dfs_stack.top();
                dfs_stack.pop();
    
                if(top.first) level_stack[top.second] = top.first->val;
    
                if(top.first->right)
                {
                    dfs_stack.push(make_pair(top.first->right, top.second + 1));
                }
    
                if(top.first->left)
                {
                    dfs_stack.push(make_pair(top.first->left, top.second + 1));
                }
            }
    
            for(auto i{0}; i < level_stack.size(); ++i)
            {
                if(level_stack[i] == -101) break;
    
                observed_nodes.push_back(level_stack[i]);
            }
    
            return observed_nodes;
        }
    };