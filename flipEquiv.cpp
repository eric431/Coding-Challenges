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
        bool flipEquiv(TreeNode* root1, TreeNode* root2) {
            if (!root1 && !root2){
                return true;
            } else if (!root1 || !root2){
                return false;
            } else if (root1->val != root2->val){
                return false;
            }
    
            bool flip_1 = flipEquiv(root1->left, root2->left);
            bool flip_2 = flipEquiv(root1->right, root2->right);
            bool flip_3 = flipEquiv(root1->left, root2->right);
            bool flip_4 = flipEquiv(root1->right, root2->left);
    
            return (flip_1 && flip_2) || (flip_3 && flip_4);
        }
    };