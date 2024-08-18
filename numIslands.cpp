// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

class Solution {
public:
    
    struct Tree {
        int value;
        pair<int, int> pos;
        Tree* moveNorth;
        Tree* moveSouth;
        Tree* moveEast;
        Tree* moveWest;
        Tree() : value(-1), moveNorth(nullptr), moveSouth(nullptr), moveEast(nullptr), moveWest(nullptr) {}
        Tree(int v) : value(v), moveNorth(nullptr), moveSouth(nullptr), moveEast(nullptr), moveWest(nullptr) {}
    };
    
    Tree* island = new Tree();
    Tree* land  = new Tree();
    vector<Tree*> islands;
    vector<Tree*> Iland;
    set<pair<int, int>> visited_land;    
    
    void create_map(vector<vector<char>>& grid, Tree* itrHead)
    {
        queue<Tree*> q;
        for(auto i = 0; i < grid.size(); i++)
        {
            for(auto j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    itrHead->value = 1;
                    itrHead->pos = make_pair(i, j);
                    Iland.push_back(itrHead);
                }
                else if(grid[i][j] == '0')
                {
                    itrHead->value = 0;
                    itrHead->pos = make_pair(i, j);
                }
                
                if(i > 0)
                {
                    q.front()->moveSouth = itrHead;
                    itrHead->moveNorth = q.front();
                    q.pop();
                }
                if(j > 0)
                {
                    itrHead->moveWest = new Tree();
                    itrHead->moveWest = q.back();
                }
                q.push(itrHead);
                
                if(j < grid[i].size()-1)
                {
                    itrHead->moveEast = new Tree();
                    itrHead = itrHead->moveEast;
                }
                else
                {
                    if(i != grid.size()-1)
                        q.front()->moveSouth = new Tree();
                        itrHead = q.front()->moveSouth;
                }
            }
        }
    }
    
    void create_island(Tree* land, Tree* itrHead)
    {
        if(itrHead->value == 1)
        {
            land->value = itrHead->value;
            land->pos = itrHead->pos;
                        
            if (visited_land.contains(land->pos)) {return;}
            visited_land.insert(land->pos);
        }
        else if(itrHead->value == 0)
        {
            land = nullptr;
            return;
        }

        if(itrHead->moveEast != nullptr)
        {
            if(itrHead->moveEast->value == 1)
            {
                land->moveEast = new Tree();
                create_island(land->moveEast, itrHead->moveEast);
            }   
        }
        
        if(itrHead->moveSouth != nullptr)
        {
            if(itrHead->moveSouth->value == 1)
            {
                land->moveSouth = new Tree();
                create_island(land->moveSouth, itrHead->moveSouth);
            }            
        }
        
        if(itrHead->moveWest != nullptr)
        {
            if(itrHead->moveWest->value == 1)
            {
                land->moveWest = new Tree();
                create_island(land->moveWest, itrHead->moveWest);
            }            
        }
        
        if(itrHead->moveNorth != nullptr)
        {
            if(itrHead->moveNorth->value == 1)
            {
                land->moveNorth = new Tree();
                create_island(land->moveNorth, itrHead->moveNorth);
            }            
        }
        
        return;
    }
    
    void explore(Tree* root)
    {
        for(auto& el : Iland)
        {
            Tree* island = new Tree();
            if(visited_land.contains(el->pos))
            {
                continue;
            }
            create_island(island, el);

            islands.push_back(island);                
        }
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        Tree* head = new Tree();
        auto itr_head = head;
 
        create_map(grid, head);
        explore(itr_head);
                
        return islands.size();
    }
};