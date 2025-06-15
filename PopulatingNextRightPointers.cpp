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
        void bfs_connect(Node* root){
            queue<pair<Node*, int>> bfs_q;
            bfs_q.push({root, 0});
            
            pair<Node*, int> prev_l = make_pair(nullptr, -1);
            while(!bfs_q.empty()){
                auto [node, l] = bfs_q.front();
                bfs_q.pop();
                
                if(l == prev_l.second){
                    prev_l.first->next = node;
                    prev_l.first = node;
                } else {
                    prev_l.first = node;
                    prev_l.second = l;
                }
                
                if(node->left && node->right){
                    bfs_q.push({node->left, l + 1});
                    bfs_q.push({node->right, l + 1});
                }
            }
        }
        
        Node* connect(Node* root) {
            if(!root) return root;
    
            bfs_connect(root);
            
            return root;
        }
    };