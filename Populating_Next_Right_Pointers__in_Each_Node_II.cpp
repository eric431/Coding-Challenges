// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

 

// Example 1:


// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100
 

// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    public:
        void connect_rcs(Node* root) {
            queue<pair<Node*, int>> node_queue {};
            node_queue.push({root, 1});
    
            pair<Node*, int> prev = {nullptr, 0};
            while(!node_queue.empty()) {
                auto [curr_root, l] = node_queue.front();
                node_queue.pop();
    
                if (prev.second == l) { 
                    prev.first->next = curr_root; 
                    prev.first = curr_root; 
                }
                else { prev = {curr_root, l}; }
    
                if (curr_root->left) { node_queue.push( {curr_root->left, l + 1} ); }
    
                if (curr_root->right) { node_queue.push( {curr_root->right, l + 1} ); }
            }
    
        }
    
        Node* connect(Node* root) {
            if (root == nullptr) return nullptr;
    
            connect_rcs(root);
    
            return root;
        }
    };