class Solution {
    public:
        using node = pair<int, string>;
    
        struct cmp{
            bool operator()(const node &n1, const node &n2) const {
                if (n1.first != n2.first){ return (n1.first > n2.first); }
                return n1.second < n2.second;
            }
        };
    
        using graph_node = set<node, cmp>;
    
        
        unordered_map<string, graph_node> graph;
        unordered_map<string, int> out;
    
        map<vector<string>, int> flights;
        
        vector<string> dfs(const string &start) {
            stack<string> dfs_stk;
            dfs_stk.push(start);
    
            vector<string> ans;
            while(!dfs_stk.empty()){
                auto from = dfs_stk.top();
                dfs_stk.pop();
                
                ans.push_back(from);
                
                for(auto &nde : graph[from]){
                    auto to = nde.second;
                    if(flights[{from, to}]){
                        --flights[{from, to}];
    
                        dfs_stk.push(to);
                        
                        break;
                    }
                }
            }
            
            return ans;
        }
        
        vector<string> findItinerary(vector<vector<string>>& tickets) {
            for (auto &ticket : tickets){
                ++flights[ticket];
                ++out[ticket[0]];
            }
            
            for (auto &ticket : tickets) {            
                graph[ticket[0]].insert({out[ticket[1]], ticket[1]});
            }
            
            return dfs("JFK");
        }
    };