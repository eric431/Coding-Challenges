class Solution {
public:
    int m;
    int n;

    void dfs_traversal(int r, int c, int id, int& size, vector<vector<int>>& grid, vector<vector<int>>& islands){
        if(r < 0 || c < 0 || r >= m || c >= n) return;

        if(!grid[r][c]) return;

        islands[r][c] = id;
        grid[r][c] = 0;

        ++size;
        dfs_traversal(r - 1, c, id, size, grid, islands);
        dfs_traversal(r + 1, c, id, size, grid, islands);
        dfs_traversal(r, c - 1, id, size, grid, islands);
        dfs_traversal(r, c + 1, id, size, grid, islands);
    }

    int largestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<int>> tmp_grid = grid;
        vector<vector<int>> islands(m, vector<int>(n));
        unordered_map<int, int> island_sizes;

        int id {1};
        for(auto r{0}; r < m; ++r){
            for(auto c{0}; c < n; ++c){
                if(grid[r][c]){
                    int size {0};
                    dfs_traversal(r, c, id, size, tmp_grid, islands);
                    island_sizes[id] = size;
                    ++id;
                }
            }
        }

        if(island_sizes.empty()) return 1;

        int largest_island = 0;
        for(auto r{0}; r < m; ++r){
            for(auto c{0}; c < n; ++c){
                if(grid[r][c]) continue;

                int tmp {1};
                unordered_set<int> visited_islands;
                if(r - 1 > -1 && grid[r - 1][c]){
                    int id = islands[r - 1][c];
                    if(!visited_islands.contains(id)) {
                        tmp += island_sizes[id];
                        visited_islands.insert(id);
                    }
                }
                if(r + 1 < m && grid[r + 1][c]){
                    int id = islands[r + 1][c];
                    if(!visited_islands.contains(id)) {
                        tmp += island_sizes[id];
                        visited_islands.insert(id);
                    }
                }
                if(c - 1 > -1 && grid[r][c - 1]){
                    int id = islands[r][c - 1];
                    if(!visited_islands.contains(id)) {
                        tmp += island_sizes[id];
                        visited_islands.insert(id);
                    }
                }
                if(c + 1 < n && grid[r][c + 1]){
                    int id = islands[r][c + 1];
                    if(!visited_islands.contains(id)) {
                        tmp += island_sizes[id];
                        visited_islands.insert(id);
                    }
                }
                largest_island = max(tmp, largest_island);
            }
        }

        if(largest_island == 0){
            for(auto &[k, v] : island_sizes){
                largest_island = max(largest_island, v);
            }
        }
        return largest_island;
    }
};