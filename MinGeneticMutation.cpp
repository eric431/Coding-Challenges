#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    public:
        int minMutation(string startGene, string endGene, vector<string>& bank) {
            unordered_map<string, vector<string>> mutation_graph;
    
            for (auto i{0}; i < bank.size(); ++i){
                int num_diff {0};
                for (auto j{0}; j < startGene.size(); ++j){
                    if (startGene[j] != bank[i][j]){
                        if (num_diff == 1){
                            break;
                        }
                        ++num_diff;
                    }
                }
    
                if (num_diff == 1){
                    mutation_graph[startGene].push_back(bank[i]);
                    mutation_graph[bank[i]].push_back(startGene);
                }
            }
    
            for (auto i{0}; i < bank.size(); ++i){
                for(auto i2 {i + 1}; i < bank.size(); ++i){
                    int num_diff {0};
                    for (auto j{0}; j < bank[i].size(); ++j){
                        if (bank[i][j] != bank[i2][j]){
                            if (num_diff == 1){
                                break;
                            }
                            ++num_diff;
                        }
                    }
    
                    if (num_diff == 1){
                        mutation_graph[bank[i]].push_back(bank[i2]);
                        mutation_graph[bank[i2]].push_back(bank[i]);
                    }
                }
            } 
    
            // bfs
            queue<pair<string, int>> bfs_q;
            bfs_q.push({startGene, 0});
    
            unordered_map<string, bool> visited;
    
            while(!bfs_q.empty()){
                auto [m, c] = bfs_q.front();
                bfs_q.pop();
    
                if (m == endGene){
                    return c;
                }
    
                for(auto& valid_m : mutation_graph[m]){
                    if(!visited[valid_m]){
                        bfs_q.push({valid_m, c + 1});
                        visited[valid_m] = true;
                    }
                }
            }
    
            return -1;
        }
    };