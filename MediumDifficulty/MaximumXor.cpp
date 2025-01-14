#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maxXor function below.

struct BitTrie
{
    int value{0};
    BitTrie *child[2] = {nullptr, nullptr};
};

vector<int> maxXor(vector<int> arr, vector<int> queries) {
    // solve here
    vector<int> max_xor(queries.size(), -1);
    
    auto insert = [&](BitTrie* root, int el)
    {
        BitTrie* itr = root;
        for(int i{31}; i > -1; --i)
        {
            bool bit = el & (1 << i);
            if(itr->child[bit] == nullptr)
            {
                itr->child[bit] = new BitTrie;
            }
            
            itr = itr->child[bit];
        }
        
        itr->value = el;
    };
    
    BitTrie* root = new BitTrie;
    
    for(auto& el : arr)
    {
        insert(root, el);
    }
    
    int j{0};
    for(auto& el : queries)
    {
        BitTrie* itr = root;

        for(int i{31}; i > -1; --i)
        {
            bool bit = (el & (1 << i));
            
            if(itr->child[1 - bit] != nullptr)
            {
                itr = itr->child[1 - bit];
            }
            else 
            {
                itr = itr->child[bit];
            }
        }
        
        max_xor[j] = itr->value ^ el;
        ++j;
    }
    
    return max_xor;
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

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(m);

    for (int i = 0; i < m; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<int> result = maxXor(arr, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
