/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public:
        vector<vector<int>> level_order_traversal(Node* root){
            queue<pair<Node*, int>> bfs_q;
            bfs_q.push({root, 0});
            
            vector<vector<int>> ans;
            vector<int> tmp;
            int prev_l = -1;
            while(!bfs_q.empty()){
                auto [node, l] = bfs_q.front();
                bfs_q.pop();
                
                if(l == prev_l){
                    tmp.push_back(node->val);
                } else {
                    if(tmp.size()) {
                        ans.push_back(tmp);
                        tmp.clear();
                    }
                    tmp.push_back(node->val);
                    prev_l = l;
                }
                
                for(auto &child : node->children){ bfs_q.push( {child, l + 1}); }
            }
            ans.push_back(tmp);
            
            return ans;
        }
        
        vector<vector<int>> levelOrder(Node* root) {
            if(!root) return {};
            return level_order_traversal(root);
        }
    };