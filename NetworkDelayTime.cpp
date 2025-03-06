// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

// Example 1:


// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Example 2:

// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1
// Example 3:

// Input: times = [[1,2,1]], n = 2, k = 2
// Output: -1
 

// Constraints:

// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)


class Solution {
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            using pr = pair<int, int>;
            
            vector<vector<pr>> edges(n);
            vector<bool> visited(n);
            vector<int> time(n, numeric_limits<int>::max());
            time[k - 1] = 0;
            
            priority_queue<pr, vector<pr>, greater<pr>> bfs_q {};
              
            // add edges
            for(auto &v : times)
            {
                edges[v[0] - 1].push_back(make_pair(v[1] - 1, v[2]));
            }
            
            bfs_q.push(make_pair(time[k - 1], k - 1));
            while(!bfs_q.empty())
            {
                auto f = bfs_q.top();
                bfs_q.pop();
    
                visited[f.second] = true;
                
                for(auto &el : edges[f.second])
                {
                    if(!visited[el.first])
                    {
                        bfs_q.push(make_pair(f.first + el.second, el.first));
                        time[el.first] = min(time[el.first], f.first + el.second);
                    }
                }
            }
            
            int delay_time{0};
            for(auto &el : time)
            {
                delay_time = max(el, delay_time);
            }
            
            if(delay_time == numeric_limits<int>::max()) return -1;
            
            return delay_time;
        }
    };