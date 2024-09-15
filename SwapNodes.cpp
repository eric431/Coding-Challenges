// HACKER RANK

// A binary tree is a tree which is characterized by one of the following properties:

// It can be empty (null).
// It contains a root node only.
// It contains a root node with a left subtree, a right subtree, or both. These subtrees are also binary trees.
// In-order traversal is performed as

// Traverse the left subtree.
// Visit root.
// Traverse the right subtree.
// For this in-order traversal, start from the left child of the root node and keep exploring the left subtree until you reach a leaf. When you reach a leaf, back up to its parent, check for a right child and visit it if there is one. If there is not a child, you've explored its left and right subtrees fully. If there is a right child, traverse its left subtree then its right in the same manner. Keep doing this until you have traversed the entire tree. You will only store the values of a node as you visit when one of the following is true:

// it is the first node visited, the first time visited
// it is a leaf, should only be visited once
// all of its subtrees have been explored, should only be visited once while this is true
// it is the root of the tree, the first time visited
// Swapping: Swapping subtrees of a node means that if initially node has left subtree L and right subtree R, then after swapping, the left subtree will be R and the right subtree, L.

// For example, in the following tree, we swap children of node 1.

//                                 Depth
//     1               1            [1]
//    / \             / \
//   2   3     ->    3   2          [2]
//    \   \           \   \
//     4   5           5   4        [3]
// In-order traversal of left tree is 2 4 1 3 5 and of right tree is 3 5 1 2 4.

// Swap operation:

// We define depth of a node as follows:

// The root node is at depth 1.
// If the depth of the parent node is d, then the depth of current node will be d+1.
// Given a tree and an integer, k, in one operation, we need to swap the subtrees of all the nodes at each depth h, where h ∈ [k, 2k, 3k,...]. In other words, if h is a multiple of k, swap the left and right subtrees of that level.

// You are given a tree of n nodes where nodes are indexed from [1..n] and it is rooted at 1. You have to perform t swap operations on it, and after each swap operation print the in-order traversal of the current state of the tree.

// Function Description

// Complete the swapNodes function in the editor below. It should return a two-dimensional array where each element is an array of integers representing the node indices of an in-order traversal after a swap operation.

// swapNodes has the following parameter(s):
// - indexes: an array of integers representing index values of each , beginning with , the first element, as the root.
// - queries: an array of integers, each representing a  value.

// Input Format
// The first line contains n, number of nodes in the tree.

// Each of the next n lines contains two integers, a b, where a is the index of left child, and b is the index of right child of ith node.

// Note: -1 is used to represent a null node.

// The next line contains an integer, t, the size of .
// Each of the next t lines contains an integer , each being a value .

// Output Format
// For each k, perform the swap operation and store the indices of your in-order traversal to your result array. After all swap operations have been performed, return your result array for printing.

// Constraints

// Either  or 
// Either  or 
// The index of a non-null child will always be greater than that of its parent.
// Sample Input 0

// 3
// 2 3
// -1 -1
// -1 -1
// 2
// 1
// 1
// Sample Output 0

// 3 1 2
// 2 1 3
// Explanation 0

// As nodes 2 and 3 have no children, swapping will not have any effect on them. We only have to swap the child nodes of the root node.

//     1   [s]       1    [s]       1   
//    / \      ->   / \        ->  / \  
//   2   3 [s]     3   2  [s]     2   3
// Note: [s] indicates that a swap operation is done at this depth.

// Sample Input 1

// 5
// 2 3
// -1 4
// -1 5
// -1 -1
// -1 -1
// 1
// 2
// Sample Output 1

// 4 2 1 5 3
// Explanation 1

// Swapping child nodes of node 2 and 3 we get

//     1                  1  
//    / \                / \ 
//   2   3   [s]  ->    2   3
//    \   \            /   / 
//     4   5          4   5  
// Sample Input 2

// 11
// 2 3
// 4 -1
// 5 -1
// 6 -1
// 7 8
// -1 9
// -1 -1
// 10 11
// -1 -1
// -1 -1
// -1 -1
// 2
// 2
// 4
// Sample Output 2

// 2 9 6 4 1 3 7 5 11 8 10
// 2 6 9 4 1 3 7 5 10 8 11
// Explanation 2

// Here we perform swap operations at the nodes whose depth is either 2 or 4 for  and then at nodes whose depth

// SOLUTION
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
 
struct BinaryTree
{
    int nodeVal, depth;
    BinaryTree* left=nullptr;
    BinaryTree* right=nullptr;
            
    BinaryTree(int a) : nodeVal(a) {}
};

void create_binaryTree(vector<vector<int>>& indexes, BinaryTree* root, map<int, vector<BinaryTree*>>& TreeMap)
{
    queue<BinaryTree*> TreeQueue;
    TreeQueue.push(root);
    for(int i = 0; i < indexes.size(); ++i)
    {
        if(!TreeQueue.empty()) 
        {
            auto node = TreeQueue.front();
            
            TreeMap[node->depth].push_back(node);
            TreeQueue.pop();
            
            int val_l = indexes[i][0];
            if(val_l != -1)
            {
                BinaryTree* left = new BinaryTree(val_l);   
                left->depth = node->depth + 1; 
                node->left = left;
                TreeQueue.push(left);
            } 
            
            int val_r = indexes[i][1];
            if(val_r != -1)
            {
                BinaryTree* right = new BinaryTree(val_r);
                right->depth = node->depth + 1;
                node->right = right;
                TreeQueue.push(right);         
            }            
        }         
    }
}

void swapSubTree(int k, BinaryTree* Node, map<int, vector<BinaryTree*>>& TreeMap)
{
    int factor = TreeMap.size() / k;
    for(int i = 1; i <= factor; ++i)
    {
        for(auto& el : TreeMap[k * i])
        {
            auto tmp = el->left;
            el->left = el->right;
            
            el->right = tmp;
        }        
    }
}

void recursive_tree_traversal(BinaryTree* Node, stack<BinaryTree*>& tree_stack, set<BinaryTree*>& visited)
{    
    if(visited.count(Node->right) == 0 && Node->right != nullptr)
    {
        recursive_tree_traversal(Node->right, tree_stack, visited);
    }
    if(visited.count(Node) == 0 && Node != nullptr) 
    {
        visited.insert(Node);
        tree_stack.push(Node);
    }
    if(visited.count(Node->left) == 0 && Node->left != nullptr)
    {
        recursive_tree_traversal(Node->left, tree_stack, visited);
    }
    return;
}

vector<int> flatten_tree(BinaryTree* Node)
{
    stack<BinaryTree*> tree_s;
    set<BinaryTree*> visited;
    
    recursive_tree_traversal(Node, tree_s, visited);
    
    vector<int> flattened_tree;
    while(!tree_s.empty())
    {
        auto top = tree_s.top();
        flattened_tree.push_back(top->nodeVal);
        tree_s.pop();
    }
    
    return flattened_tree;
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    BinaryTree* root = new BinaryTree(1);
    root->depth = 1; 
    
    map<int, vector<BinaryTree*>> TreeMap;
    create_binaryTree(indexes, root, TreeMap);

    vector<vector<int>> solution;
    for(auto el : queries)
    {
        swapSubTree(el, root, TreeMap);
        solution.push_back(flatten_tree(root));
    }
    return solution;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
