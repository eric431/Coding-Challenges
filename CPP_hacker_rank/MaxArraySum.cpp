#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int find_max_sum(vector<pair<int, int>>& even, vector<pair<int, int>>& odd)
{
    int i{0};   
    int j{0};
    set<int> max_sums{};
    map<pair<int, int>, int> memo{};
    while(true)
    {
        if(i >= even.size() || j >= odd.size()) break;

        if(odd[j].second < even[i].second)
        {
            if(i == 0 && j == 0)
            {
                memo[odd[j]] = odd[j].first;
                max_sums.insert(memo[odd[j]]);
                ++j;
            }

            for(; odd[j].second < even[i].second && j < odd.size(); ++j)
            {
                memo[odd[j]] = odd[j].first;
                if((j == 0 && i == 1) && (odd[j].second - 1 == even[i - 1].second)) ;
                else if(i >= 1 && (even[i - 1].second + 1 == odd[j].second && memo[even[i - 1]] == *(max_sums.rbegin())))
                {
                    int m{memo[odd[j - 1]]};
                    if (i >= 2 ) m = max(m, memo[even[i - 2]]);
                    
                    memo[odd[j]] += max(*(++max_sums.rbegin()), m);
                }
                else
                {
                    memo[odd[j]] += *(max_sums.rbegin());
                }
                max_sums.insert(memo[odd[j]]);
            }
        }
        else if(even[i].second < odd[j].second)
        {
            if(i == 0 && j == 0)
            {
                memo[even[i]] = even[i].first;
                max_sums.insert(memo[even[i]]);
                ++i;
            }

            for(; even[i].second < odd[j].second && i < even.size(); ++i)
            {
                memo[even[i]] = even[i].first;
                if(i == 0 && j == 1 && even[i].second - 1 == odd[j - 1].second) ;
                else if(j >= 1 && (odd[j - 1].second + 1 == even[i].second && *(max_sums.rbegin()) == memo[odd[j - 1]]))
                {
                    int m{memo[even[i - 1]]};
                    if (j >= 2 ) m = max(m, memo[odd[j - 2]]);
                    
                    memo[even[i]] += max(*(++max_sums.rbegin()), m);
                }
                else
                {
                    memo[even[i]] += *(max_sums.rbegin());
                }
                max_sums.insert(memo[even[i]]);
            }
        }
    }

    if(j == odd.size())
    {
        --j;
        for(; i < even.size(); ++i)
        {
            memo[even[i]] = even[i].first;
            if(j >= 1 && (odd[j].second + 1 == even[i].second && *(max_sums.rbegin()) == memo[odd[j]]))
            {
                int m = max(memo[even[i - 1]], memo[odd[j - 1]]);
                memo[even[i]] += max(*(++max_sums.rbegin()), m);
            }
            else
            {
                memo[even[i]] += *(max_sums.rbegin());
            }
            max_sums.insert(memo[even[i]]);
        }
    }
    else if(i == even.size())
    {
        --i;
        for(; j < odd.size(); ++j)
        {
            memo[odd[j]] = odd[j].first;
            if(i >= 1 && (odd[j].second == even[i].second + 1 && *(max_sums.rbegin()) == memo[even[i]]))
            {
                int m = max(memo[even[i - 1]], memo[odd[j - 1]]);
                memo[odd[j]] += max(*(++max_sums.rbegin()), m);
            }
            else
            {
                memo[odd[j]] += *(max_sums.rbegin());
            }
            max_sums.insert(memo[odd[j]]);
        }
    }

    return *(max_sums.rbegin());
}

// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    int n = arr.size();
    vector<pair<int, int>> arr_idx_v{};
    for(auto i{0}; i < n; ++i)
    {
        if(arr[i] > 0)
        {
            arr_idx_v.emplace_back(make_pair(arr[i], i));
        }
    }

    vector<pair<int, int>> even_idx_v{}, odd_idx_v{};
    for(auto j{0}; j < arr_idx_v.size(); ++j)
    {
        if(arr_idx_v[j].second % 2 == 0)
        {
            even_idx_v.emplace_back(arr_idx_v[j]);
        }
        else
        {
            odd_idx_v.emplace_back(arr_idx_v[j]);
        }
    }

    return find_max_sum(even_idx_v, odd_idx_v);
}

int main()
{
    ofstream fout("output.txt");

    ifstream fin("input.txt");

    string num;
    getline(fin, num);
    int n = stoi(num);

    // fin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(fin, arr_temp_temp);

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