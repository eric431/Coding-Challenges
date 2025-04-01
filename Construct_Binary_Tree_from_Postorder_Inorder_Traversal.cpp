// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.


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
        vector<int> m_postorder;
        vector<int> m_inorder;
    
        int n;
        unordered_map<int, int> map;
    
        void build_tree_rcs(int& i, int l, int r, TreeNode* root) {
            if (i < 0 || (i > -1 && map[m_postorder[i]] > r)) return;
    
            root->val = m_postorder[i];
    
            int pivot = map[m_postorder[i]];
            --i;
    
            if ((l == r) || i < 0 || (i > -1 && map[m_postorder[i]] < l)) return;
    
            int sub_root = map[m_postorder[i]];
    
            if (sub_root > pivot) {
                root->right = new TreeNode();
                build_tree_rcs(i, pivot + 1, r, root->right);
            }
    
            if ((l == r) || i < 0 || (i > -1 && map[m_postorder[i]] < l)) return;
    
            sub_root = map[m_postorder[i]];
    
            if (sub_root < pivot) {
                root->left = new TreeNode();
                build_tree_rcs(i, l, pivot - 1, root->left);
            }
        }
    
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            m_postorder = postorder;
            m_inorder = inorder;
    
            n = inorder.size();
    
            for (auto i{0}; i < inorder.size(); ++i) { map[inorder[i]] = i; }
    
            TreeNode* root = new TreeNode();
    
            int i {n - 1};
            build_tree_rcs(i, 0, n - 1, root);
    
            return root;
        }
    };