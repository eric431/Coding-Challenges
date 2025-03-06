/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 

Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/

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
    bool isBST(TreeNode* root, pair<int, int>& min_max)
    {
        if(!root) return true;
        
        if(!root->left && !root->right)
        {
            min_max = make_pair(root->val, root->val);
        }
        else
        {
            auto left = root->left;
            auto right = root->right;
                        
            if((left && left->val > root->val) || (right && right->val < root->val))
                return false;
            
            pair<int, int> left_min_max {numeric_limits<int>::max(), numeric_limits<int>::min()};
            pair<int, int> right_min_max {numeric_limits<int>::max(), numeric_limits<int>::min()};
            
            bool valid {};
            valid = isBST(left, left_min_max) && isBST(right, right_min_max);
                        
            if(!valid) return false;

            if(left && left_min_max.first < root->val && left_min_max.second < root->val)
                min_max.first = min(min_max.first, left_min_max.first);
            else if(!left)
                min_max.first = min(min_max.first, root->val);
            else if(left)
                return false;
            
            if(right && right_min_max.first > root->val && right_min_max.second > root->val)
                min_max.second = max(min_max.second, right_min_max.second);
            else if(!right)
                min_max.second = max(min_max.first, root->val);
            else if(right)
                return false;
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        pair<int, int> min_max {numeric_limits<int>::max(), numeric_limits<int>::min()};
        return isBST(root, min_max);
    }
};

// Alternatively
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
        void traverse_tree(TreeNode* root, long& prev_val, bool& is_valid)
        {
            if(!root || !is_valid)
            {
                is_valid &= true;
                return;
            }
    
            traverse_tree(root->left, prev_val, is_valid);
    
            is_valid &= (root->val > prev_val);
    
            prev_val = root->val;
    
            traverse_tree(root->right, prev_val, is_valid);
        }
    
        bool isValidBST(TreeNode* root) {
            long prev_val = numeric_limits<long>::min();
            bool is_valid = true;
            
            traverse_tree(root, prev_val, is_valid);
    
            return is_valid;
        }
    };