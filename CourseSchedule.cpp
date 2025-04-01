class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> classes(numCourses);
            vector<int> in_degree(numCourses);
            vector<bool> completed(numCourses);
    
            queue<int> class_order {};
    
            for (auto v : prerequisites){
                classes[v[1]].push_back(v[0]);
                ++in_degree[v[0]];
            }
    
            for (auto i{0}; i < in_degree.size(); ++i){
                if (in_degree[i] == 0) { class_order.push(i); }
            }
    
            if (class_order.empty()) return false;
    
            while(!class_order.empty()) {
                auto c = class_order.front();
                class_order.pop();
    
                completed[c] = true;
    
                for (auto& p : classes[c]) {
                    in_degree[p] -= 1;
    
                    if (in_degree[p] == 0) { class_order.push(p); }
                }
            }
    
            for (auto c : completed) { if (!c) return false; }
    
            return true;
        }
    };