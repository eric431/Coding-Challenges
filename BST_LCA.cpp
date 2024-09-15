// NOTE: THIS SOLUTION NEEDS OPTIMIZATION EVEN THOUGH SOLUTION PASSES //
// HACKERRANK //

// You are given pointer to the root of the binary search tree and two values  and . You need to return the lowest common ancestor (LCA) of  and  in the binary search tree.

// image
// In the diagram above, the lowest common ancestor of the nodes  and  is the node . Node  is the lowest node which has nodes  and  as descendants.

// Function Description

// Complete the function lca in the editor below. It should return a pointer to the lowest common ancestor node of the two values given.

// lca has the following parameters:
// - root: a pointer to the root node of a binary search tree
// - v1: a node.data value
// - v2: a node.data value

// Input Format

// The first line contains an integer, , the number of nodes in the tree.
// The second line contains  space-separated integers representing  values.
// The third line contains two space-separated integers,  and .

// To use the test data, you will have to create the binary search tree yourself. Here on the platform, the tree will be created for you.

// Constraints




// The tree will contain nodes with data equal to  and .

// Output Format

// Return the a pointer to the node that is the lowest common ancestor of  and .

// Sample Input

// 6
// 4 2 3 1 7 6
// 1 7
// image

//  and .

// Sample Output

// [reference to node 4]

// Explanation

// LCA of  and  is , the root in this case.
// Return a pointer to the node.


// SOLUTION
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void DFS_search(Node* node, int v1, int v2, set<Node*>& visited, stack<Node*>& ToVisit, map<int, Node*>& node_map)
    {
        if(visited.count(node) == 1) return;
        else visited.insert(node);
            
        if(node->data == v1 || node->data == v2)
        {
            node_map[node->data] = node;
        }
        if(node_map.size() == 2)
        {
            stack<Node*>().swap(ToVisit);
            return;
        }
            
        if(node->right != nullptr) 
        {
            ToVisit.push(node->right);
        }
        if(node->left != nullptr) 
        {
            ToVisit.push(node->left);
        }
            
        while(!ToVisit.empty())
        {
            auto nextNode = ToVisit.top();
            ToVisit.pop();
            DFS_search(nextNode, v1, v2, visited, ToVisit, node_map);
        }
    }

    map<int, Node*> DFS(Node *root, int v1, int v2)
    {
        map<int, Node*> node_map;
        map<Node*, vector<Node*>> child_nodes;
        set<Node*> visited;
        stack<Node*> ToVisit;

        DFS_search(root, v1, v2, visited, ToVisit, node_map);
        return node_map;
    }
    
    bool hasDescendants(Node* nodes, int v1, int v2)
    {
        auto node_map = DFS(nodes, v1, v2);
        if(node_map.size() == 2) return true;
        return false;
    }
  
    Node *lca(Node *root, int v1,int v2) {
		// Write your code here.
        stack<Node*> node_stack, lca_stack;
        node_stack.push(root);
        while(!node_stack.empty())
        {
            auto node = node_stack.top();
            node_stack.pop();
            if(hasDescendants(node, v1, v2))
            {
                lca_stack.push(node);
                if(node->right != nullptr)node_stack.push(node->right);
                if(node->left != nullptr)node_stack.push(node->left);
            }
        }
        
        auto lca = lca_stack.top();
        return lca;
    }