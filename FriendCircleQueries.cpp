/*
The population of HackerWorld is . Initially, none of the people are friends with each other. In order to start a friendship, two persons  and  have to shake hands, where . The friendship relation is transitive, that is if  and  shake hands with each other,  and friends of  become friends with  and friends of .

You will be given  queries. After each query, you need to report the size of the largest friend circle (the largest group of friends) formed after considering that query.

For example, your list of queries is:

1 2
3 4
2 3
First,  and  shake hands, forming a circle of . Next,  and  do the same. Now there are two groups of  friends. When  and  become friends in the next query, both groups of friends are added together to make a circle of  friends. We would print

2
2
4
Function Description

Complete the function maxCircle in the editor below. It must return an array of integers representing the size of the maximum circle of friends after each query.

maxCircle has the following parameter(s):

queries: an array of integer arrays, each with two elements indicating a new friendship
Input Format

The first line contains an integer, , the number of queries to process.
Each of the next  lines consists of two space-separated integers denoting the 2-D array .

Constraints

 for 
Output Format

Return an integer array of size , whose value at index  is the size of largest group present after processing the  query.

Sample Input 0

2
1 2
1 3
Sample Output 0

2
3
Explanation 0

In the first query,  and  shake hands. So, the size of largest group of friends is  (as no other friendships exist).
After the second query, ,  and  all become friends, as  shakes hand with ,  also become friends with  as he was already a friend of .

Sample Input 1

4
1000000000 23
11 3778
7 47
11 1000000000
Sample Output 1

2
2
2
4
Explanation 1

After first query, person  and person  become friends. So, the largest group size is .
After the second query, person  and person  become friends. So, the largest group size is still .
After the third query, person  and person  become friends. Answer is still .
After the last query, person  and person  become friends, which means , ,  and  all become friends. Hence, the answer now increased to .

Sample Input 2

6
1 2
3 4
1 3
5 7
5 6
7 4
Sample Output 2

2
2
4
4
4
7
Explanation 2

Friend circles after each iteration:

1   [1,2]
2   [1,2],[3,4]
3   [1,2,3,4]
4   [1,2,3,4],[5,7]
5   [1,2,3,4],[5,7,6]
6   [1,2,3,4,5,6,7]
*/

#include <bits/stdc++.h>

using namespace std;

// Complete the maxCircle function below.
int find(unordered_map<int, int>& root, int x)
{
    if(x == root[x])
        return x;
    return root[x] = find(root, root[x]);
}

void union_set(unordered_map<int, int>&root, unordered_map<int, int>& rank, int x, int y)
{
    int rootX = find(root, x);
    int rootY = find(root, y);
    if(rootX != rootY)
    {
        int curr_rank = rank[rootX] + rank[rootY]; 
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
        }
        rank[rootX] = rank[rootY] = curr_rank;
    }
}

vector<int> maxCircle(vector<vector<int>> queries) {   
    unordered_map<int, int> friends{};
    unordered_map<int, int> ranks{};
    for(auto q : queries)
    {
        friends[q[0]] = q[0];
        friends[q[1]] = q[1];
        ranks[q[0]] = 1;
        ranks[q[1]] = 1;
    }
    
    int max_rank{0};
    vector<int> groups{};
    for(auto q : queries)
    {
        union_set(friends, ranks, q[0], q[1]);
        int root1_ = find(friends, q[0]);
        int root2_ = find(friends, q[1]);
        max_rank = max({max_rank, ranks[root1_], ranks[root2_]});
        
        groups.push_back(max_rank);
    }
    
    return groups;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
