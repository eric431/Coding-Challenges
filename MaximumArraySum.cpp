#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// int subsetSumRecursive(const vector<pair<int, int>>& arr, int ptr, set<int> visited_idcs, stack<int>& recursive_stack)
// {
//     visited_idcs.insert(arr[ptr].second);
//     set<int> reset_cache = visited_idcs;    
    
//     int maxSum{arr[ptr].first}, resetMaxSum{maxSum};
//     int maxSumRcs{}, maxSumItr{maxSum};

//     for(int i = ptr - 1; i >= 0; --i)
//     {
//         if(visited_idcs.count(arr[i].second - 1) == 0 && visited_idcs.count(arr[i].second + 1) == 0)
//         {
//             maxSumRcs = subsetSumRecursive(arr, i, visited_idcs);
//             maxSumItr += maxSumRcs;
//             maxSum = max(maxSumItr, maxSum);
            
//             maxSumItr = resetMaxSum;
//             visited_idcs = reset_cache;
//         }
//     }
//     return maxSum;
// }

struct recursive_variables
{
    int max_sum;
    int curr_ptr;
    
    set<int> visited_idcs;
}

int subsetSumRcs(recursive_variables rcs_cache, stack<recursive_variables>& recursive_stack)
{
    // maxSumItr += maxSumRcs;
    // maxSum = max(maxSumItr, maxSum);
    
    // maxSumItr = resetMaxSum;
    // visited_idcs = reset_cache; 
    
    // if (i - 1 > 0)
    //     recursive_stack.push(i - 1); 
    
    return 0;
}

int subsetSumRecursive(const vector<pair<int, int>>& arr, recursive_variables rcs_cache, stack<recursive_variables>& recursive_stack)
{
    // visited_idcs.insert(arr[ptr].second);
    // set<int> reset_cache = visited_idcs;    
    
    // int maxSum{arr[ptr].first}; 
    // int resetMaxSum{maxSum};
    // int maxSumRcs{}, maxSumItr{maxSum};
    
    rcs_cache.max_sum = arr[rcs_cache.curr_ptr].first;
    rcs_cache.visited_idcs.insert(arr[rcs_cache.curr_ptr].second);
    
    recursive_stack.push(rcs_cache);
    
    while(!recursive_stack.empty())
    {
        auto rCache = recursive_stack.top();
        recursive_stack.pop(); 
        
        auto maxSum = subsetSumRcs(rCache, recursive_stack);
    }

    return maxSum;
}

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    vector<pair<int, int>> arr_idx_pair{};
    for(auto i = 0; i < arr.size(); ++i)
    {
        if(arr[i] > 0)
        {
            arr_idx_pair.emplace_back(make_pair(arr[i], i));   
        }
    }
    if(arr_idx_pair.size() == 0) 
        return 0;
        
    // unordered_map<int, vector<int>> cache{};
    set<int> visited_idcs{};
    
    // stack<int> recursive_stack{};
    stack<recursive_variables> recursive_stack{};
    
    sort(arr_idx_pair.begin(), arr_idx_pair.end());
    int ptr_end = arr_idx_pair.size() - 1;    
    
    int maxSubset{0}, maxSubsetTmp{0};
    for(int ptr = ptr_end; ptr >= 0; --ptr)
    {
        recursive_variables init{.max_sum = 0, .curr_ptr = ptr_end, .visited_idcs = visited_idcs};
        
        maxSubsetTmp = subsetSumRecursive(arr_idx_pair, init, recursive_stack);
        maxSubset = max(maxSubset, maxSubsetTmp);
    }
    return maxSubset;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = maxSubsetSum(arr);

    fout << res << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
