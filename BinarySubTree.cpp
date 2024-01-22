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
    vector<TreeNode*> MakeSubTreeVector(TreeNode* root)
    {
        vector<TreeNode*> tmp;
                
        if(root!=nullptr)
        {
            tmp.push_back(root);
            
            auto left = MakeSubTreeVector(root->left);
            auto right = MakeSubTreeVector(root->right);
            tmp.insert(tmp.end(), left.begin(), left.end());
            tmp.insert(tmp.end(), right.begin(), right.end());
        }
        
        return tmp;
    }
    
    vector<int> VectoriseTreeNode(TreeNode* root)
    {
        vector<int> tmp;
                
        if(root!=nullptr)
        {
            tmp.push_back(root->val);
            
            auto left = VectoriseTreeNode(root->left);
            auto right = VectoriseTreeNode(root->right);
            tmp.insert(tmp.end(), left.begin(), left.end());
            tmp.insert(tmp.end(), right.begin(), right.end());
        }
        
        return tmp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<int, vector<TreeNode*>>  subtree_tracker;

        map<vector<int>, vector<TreeNode*>> SubTreeMap;

        vector<TreeNode*> DuplicateSubTree = MakeSubTreeVector(root);
        
        for(auto& el : DuplicateSubTree)
        {
            cout << "NEW NODE" << endl;
            auto vec_DST = VectoriseTreeNode(el);
            for (auto& el2 : vec_DST)
            {
                cout << el2 << endl;
            }
            SubTreeMap[vec_DST].push_back(el);
        }

        vector<TreeNode*> DST;        
        
        for(auto& [key, value] : SubTreeMap)
        {
            // cout << "KEY : ";
            cout << "{";
            for(auto& el : key)
            {
                cout << el << " ";
            }
            cout << "}:";
            // cout << endl;
            cout << value.size() << endl;
            
            if(value.size()>1)
            {
                DST.push_back(value[0]);
            }
            
        }
        
        
        
        return DST;
    }
};