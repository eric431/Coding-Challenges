/*
Consider an undirected graph consisting of  nodes where each node is labeled from  to  and the edge between any two nodes is always of length . We define node  to be the starting position for a BFS. Given a graph, determine the distances from the start node to each of its descendants and return the list in node number order, ascending. If a node is disconnected, it's distance should be .

For example, there are  nodes in the graph with a starting node . The list of , and each has a weight of .

image

Starting from node  and creating a list of distances, for nodes  through  we have .

Function Description

Define a Graph class with the required methods to return a list of distances.

Input Format

The first line contains an integer, , the number of queries.

Each of the following  sets of lines is as follows:

The first line contains two space-separated integers,  and , the number of nodes and the number of edges.
Each of the next  lines contains two space-separated integers,  and , describing an edge connecting node  to node .
The last line contains a single integer, , the index of the starting node.
Constraints

Output Format

For each of the  queries, print a single line of  space-separated integers denoting the shortest distances to each of the  other nodes from starting position . These distances should be listed sequentially by node number (i.e., ), but should not include node . If some node is unreachable from , print  as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output

6 6 -1
-1 6
Explanation

We perform the following two queries:

The given graph can be represented as:
image
where our start node, , is node . The shortest distances from  to the other nodes are one edge to node , one edge to node , and there is no connection to node .
The given graph can be represented as:
image
where our start node, , is node . There is only one edge here, so node  is unreachable from node  and node  has one edge connecting it to node . We then print node 's distance to nodes  and  (respectively) as a single line of space-separated integers: -1 6.

Note: Recall that the actual length of each edge is , and we print  as the distance to any node that's unreachable from .

Language
C++14
More
1213141516171819204748495051525354555657581191078563421
            };
        
            auto dcs = bfs(start, graph);
            
            return dcs;
        }
    
};

int main() {

Line: 52 Col: 10

Test against custom input
Congratulations
You solved this challenge. Would you like to challenge your friends?Share on FacebookShare on TwitterShare on LinkedIn

Test case 0

Test case 1

Test case 2

Test case 3

Test case 4

Test case 5

Test case 6

Test case 7

Test case 8
Compiler Message
Success
Input (stdin)
2
4 2
1 2
1 3
1
3 1
2 3
2
Expected Output
6 6 -1
-1 6

*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    vector<vector<int>> graph;
    public:
        Graph(int n) { graph.resize(n); }
    
        void add_edge(int u, int v) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            auto bfs = [&](int s, vector<vector<int>>& graph) {
                queue<pair<int, int>> bfs_q;
                bfs_q.push({s, 0});
                
                vector<int> distances(graph.size(), - 1);
                distances[s] = 0;
                
                vector<bool> visited(graph.size(), false);
                visited[s] = true;
                
                while(!bfs_q.empty()) {
                    auto f = bfs_q.front();
                    bfs_q.pop();
                    
                    int curr_n = f.first;
                    int d = f.second;
                    for (auto &n : graph[curr_n]) {
                        if (!visited[n]) {
                            bfs_q.push({n, d + 1});
                            distances[n] = 6 * (d + 1);
       
                            visited[n] = true;
                        }
                    }
                }
                
                return distances;
            };
        
            auto dcs = bfs(start, graph);
            
            return dcs;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}