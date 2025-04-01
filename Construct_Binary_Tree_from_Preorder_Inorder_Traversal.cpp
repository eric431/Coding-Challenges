// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

// Example 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// Example 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 

// Constraints:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.


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
        vector<int> p {};
        vector<int> i_ {};
        unordered_map<int, int> map{};
        int n{};
    
        void build_tree_rcs(int& i, int l, int r, TreeNode* root)
        {
            if (!root || i >= n || (i < n && map[p[i]] > r)) return;
    
            root->val = p[i];
    
            int pivot = map[p[i]];
    
            ++i;
    
            if ( (l == r) || i >= n || (i < n && map[p[i]] > r) ) return;
    
            int sub_root = map[p[i]];
    
            if (sub_root < pivot){
                root->left = new TreeNode();
                build_tree_rcs(i, l, pivot - 1, root->left);
            }
            
            if ( (l == r) || i >= n || (i < n && map[p[i]] > r) ) return;
    
            sub_root = map[p[i]];
    
            if (sub_root > pivot) {
                root->right = new TreeNode();
                build_tree_rcs(i, pivot + 1, r, root->right);
            }
        }
    
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            p = preorder;
            i_ = inorder;
            n = preorder.size();
    
            for (auto i{0}; i < n; ++i){ map[inorder[i]] = i; }
    
            TreeNode* root = new TreeNode();
    
            int i {0};
            build_tree_rcs(i, 0, n - 1, root);
    
            return root;
        }
    };