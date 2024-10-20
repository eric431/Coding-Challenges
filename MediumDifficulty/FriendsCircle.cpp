#include <bits/stdc++.h>

using namespace std;

// Complete the maxCircle function below.

struct set_wrapper
{
    set<int> group;
};

vector<int> maxCircle(vector<vector<int>> queries) { 
    map<int, int> friend_to_pos_map;
    vector<set_wrapper*> store;
    vector<int> solution(queries.size());
    
    set_wrapper* new_wrapper = nullptr;
    
    int idx = 0, max_size = 0, size, idc0, idc1;
    
    for(auto q : queries)
    {
        if(friend_to_pos_map.count(q[0]) == 0 && friend_to_pos_map.count(q[1]) == 0)
        {
            new_wrapper = new set_wrapper;
            set<int> new_circle{q[0], q[1]};
            new_wrapper->group.insert(new_circle.begin(), new_circle.end());
                        
            store.push_back(new_wrapper);            
            
            idc0 = int(store.size()) - 1;
            friend_to_pos_map[q[0]] = idc0;
            friend_to_pos_map[q[1]] = idc0;
        }
        else if(friend_to_pos_map.count(q[0]) == 0)
        {
            idc0 = friend_to_pos_map[q[1]];
            store[idc0]->group.insert(q[0]);
            friend_to_pos_map[q[0]] = idc0;
        }
        else if(friend_to_pos_map.count(q[1]) == 0)
        {
            idc1 = friend_to_pos_map[q[0]];
            store[idc1]->group.insert(q[1]);
            friend_to_pos_map[q[1]] = idc1;              
        }
 
        idc0 = friend_to_pos_map[q[0]];
        idc1 = friend_to_pos_map[q[1]];
        
        store[idc0]->group.insert(store[idc1]->group.begin(), store[idc1]->group.end());
        store[idc1] = store[idc0];        
    
        size = store[idc0]->group.size();
        max_size = max(max_size, size);
        
        solution[idx] = max_size;
        ++idx;
    }
    return solution;
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
