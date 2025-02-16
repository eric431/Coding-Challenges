#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'solve' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER_ARRAY queries
 */

vector<int> solve(vector<int> arr, vector<int> queries) {
    auto next_largest_element = [&](const vector<int>& arr)
    {
        stack<pair<int, int>> nle_stack{};
        
        // intialise the next largest element with a sentinel value of -1
        const int sentinel_val{-1};
        vector<int> next_largest_element(arr.size(), sentinel_val);
        for(auto i{0}; i < arr.size(); ++i)
        {
            // while the stack is not empty and the element is greater than the top element of the stack
            while(!nle_stack.empty() && arr[i] > nle_stack.top().first)
            {
                // store the top of the stack in a variable called tmp
                auto tmp = nle_stack.top();
                nle_stack.pop();
                
                // get the index of the top of the stack and update the next smallest element vector with the window size of the current smallest element
                next_largest_element[tmp.second] = i - tmp.second;
            }
            nle_stack.push(make_pair(arr[i], i));
        }
        
        while(!nle_stack.empty())
        {
            auto tmp = nle_stack.top();
            nle_stack.pop();
            
            next_largest_element[tmp.second] = arr.size() - tmp.second;
        }
        return next_largest_element;
    };
    
    auto previous_largest_element = [&](const vector<int>& arr)
    {
        stack<pair<int, int>> ple_stack{};
        
        // initialise the previous smallest element with a sentinel value of -1
        int sentinel_val{-1};
        vector<int> prev_largest_element(arr.size(), sentinel_val);
        
        for(int i = arr.size() - 1; i > -1; --i)
        {
            // while the stack is not empty and the element is greater than the top element of the stack
            while(!ple_stack.empty() && arr[i] > ple_stack.top().first)
            {
                // store the top of the stack in a variable called tmp
                auto tmp = ple_stack.top();
                ple_stack.pop();
                
                // get the index of the top of the stack and update the previous smallest element vector with the window size of the current smallest element
                prev_largest_element[tmp.second] = tmp.second - i - 1;
            }
            ple_stack.push(make_pair(arr[i], i));
        }
        
        while(!ple_stack.empty())
        {
            auto tmp = ple_stack.top();
            ple_stack.pop();
            
            prev_largest_element[tmp.second] = tmp.second;
        }
        return prev_largest_element;
    }; 
    
    auto nle = next_largest_element(arr);
    auto ple = previous_largest_element(arr);
    
    // create arr of window sizes
   vector<int> k(arr.size());
   for(auto i{0}; i < k.size(); ++i) k[i] = nle[i] + ple[i];
   
   vector<int> min_max(k.size(), -1);
   for(auto i{0}; i < min_max.size(); ++i)
        min_max[k[i] - 1] = max(min_max[k[i] - 1], arr[i]);
        
    for(int i = min_max.size() - 1; i > -1; --i)
    {
        if(min_max[i] == -1) min_max[i] = min_max[i + 1];
        else if(i < min_max.size() - 1) min_max[i] = min(min_max[i], min_max[i + 1]);
    }
    
    vector<int> result {};
    for(auto q : queries)
        result.push_back(min_max[q - 1]);

    return result;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = solve(arr, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
