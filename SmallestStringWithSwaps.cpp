/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

class Solution {
public:
    int find(vector<int>& root, int x)
    {
        if(x == root[x])
            return x;
        return root[x] = find(root, root[x]);
    }
    
    void union_set(vector<int>& root, vector<int>& rank, int x, int y)
    {
        int rootX = find(root, x);
        int rootY = find(root, y);
        if(rootX != rootY)
        {
            if(rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if(rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            } 
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> root(s.size());
        vector<int> rank(s.size());
        for(auto i{0}; i < s.size(); ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
        
        for(auto p : pairs)
            union_set(root, rank, p[0], p[1]);
        
        map<int, vector<int>> root_map{};
        for(auto i{0}; i < root.size(); ++i)
        {
            root[i] = find(root, root[i]);
            root_map[root[i]].push_back(i);
        }
        
        for(auto& [k, v] : root_map)
        {
            vector<char> tmp{};
            for(auto& i : v) tmp.push_back(s[i]);
            
            sort(tmp.begin(), tmp.end());
            sort(v.begin(), v.end());
            
            for(auto i{0}; i < tmp.size(); ++i)
            {
                s[v[i]] = tmp[i];
            }
        }
                
        return s;
    }
};