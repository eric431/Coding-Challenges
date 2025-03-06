// You are given the root of a binary tree.

// A ZigZag path for a binary tree is defined as follow:

// Choose any node in the binary tree and a direction (right or left).
// If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
// Change the direction from right to left or from left to right.
// Repeat the second and third steps until you can't move in the tree.
// Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

// Return the longest ZigZag path contained in that tree.

 

// Example 1:


// Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
// Output: 3
// Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
// Example 2:


// Input: root = [1,1,1,null,1,null,null,1,1,null,1]
// Output: 4
// Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).
// Example 3:

// Input: root = [1]
// Output: 0


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
        int longestZigZag(TreeNode* root) {
            stack<pair<TreeNode*, vector<int>>> s;
    
            int longest_zig_zag {0};
    
            pair<TreeNode*, vector<int>> pr = {root, {-1, 0}};
            s.push(pr);
            while(!s.empty())
            {
                auto top = s.top();
                s.pop();
    
                if(top.first == nullptr) continue;
    
                int cnt = top.second[1];
    
                longest_zig_zag = max(cnt, longest_zig_zag);
    
                if((!top.first->left && !top.first->right)) continue;
    
                if(top.second[0] == -1)
                {
                    pr = {top.first->left, {0, cnt + 1}};
                    s.push(pr);
    
                    pr = {top.first->right, {1, cnt + 1}};
                    s.push(pr);
                    continue;
                }
    
                if(top.second[0] == 0 && top.first->right)
                {
                    pr = {top.first->right, {1, cnt + 1}};
                    s.push(pr);
                }
                if(top.second[0] == 0 && top.first->left)
                {
                    pr = {top.first->left, {0, 1}};
                    s.push(pr);
                }
    
                if(top.second[0] == 1 && top.first->left)
                {
                    pr = {top.first->left, {0, cnt + 1}};
                    s.push(pr);
                }
                if(top.second[0] == 1 && top.first->right)
                {
                    pr = {top.first->right, {1, 1}};
                    s.push(pr);
                }            
            }
    
            return longest_zig_zag;
        }
    };