class Solution {
    public:
        vector<vector<int>> graph;
        vector<vector<int>> prices;
        int k;
        
        using v = vector<int>;
        
        int find_flight(int src, int dst){
            priority_queue<v, vector<v>, greater<v>> bfs_q;
            vector<int> start = {0, 0, src};
            bfs_q.push(start);
            
            map<pair<int, int>, int> visited{};
            while(!bfs_q.empty()){
                auto tmp = bfs_q.top();
                bfs_q.pop();
                
                auto spent = tmp[0];
                auto p = tmp[1];
                auto loc = tmp[2];
                                        
                if (p > (k + 1)){
                    continue;
                } else if(loc == dst && p <= (k + 1)){
                    return spent;
                }
                
                for(auto &el : graph[loc]){
                    pair<int, int> flight = {loc, el};
                    if(!visited.contains(flight) || (visited.contains(flight) && p < visited[flight])){
                        vector<int> curr = {spent + prices[loc][el], p + 1, el};
                        bfs_q.push(curr);
                        visited[flight] = p;
                    }
                }
            }
            
            return -1;
        }
        
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            this->graph.resize(n + 1);
            this->prices.resize(n + 1, vector<int>(n + 1, -1));
            this->k = k;
            
            for (auto &flight : flights){
                graph[flight[0]].push_back(flight[1]);
                prices[flight[0]][flight[1]] = flight[2];
            }
            
            return find_flight(src, dst);
            
        }
    };